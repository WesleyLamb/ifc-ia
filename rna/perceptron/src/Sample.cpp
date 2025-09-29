#include "Sample.hpp"

Sample::Sample(int ax1, int ax2, int aResult)
{
    this->x1 = ax1;
    this->x2 = ax2;
    this->result = aResult;
}

int Sample::getx1()
{
    return this->x1;
}

int Sample::getx2()
{
    return this->x2;
}

int Sample::getResult()
{
    return this->result;
}
