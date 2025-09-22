#ifndef Helpers_hpp
#define Helpers_hpp

#include <cmath>
#include <memory>
#include "Coordinate.hpp"

int heuristic(std::shared_ptr<Coordinate> currentPos, std::shared_ptr<Coordinate> endPos);

#endif