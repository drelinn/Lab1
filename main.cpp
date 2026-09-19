#include <iostream>
#include <memory>
#include "shared_types.h"

// Оголошення функцій
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);

int main() {
    // Створення спільного об'єкта вхідних даних
    auto data = std::make_shared<const InputData>(InputData{
        [](double x) { return (x - 2) * (x - 2) + 3; }, // Тестова функція: мінімум у точці x=2, y=3
        0.0,  // a
        5.0,  // b
        1e-5  // epsilon
    });

    std::cout << "Project Initialized!" << std::endl;
    return 0;
}