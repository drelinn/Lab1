#pragma once
#include <functional>

struct InputData
{
    std::function<double(double)> f; // функція f(x)
    double a;                        // початок інтервалу
    double b;                        // кінець інтервалу
    double epsilon;                  // точність
};

struct Result
{
    double extremum_x; // координата точки екстремуму
    double extremum_y; // значення функції
    int iterations;    // кількість ітерацій
};