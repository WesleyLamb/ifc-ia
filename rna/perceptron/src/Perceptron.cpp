#include "Perceptron.hpp"
#include <iostream>

void Perceptron::recalculate(std::shared_ptr<Sample> sample)
{
    std::cout << "reaprendendo pois para X1 = " << std::to_string(sample->getx(0)) << " e X2 = " << std::to_string(sample->getx(1)) << " calculei " << std::to_string(this->think(sample->getx(0), sample->getx(1))) << std::endl;
    for (int i = 0; i < BIAS_COUNT; i++) {
        this->weights.at(i) = this->weights.at(i) + (this->learningRate * (sample->getResult() - this->think(sample->getx(0), sample->getx(1))) * sample->getx(i));
    }
    this->bias = this->bias + (this->learningRate * (sample->getResult() - this->think(sample->getx(0), sample->getx(1))));
}

double Perceptron::getRandom()
{
    double random = (rand() % 101);
    random = random / 100;
    return random;
}

Perceptron::Perceptron(double aLearningRate)
{
    srand(time(0));
    this->learningRate = aLearningRate;

    for (int i = 0; i < BIAS_COUNT; i++) {
        this->weights.push_back(this->getRandom());
    }
    this->bias = this->getRandom();
}

void Perceptron::train(std::shared_ptr<std::list<std::shared_ptr<Sample>>> samples, int epochCount)
{
    for (int i = 0; i < epochCount; i++) {
        for (auto sample = samples->begin(); sample != samples->end(); ++sample) {
            if (this->think((*sample)->getx(0), (*sample)->getx(1)) != (*sample)->getResult()) {
                this->recalculate(*sample);
            }
        }
    }
}

int Perceptron::think(int ax1, int ax2)
{
    double y = (this->weights.at(0) * ax1) + (this->weights.at(1) * ax2) + this->bias;
    int result;
    if (y >= 1) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
