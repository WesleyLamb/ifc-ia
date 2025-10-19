#include <iostream>
#include <memory>
#include <list>

#include "src/Perceptron.hpp"
#include "src/Sample.hpp"

int main()
{
    {
        std::cout << "Tabela and" << std::endl;
        auto amostras = std::make_shared<std::list<std::shared_ptr<Sample>>>();
        amostras->push_back(std::make_shared<Sample>(0, 0, 0));
        amostras->push_back(std::make_shared<Sample>(0, 1, 0));
        amostras->push_back(std::make_shared<Sample>(1, 0, 0));
        amostras->push_back(std::make_shared<Sample>(1, 1, 1));

        auto perceptron = std::make_shared<Perceptron>(0.1);
        perceptron->train(amostras, 10);

        std::cout << std::to_string(perceptron->think(0, 0)) << std::endl;
        std::cout << std::to_string(perceptron->think(0, 1)) << std::endl;
        std::cout << std::to_string(perceptron->think(1, 0)) << std::endl;
        std::cout << std::to_string(perceptron->think(1, 1)) << std::endl;
    }

    {
        std::cout << "Tabela or" << std::endl;
        auto amostras = std::make_shared<std::list<std::shared_ptr<Sample>>>();
        amostras->push_back(std::make_shared<Sample>(0, 0, 0));
        amostras->push_back(std::make_shared<Sample>(0, 1, 1));
        amostras->push_back(std::make_shared<Sample>(1, 0, 1));
        amostras->push_back(std::make_shared<Sample>(1, 1, 1));

        auto perceptron = std::make_shared<Perceptron>(0.1);
        perceptron->train(amostras, 10);
        std::cout << std::to_string(perceptron->think(0, 0)) << std::endl;
        std::cout << std::to_string(perceptron->think(0, 1)) << std::endl;
        std::cout << std::to_string(perceptron->think(1, 0)) << std::endl;
        std::cout << std::to_string(perceptron->think(1, 1)) << std::endl;
    }

    {
        std::cout << "Tabela xor" << std::endl;
        auto amostras = std::make_shared<std::list<std::shared_ptr<Sample>>>();
        amostras->push_back(std::make_shared<Sample>(0, 0, 0));
        amostras->push_back(std::make_shared<Sample>(0, 1, 1));
        amostras->push_back(std::make_shared<Sample>(1, 0, 1));
        amostras->push_back(std::make_shared<Sample>(1, 1, 0));

        auto perceptron = std::make_shared<Perceptron>(0.1);
        perceptron->train(amostras, 10);

        std::cout << std::to_string(perceptron->think(0, 0)) << std::endl;
        std::cout << std::to_string(perceptron->think(0, 1)) << std::endl;
        std::cout << std::to_string(perceptron->think(1, 0)) << std::endl;
        std::cout << std::to_string(perceptron->think(1, 1)) << std::endl;
    }

    return 0;
}