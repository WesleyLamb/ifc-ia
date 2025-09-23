#include "Maze.hpp"

Maze::Maze(std::shared_ptr<std::vector<std::vector<char>>> aMaze)
{
    this->maze = aMaze;
}

std::string Maze::showPath(std::shared_ptr<Coordinate> pos)
{
    std::shared_ptr<std::list<std::shared_ptr<Coordinate>>> path = std::make_shared<std::list<std::shared_ptr<Coordinate>>>();
    while (pos != nullptr) {
        path->push_back(pos);
        pos = pos->getParent();
    }

    std::unique_ptr<std::stack<char>> strPath = std::make_unique<std::stack<char>>();

    for (auto it = path->begin(); it != path->end(); ++it) {
        strPath->push(this->maze->at(it->get()->getY()).at(it->get()->getX()));
    }

    std::string result = "";
    while (strPath->size() > 0) {
        auto str = strPath->top();
        strPath->pop();
        if ((result.find(str) == std::string::npos) && (str != ' ')) {
            if (result.length() > 0) {
                result += " -> ";
            }
            result += str;
        }
    }

    return result;
}

void Maze::bfs(std::shared_ptr<Coordinate> startPos, std::shared_ptr<Coordinate> endPos)
{
    bool found = false;
    auto visited = std::make_unique<std::vector<std::vector<char>>>();
    auto queue = std::make_unique<std::queue<std::shared_ptr<Coordinate>>>();
    std::shared_ptr<Coordinate> currentPos = nullptr;

    int x, y, accesses = 0;

    for (int i = 0; i < this->maze->size(); i++) {
        visited->push_back(this->maze->at(i));
    }

    queue->push(startPos);


    while (queue->size() > 0) {
        currentPos = queue->front();
        queue->pop();
        visited->at(currentPos->getY()).at(currentPos->getX()) = '-';

        if (currentPos->same(endPos)) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    x = 0;
                    y = -1;
                    break;

                case 1:
                    x = -1;
                    y = 0;
                    break;

                case 2:
                    x = 1;
                    y = 0;
                    break;

                default:
                    x = 0;
                    y = 1;
                    break;
            }

            if ((visited->at(currentPos->getY() + y).at(currentPos->getX() + x) != '-') && (visited->at(currentPos->getY() + y).at(currentPos->getX() + x) != '|')) {
                queue->push(std::make_shared<Coordinate>(currentPos->getX() + x, currentPos->getY() + y, currentPos));
                accesses++;
            }
        }
    }

    if (found) {
        auto helper = currentPos;
        while (helper != nullptr) {
            visited->at(helper->getY()).at(helper->getX()) = '*';
            helper = helper->getParent();
        }
        for (int i = 0; i < visited->size(); i++) {
            for (int j = 0; j < visited->at(i).size(); j++) {
                std::cout << visited->at(i).at(j);
            }
            std::cout << '\n';
        }

        std::cout << "Custo: " << std::to_string(currentPos->getCost()) << " acessos: " <<  std::to_string(accesses) << ", caminho: " << this->showPath(currentPos) << std::endl;
    } else {
        std::cout << "Não encontrado caminho entre " << startPos->toString() << " e " << endPos->toString() << std::endl;
    }
}

void Maze::dfs(std::shared_ptr<Coordinate> startPos, std::shared_ptr<Coordinate> endPos)
{
    bool found = false;
    auto visited = std::make_unique<std::vector<std::vector<char>>>();
    auto stack = std::make_unique<std::stack<std::shared_ptr<Coordinate>>>();
    std::shared_ptr<Coordinate> currentPos = nullptr;

    int x, y, accesses = 0;

    for (int i = 0; i < this->maze->size(); i++) {
        visited->push_back(this->maze->at(i));
    }

    stack->push(startPos);

    while (stack->size() > 0) {
        currentPos = stack->top();
        stack->pop();
        visited->at(currentPos->getY()).at(currentPos->getX()) = '-';

        if (currentPos->same(endPos)) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    x = 0;
                    y = -1;
                    break;

                case 1:
                    x = -1;
                    y = 0;
                    break;

                case 2:
                    x = 1;
                    y = 0;
                    break;

                default:
                    x = 0;
                    y = 1;
                    break;
            }

            if ((visited->at(currentPos->getY() + y).at(currentPos->getX() + x) != '-') && (visited->at(currentPos->getY() + y).at(currentPos->getX() + x) != '|')) {
                stack->push(std::make_shared<Coordinate>(currentPos->getX() + x, currentPos->getY() + y, currentPos));
                accesses++;
            }
        }
    }

    if (found) {
        auto helper = currentPos;
        while (helper != nullptr) {
            visited->at(helper->getY()).at(helper->getX()) = '*';
            helper = helper->getParent();
        }
        for (int i = 0; i < visited->size(); i++) {
            for (int j = 0; j < visited->at(i).size(); j++) {
                std::cout << visited->at(i).at(j);
            }
            std::cout << '\n';
        }

        std::cout << "Custo: " << std::to_string(currentPos->getCost()) << " acessos: " <<  std::to_string(accesses) << ", caminho: " << this->showPath(currentPos) << std::endl;
    } else {
        std::cout << "Não encontrado caminho entre " << startPos->toString() << " e " << endPos->toString() << std::endl;
    }
}

