#include "Coordinate.hpp"

bool Coordinate::same(std::shared_ptr<Coordinate> rhs)
{
    return (this->getX() == rhs->getX()) && (this->getY() == rhs->getY());
}

Coordinate::Coordinate(int ax, int ay, std::shared_ptr<Coordinate> aParent)
{
    this->x = ax;
    this->y = ay;
    this->parent = aParent;
}

std::string Coordinate::toString()
{
    return "x: " + std::to_string(this->getX()) + " y: " + std::to_string(this->getY());
}

std::string Coordinate::extractPath()
{
    return std::string();
}

int Coordinate::getX()
{
    return this->x;
}

int Coordinate::getY()
{
    return this->y;
}

std::shared_ptr<Coordinate> Coordinate::getParent()
{
    return this->parent;
}

int Coordinate::getCost()
{
    if (this->parent == nullptr)
        return 0;
    return this->parent->getCost() + 1;
}
