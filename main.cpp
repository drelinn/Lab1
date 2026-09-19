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
    
    // Виклик алгоритму Студента А
    auto resultA = calculateA(data);
    
    // Використання structured bindings для отримання результату
    auto [extremum_x_A, extremum_y_A, iterations_A] = *resultA; 
    
    std::cout << "\n--- Result of Student A (Golden Section) ---" << std::endl;
    std::cout << "Extremum X: " << extremum_x_A << std::endl;
    std::cout << "Extremum Y: " << extremum_y_A << std::endl;
    std::cout << "Iterations: " << iterations_A << std::endl;

    return 0;
}