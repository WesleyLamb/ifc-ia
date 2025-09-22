#ifndef Vec_hpp
#define Vec_hpp

#include <memory>
#include "Helpers.hpp"

class Vec
{
    public:
        Vec(int ax, int ay, std::shared_ptr<Vec> aParent);

        int x;
        int y;
        std::shared_ptr<Vec> parent = 0;
};

#endif