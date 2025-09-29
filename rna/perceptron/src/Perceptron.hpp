#ifndef Perceptron_hpp
#define Perceptron_hpp

#define BIAS_COUNT 2

#include <memory>
#include <list>
#include <vector>
#include "Sample.hpp"
#include <cstdlib>
#include <ctime>

class Perceptron
{
    private:
        int learningRate;
        std::vector<double> weights;
        double bias;

        void recalculate(std::shared_ptr<Sample> sample);
        double getRandom();
    public:
        Perceptron(int aLearningRate);

        void train(std::shared_ptr<std::list<std::shared_ptr<Sample>>> samples, int epochCount);
        double think(int ax1, int ax2);
};

#endif