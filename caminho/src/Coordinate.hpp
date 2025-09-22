#ifndef Coordinate_hpp
#define Coordinate_hpp

#include <memory>
#include <iostream>

class Coordinate
{
    protected:
        int x;
        int y;
        std::shared_ptr<Coordinate> parent = 0;
    public:
        Coordinate(int ax, int ay, std::shared_ptr<Coordinate> aParent = nullptr);

        bool same (std::shared_ptr<Coordinate> rhs);
        std::string toString();
        std::string extractPath();

        int getX();
        int getY();
        std::shared_ptr<Coordinate> getParent();
        int getCost();

};

#endif