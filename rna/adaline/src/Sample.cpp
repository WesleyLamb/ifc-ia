#include "Sample.hpp"

Sample::Sample(int ax1, int ax2, int aResult)
{
    this->x.push_back(ax1);
    this->x.push_back(ax2);

    this->result = aResult;
}

Sample::Sample(int ax1, int ax2)
{
    this->x.push_back(ax1);
    this->x.push_back(ax2);
}

int Sample::getx(int i)
{
    return this->x.at(i);
}

int Sample::getResult()
{
    return this->result;
}
