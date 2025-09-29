#include "Perceptron.hpp"

void Perceptron::recalculate(std::shared_ptr<Sample> sample)
{
    for (int i = 0; i < BIAS_COUNT; i++) {
        this->weights.at(i) = this->weights.at(i) + (this->learningRate * (this->think(sample->getx1(), sample->getx2())));
    }
    this->bias = this->bias + (this->learningRate * (this->think(sample->getx1(), sample->getx2())));
}

double Perceptron::getRandom()
{
    double random = (rand() % 101);
    random = random / 100;
    return random;
}

Perceptron::Perceptron(int aLearningRate)
{
    srand(time(0));
    this->learningRate = aLearningRate;

    for (int i = 0; i < BIAS_COUNT; i++) {
        this->weights.push_back(this->getRandom());
    }
    this->bias = (this->getRandom());
}

void Perceptron::train(std::shared_ptr<std::list<std::shared_ptr<Sample>>> samples, int epochCount)
{
    for (int i = 0; i < epochCount; i++) {
        for (auto sample = samples->begin(); sample != samples->end(); ++sample) {
            double result = this->think((*sample)->getx1(), (*sample)->getx2());
            if (result < 0.5) {
                result = 0;
            } else {
                result = 1;
            }

            if (result != (*sample)->getResult()) {
                this->recalculate(*sample);
            }
        }
    }
}

double Perceptron::think(int ax1, int ax2)
{
    double y = (this->weights.at(0) * ax1) + (this->weights.at(1) * ax2) + this->bias;
    return y;
}
