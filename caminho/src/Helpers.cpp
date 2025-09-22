#include "Helpers.hpp"

int heuristic(std::shared_ptr<Coordinate> currentPos, std::shared_ptr<Coordinate> endPos)
{
    return abs((currentPos->getX() - endPos->getX()) + (currentPos->getY() - endPos->getY()));
};