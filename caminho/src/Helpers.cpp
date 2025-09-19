#include "Helpers.hpp"

int heuristic(int x, int y, int xf, int yf)
{
    return abs((x - xf) + (y - yf));
};