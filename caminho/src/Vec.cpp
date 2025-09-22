#include "Vec.hpp"

Vec::Vec(int ax, int ay, std::shared_ptr<Vec> aParent = NULL)
{
    this->x = ax;
    this->y = ay;
    this->parent = aParent;
}