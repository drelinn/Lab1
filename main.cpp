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

    auto resultB = calculateB(data);

    if (resultB) {
        auto [x_b, y_b, iters_b] = *resultB;
        std::cout << "\n";
        std::cout << "StudentB result:\n";
        std::cout << "extreme point (x): " << x_b << "\n";
        std::cout << "Value f(x):        " << y_b << "\n";
        std::cout << "Count of iterations:   " << iters_b << "\n";
    }
    return 0;
}