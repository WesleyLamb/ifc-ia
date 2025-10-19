#ifndef Adaline_hpp
#define Adaline_hpp

#define BIAS_COUNT 2

#include <memory>
#include <list>
#include <vector>
#include "Sample.hpp"
#include <cstdlib>
#include <ctime>

class Adaline
{
    private:
        double learningRate;
        std::vector<double> weights;

        void recalculate(std::shared_ptr<Sample> sample);
        double getRandom();
        double aggregate(std::shared_ptr<Sample> sample);
        double error(double yHat, double y);
        double activation(double input);

        int threshold(int y);
    public:
        Adaline(double aLearningRate);

        void train(std::shared_ptr<std::list<std::shared_ptr<Sample>>> samples, int epochCount);
        int think(std::shared_ptr<Sample> sample);
        int predict(std::shared_ptr<Sample> sample);
};

#endif