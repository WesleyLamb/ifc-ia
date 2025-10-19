#include "Adaline.hpp"
#include <iostream>
#include <math.h>
#include <numeric>

void Adaline::recalculate(std::shared_ptr<Sample> sample)
{
    double error = this->error(sample->getResult(), this->activation(this->aggregate(sample)));

    for (int i = 0; i < BIAS_COUNT + 1; i++) {
        this->weights.at(i) = this->weights.at(i) + (this->learningRate * error * sample->getx(i));
    }
}

double Adaline::getRandom()
{
    double random = (rand());
    random = (random / RAND_MAX) - 0.5;
    return random;
}

double Adaline::aggregate(std::shared_ptr<Sample> sample)
{
    double y = std::inner_product(sample->x.begin(), sample->x.end(), this->weights.begin(), 0.0);
    return y;
    // double y = 1;
    // for (int i = 0; i < this->weights.size(); i++) {
    //     y += sample->getx(i) * this->weights.at(i);
    // }

    // return y;
}

double Adaline::error(double yHat, double y)
{
    return yHat - y;
}

double Adaline::activation(double input)
{
    return input;
}

int Adaline::threshold(int y)
{
    if (y >= 0.0) {
        return 1;
    } else {
        return -1;
    }
}

Adaline::Adaline(double aLearningRate)
{
    srand(time(0));
    this->learningRate = aLearningRate;

    this->weights.push_back(-0.5);
    this->weights.push_back(0);
    this->weights.push_back(0.5);
    // this->bias = this->getRandom();
    // for (int i = 0; i < BIAS_COUNT; i++) {
    //     this->weights.push_back(this->getRandom());
    // }
}

void Adaline::train(std::shared_ptr<std::list<std::shared_ptr<Sample>>> samples, int epochCount)
{
    for (int i = 0; i < epochCount; i++) {
        for (auto sample = samples->begin(); sample != samples->end(); ++sample) {
            this->think((*sample));
        }
    }
}

int Adaline::think(std::shared_ptr<Sample> sample)
{
    int result = this->threshold(this->aggregate(sample));
    this->recalculate(sample);

    return result;
}

int Adaline::predict(std::shared_ptr<Sample> sample)
{
    return this->threshold(this->aggregate(sample));
}
