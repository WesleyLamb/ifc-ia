#include "src/Maze.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <bits/stdc++.h>

int main()
{
    auto labirintoStr = std::make_shared<std::vector<std::vector<char>>>();

    labirintoStr->push_back({'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'});
    labirintoStr->push_back({'|', 'a', 'a', 'a', '|', 'g', '|', 'k', '|', 'n', 'n', 'n', '|', 'q', 'q', 'q', '|'});
    labirintoStr->push_back({'|', '|', '|', ' ', '|', 'g', ' ', 'k', ' ', 'n', 'n', 'n', ' ', 'q', 'q', 'q', '|'});
    labirintoStr->push_back({'|', 'b', '|', 'c', ' ', 'g', '|', 'k', '|', 'n', 'n', 'n', '|', 'q', 'q', 'q', '|'});
    labirintoStr->push_back({'|', 'b', ' ', 'c', '|', ' ', '|', ' ', '|', '|', ' ', '|', '|', '|', ' ', '|', '|'});
    labirintoStr->push_back({'|', 'b', '|', 'c', '|', 'h', 'h', 'h', '|', 'o', 'o', 'o', '|', 'r', 'r', 'r', '|'});
    labirintoStr->push_back({'|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', '|', '|'});
    labirintoStr->push_back({'|', 'd', 'd', 'd', '|', 'i', '|', 'l', 'l', 'l', '|', 'p', '|', 's', 's', 's', '|'});
    labirintoStr->push_back({'|', '|', ' ', '|', '|', 'i', '|', 'l', 'l', 'l', '|', 'p', '|', '|', ' ', '|', '|'});
    labirintoStr->push_back({'|', 'e', 'e', 'e', '|', 'i', '|', 'l', 'l', 'l', '|', 'p', '|', 't', 't', 't', '|'});
    labirintoStr->push_back({'|', 'e', 'e', 'e', '|', ' ', '|', '|', ' ', '|', '|', 'p', ' ', 't', 't', 't', '|'});
    labirintoStr->push_back({'|', 'e', 'e', 'e', '|', 'j', '|', 'm', 'm', 'm', '|', 'p', '|', 't', 't', 't', '|'});
    labirintoStr->push_back({'|', '|', ' ', '|', '|', 'j', ' ', 'm', 'm', 'm', ' ', 'p', '|', '|', ' ', '|', '|'});
    labirintoStr->push_back({'|', 'f', 'f', 'f', ' ', 'j', '|', 'm', 'm', 'm', '|', 'p', '|', 'u', 'u', 'u', '|'});
    labirintoStr->push_back({'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'});

    auto labirinto = std::make_shared<Maze>(labirintoStr);

    std::cout << "BFS: " << std::endl;

    labirinto->bfs(1, 1, 15, 13);

    std::cout << "DFS: " << std::endl;

    labirinto->dfs(1, 1, 15, 13);

    std::cout << "Greedy: " << std::endl;

    labirinto->greedy(1, 1, 15, 13);

    std::cout << "A*: " << std::endl;

    labirinto->aStar(1, 1, 15, 13);

    // auto labirinto = std::make_unique<Maze>(labirintoStr);

    return 0;
}