void Maze::greedy(std::shared_ptr<Coordinate> startPos, std::shared_ptr<Coordinate> endPos)
{
    bool found = false;
    auto visited = std::make_shared<std::vector<std::vector<char>>>();
    auto list = std::make_unique<std::list<std::shared_ptr<Coordinate>>>();
    int x, y, bestHeuristic, accesses = 0;
    std::shared_ptr<Coordinate> currentPos = nullptr;

    for (int i = 0; i < this->maze->size(); i++) {
        visited->push_back(this->maze->at(i));
    }

    list->push_front(startPos);

    while (list->size() > 0) {
        currentPos = list->front();
        list->pop_front();
        visited->at(currentPos->getY()).at(currentPos->getX()) = '-';
        bestHeuristic = heuristic(currentPos, endPos);

        if ((currentPos->same(endPos))) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    x = 0;
                    y = -1;
                    break;

                case 1:
                    x = -1;
                    y = 0;
                    break;

                case 2:
                    x = 1;
                    y = 0;
                    break;

                default:
                    x = 0;
                    y = 1;
                    break;
            }

            if ((visited->at(currentPos->getY() + y).at(currentPos->getX() + x) != '-') && (visited->at(currentPos->getY() + y).at(currentPos->getX() + x) != '|') ) {
                auto newPos = std::make_shared<Coordinate>(currentPos->getX() + x, currentPos->getY() + y, currentPos);
                auto it = list->begin();
                for (it = list->begin(); it != list->end(); ++it) {
                    if (heuristic(*it, endPos) > heuristic(newPos, endPos)) {
                        break;
                    }
                }
                list->insert(it, newPos);
                accesses++;
            }
        }
    }

    if (found) {
        auto helper = currentPos;
        while (helper != nullptr) {
            visited->at(helper->getY()).at(helper->getX()) = '*';
            helper = helper->getParent();
        }
        for (int i = 0; i < visited->size(); i++) {
            for (int j = 0; j < visited->at(i).size(); j++) {
                std::cout << visited->at(i).at(j);
            }
            std::cout << '\n';

        }
        std::cout << "Custo: " << std::to_string(currentPos->getCost()) << " acessos: " <<  std::to_string(accesses) << ", caminho: " << this->showPath(currentPos) << std::endl;
    } else {
        std::cout << "Não encontrado caminho entre " << startPos->toString() << " e " << endPos->toString() << std::endl;
    }
}

void Maze::aStar(std::shared_ptr<Coordinate> startPos, std::shared_ptr<Coordinate> endPos)
{
    bool found = false;
    auto visited = std::make_shared<std::vector<std::vector<char>>>();
    auto list = std::make_unique<std::list<std::shared_ptr<Coordinate>>>();
    int x, y, bestHeuristic, accesses = 0;
    std::shared_ptr<Coordinate> currentPos = nullptr;

    for (int i = 0; i < this->maze->size(); i++) {
        visited->push_back(this->maze->at(i));
    }

    list->push_front(startPos);

    while (list->size() > 0) {
        currentPos = list->front();
        list->pop_front();
        visited->at(currentPos->getY()).at(currentPos->getX()) = '-';
        bestHeuristic = heuristic(currentPos, endPos);

        if ((currentPos->same(endPos))) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    x = 0;
                    y = -1;
                    break;

                case 1:
                    x = -1;
                    y = 0;
                    break;

                case 2:
                    x = 1;
                    y = 0;
                    break;

                default:
                    x = 0;
                    y = 1;
                    break;
            }

            if ((visited->at(currentPos->getY() + y).at(currentPos->getX() + x) != '-') && (visited->at(currentPos->getY() + y).at(currentPos->getX() + x) != '|') ) {
                auto newPos = std::make_shared<Coordinate>(currentPos->getX() + x, currentPos->getY() + y, currentPos);
                auto it = list->begin();
                for (it = list->begin(); it != list->end(); ++it) {
                    if ((heuristic(*it, endPos) + (*it)->getCost()) > (heuristic(newPos, endPos) + newPos->getCost())) {
                        break;
                    }
                }
                list->insert(it, newPos);
                accesses++;
            }
        }
    }

    if (found) {
        auto helper = currentPos;
        while (helper != nullptr) {
            visited->at(helper->getY()).at(helper->getX()) = '*';
            helper = helper->getParent();
        }
        for (int i = 0; i < visited->size(); i++) {
            for (int j = 0; j < visited->at(i).size(); j++) {
                std::cout << visited->at(i).at(j);
            }
            std::cout << '\n';

        }
        std::cout << "Custo: " << std::to_string(currentPos->getCost()) << " acessos: " <<  std::to_string(accesses) << ", caminho: " << this->showPath(currentPos) << std::endl;
    } else {
        std::cout << "Não encontrado caminho entre " << startPos->toString() << " e " << endPos->toString() << std::endl;
    }
}