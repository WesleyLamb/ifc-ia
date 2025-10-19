#ifndef Sample_hpp
#define Sample_hpp

#include <vector>

class Sample
{
    private:
    int result;
    public:
        std::vector<int> x;
        Sample(int ax1, int ax2, int aResult);
        Sample(int ax1, int ax2);

        int getx(int i);
        int getResult();
};

#endif