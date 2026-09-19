#include "shared_types.h"
#include <memory>
#include <cmath>

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    double a = data->a;
    double b = data->b;
    double epsilon = data->epsilon;
    
    // Пропорція золотого перерізу
    const double phi = (std::sqrt(5.0) - 1.0) / 2.0;
    
    double x1 = b - phi * (b - a);
    double x2 = a + phi * (b - a);
    
    double y1 = data->f(x1);
    double y2 = data->f(x2);
    
    int iterations = 0;
    
    // Шукаємо мінімум функції
    while (std::abs(b - a) > epsilon) {
        if (y1 < y2) {
            b = x2;
            x2 = x1;
            y2 = y1;
            x1 = b - phi * (b - a);
            y1 = data->f(x1);
        } else {
            a = x1;
            x1 = x2;
            y1 = y2;
            x2 = a + phi * (b - a);
            y2 = data->f(x2);
        }
        iterations++;
    }
    
    // Знаходимо координати точки мінімуму
    double x_min = (a + b) / 2.0;
    double y_min = data->f(x_min);
    
    // Повертаємо результат через std::unique_ptr
    return std::make_unique<Result>(Result{x_min, y_min, iterations});
}