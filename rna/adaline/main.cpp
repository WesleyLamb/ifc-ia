#include <iostream>
#include <memory>
#include <list>
#include "src/Adaline.hpp"
#include "src/Sample.hpp"

int main()
{
    {
        std::cout << "Tabela and" << std::endl;
        auto amostras = std::make_shared<std::list<std::shared_ptr<Sample>>>();
        amostras->push_back(std::make_shared<Sample>(-1, -1, -1));
        amostras->push_back(std::make_shared<Sample>(-1, 1, -1));
        amostras->push_back(std::make_shared<Sample>(1, -1, -1));
        amostras->push_back(std::make_shared<Sample>(1, 1, 1));

        auto adaline = std::make_shared<Adaline>(0.1);
        adaline->train(amostras, 100);

        std::cout << std::to_string(adaline->think(std::make_shared<Sample>(-1, -1))) << std::endl;
        std::cout << std::to_string(adaline->think(std::make_shared<Sample>(-1, 1))) << std::endl;
        std::cout << std::to_string(adaline->think(std::make_shared<Sample>(1, -1))) << std::endl;
        std::cout << std::to_string(adaline->think(std::make_shared<Sample>(1, 1))) << std::endl;
    }

    // {
    //     std::cout << "Tabela or" << std::endl;
    //     auto amostras = std::make_shared<std::list<std::shared_ptr<Sample>>>();
    //     amostras->push_back(std::make_shared<Sample>(-1, -1, -1));
    //     amostras->push_back(std::make_shared<Sample>(-1, 1, 1));
    //     amostras->push_back(std::make_shared<Sample>(1, -1, 1));
    //     amostras->push_back(std::make_shared<Sample>(1, 1, 1));

    //     auto adaline = std::make_shared<Adaline>(0.1);
    //     adaline->train(amostras, 10);
    //     std::cout << std::to_string(adaline->think(std::make_shared<Sample>(-1, -1))) << std::endl;
    //     std::cout << std::to_string(adaline->think(std::make_shared<Sample>(-1, 1))) << std::endl;
    //     std::cout << std::to_string(adaline->think(std::make_shared<Sample>(1, -1))) << std::endl;
    //     std::cout << std::to_string(adaline->think(std::make_shared<Sample>(1, 1))) << std::endl;
    // }

    // {
    //     std::cout << "Tabela xor" << std::endl;
    //     auto amostras = std::make_shared<std::list<std::shared_ptr<Sample>>>();
    //     amostras->push_back(std::make_shared<Sample>(-1, -1, -1));
    //     amostras->push_back(std::make_shared<Sample>(-1, 1, 1));
    //     amostras->push_back(std::make_shared<Sample>(1, -1, 1));
    //     amostras->push_back(std::make_shared<Sample>(1, 1, -1));

    //     auto adaline = std::make_shared<Adaline>(0.1);
    //     adaline->train(amostras, 10);

    //     std::cout << std::to_string(adaline->think(std::make_shared<Sample>(-1, -1))) << std::endl;
    //     std::cout << std::to_string(adaline->think(std::make_shared<Sample>(-1, 1))) << std::endl;
    //     std::cout << std::to_string(adaline->think(std::make_shared<Sample>(1, -1))) << std::endl;
    //     std::cout << std::to_string(adaline->think(std::make_shared<Sample>(1, 1))) << std::endl;
    // }

    return 0;
}