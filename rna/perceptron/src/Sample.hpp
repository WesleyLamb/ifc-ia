#ifndef Sample_hpp
#define Sample_hpp

#include <vector>

class Sample
{
    private:
        int x1;
        int x2;
        int result;
    public:
        Sample(int ax1, int ax2, int aResult);

        int getx1();
        int getx2();
        int getResult();
};

#endif