#ifndef Maze_hpp
#define Maze_hpp

#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <list>
#include "Helpers.hpp"
#include "Coordinate.hpp"

class Maze
{
    private:
        std::shared_ptr<std::vector<std::vector<char>>> maze;
        // int heuristic(int x, int y, int xf, int yf);
    public:
        Maze(std::shared_ptr<std::vector<std::vector<char>>> aMaze);

        std::string showPath(std::shared_ptr<Coordinate> pos);
        void bfs(std::shared_ptr<Coordinate> startPos, std::shared_ptr<Coordinate> endPos);
        void dfs(std::shared_ptr<Coordinate> startPos, std::shared_ptr<Coordinate> endPos);
        void greedy(std::shared_ptr<Coordinate> startPos, std::shared_ptr<Coordinate> endPos);
        void aStar(std::shared_ptr<Coordinate> startPos, std::shared_ptr<Coordinate> endPos);

};

#endif