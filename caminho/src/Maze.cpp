#include "Maze.hpp"

Maze::Maze(std::shared_ptr<std::vector<std::vector<char>>> aMaze)
{
    this->maze = aMaze;
}

void Maze::bfs(int xi, int yi, int xf, int yf)
{
    bool found = false;
    auto visited = std::make_shared<std::vector<std::vector<char>>>();
    auto queue = std::make_unique<std::queue<Vec>>();
    auto dest = std::make_unique<Vec>(xf, yf);
    int x, y;

    for (int i = 0; i < this->maze->size(); i++) {
        visited->push_back(this->maze->at(i));
    }

    queue->push({xi, yi});
    visited->at(yi).at(xi) = '*';

    while (queue->size() > 0) {
        auto v = queue->front();
        queue->pop();
        visited->at(v.y).at(v.x) = '*';

        if ((v.x == dest->x) && (v.y == dest->y)) {
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

            if ((visited->at(v.y + y).at(v.x + x) != '*') && (visited->at(v.y + y).at(v.x + x) != '|')) {
                queue->push({v.x + x, v.y + y});
            }
        }
    }

    if (found) {
        for (int i = 0; i < visited->size(); i++) {
            for (int j = 0; j < visited->at(i).size(); j++) {
                std::cout << visited->at(i).at(j);
            }
            std::cout << '\n';
        }
    } else {
        std::cout << "Não encontrado caminho entre xi: " << xi << " yi: " << yi << " e xf: " << xf << " yf: " << yf << std::endl;
    }
}

void Maze::dfs(int xi, int yi, int xf, int yf)
{
    bool found = false;
    auto visited = std::make_shared<std::vector<std::vector<char>>>();
    auto stack = std::make_unique<std::stack<Vec>>();
    auto dest = std::make_unique<Vec>(xf, yf);
    int x, y,dist;

    for (int i = 0; i < this->maze->size(); i++) {
        visited->push_back(this->maze->at(i));
    }

    stack->push({xi, yi});
    visited->at(yi).at(xi) = '*';

    while (stack->size() > 0) {
        auto v = stack->top();
        stack->pop();
        visited->at(v.y).at(v.x) = '*';
        dist = this->heuristic(v.x, v.y, xf, yf);

        if ((v.x == dest->x) && (v.y == dest->y)) {
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

            if ((visited->at(v.y + y).at(v.x + x) != '*') && (visited->at(v.y + y).at(v.x + x) != '|') && (heuristic(v.x + x, v.y + y, xf, yf) < dist)) {
                stack->push({v.x + x, v.y + y});
            }
        }
    }

    if (found) {
        for (int i = 0; i < visited->size(); i++) {
            for (int j = 0; j < visited->at(i).size(); j++) {
                std::cout << visited->at(i).at(j);
            }
            std::cout << '\n';
        }
    } else {
        std::cout << "Não encontrado caminho entre xi: " << xi << " yi: " << yi << " e xf: " << xf << " yf: " << yf << std::endl;
    }
}

void Maze::greedy(int xi, int yi, int xf, int yf)
{
    bool found = false;
    auto visited = std::make_shared<std::vector<std::vector<char>>>();
    auto stack = std::make_unique<std::stack<Vec>>();
    auto dest = std::make_unique<Vec>(xf, yf);
    int x, y;

    for (int i = 0; i < this->maze->size(); i++) {
        visited->push_back(this->maze->at(i));
    }

    stack->push({xi, yi});
    visited->at(yi).at(xi) = '*';

    while (stack->size() > 0) {
        auto v = stack->top();
        stack->pop();
        visited->at(v.y).at(v.x) = '*';

        if ((v.x == dest->x) && (v.y == dest->y)) {
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

            if ((visited->at(v.y + y).at(v.x + x) != '*') && (visited->at(v.y + y).at(v.x + x) != '|')) {
                stack->push({v.x + x, v.y + y});
            }
        }
    }

    if (found) {
        for (int i = 0; i < visited->size(); i++) {
            for (int j = 0; j < visited->at(i).size(); j++) {
                std::cout << visited->at(i).at(j);
            }
            std::cout << '\n';
        }
    } else {
        std::cout << "Não encontrado caminho entre xi: " << xi << " yi: " << yi << " e xf: " << xf << " yf: " << yf << std::endl;
    }
}

void Maze::aStar(int xi, int yi, int xf, int yf)
{
bool found = false;
    auto visited = std::make_shared<std::vector<std::vector<char>>>();
    auto list = std::make_unique<std::list<Vec>>();
    auto dest = std::make_unique<Vec>(xf, yf);
    int x, y;

    for (int i = 0; i < this->maze->size(); i++) {
        visited->push_back(this->maze->at(i));
    }

    list->push_back({xi, yi});
    visited->at(yi).at(xi) = '*';

    while (list->size() > 0) {
        auto v = list->front();
        list->pop_front();
        visited->at(v.y).at(v.x) = '*';

        if ((v.x == dest->x) && (v.y == dest->y)) {
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

            if ((visited->at(v.y + y).at(v.x + x) != '*') && (visited->at(v.y + y).at(v.x + x) != '|')) {
                auto it = list->begin();
                for (it = list->begin(); it != list->end(); ++it) {
                    if (this->heuristic(it->x, it->y, xf, yf) > this->heuristic(v.x + x, v.y + y, xf, yf)) {
                        break;
                    }
                }
                list->insert(it, {v.x + x, v.y + y});
            }
        }
    }

    if (found) {
        for (int i = 0; i < visited->size(); i++) {
            for (int j = 0; j < visited->at(i).size(); j++) {
                std::cout << visited->at(i).at(j);
            }
            std::cout << '\n';
        }
    } else {
        std::cout << "Não encontrado caminho entre xi: " << xi << " yi: " << yi << " e xf: " << xf << " yf: " << yf << std::endl;
    }
}

int Maze::heuristic(int x, int y, int xf, int yf)
{
    return abs((x - xf) + (y - yf));
}
