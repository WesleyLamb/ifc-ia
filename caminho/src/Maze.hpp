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
#include "Vec.hpp"
#include "Helpers.hpp"

class Maze
{
    private:
        std::shared_ptr<std::vector<std::vector<char>>> maze;
        int heuristic(int x, int y, int xf, int yf);
    public:
        Maze(std::shared_ptr<std::vector<std::vector<char>>> aMaze);

        void bfs(int xi, int yi, int xf, int yf);
        void dfs(int xi, int yi, int xf, int yf);
        void greedy(int xi, int yi, int xf, int yf);
        void aStar(int xi, int yi, int xf, int yf);

};

#endif