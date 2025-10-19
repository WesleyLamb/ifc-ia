#ifndef Sample_hpp
#define Sample_hpp

#include <vector>

class Sample
{
    private:
        std::vector<int> x;
        int result;
    public:
        Sample(int ax1, int ax2, int aResult);

        int getx(int i);
        int getResult();
};

#endif