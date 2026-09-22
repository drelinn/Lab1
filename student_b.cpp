#include "shared_types.h"
#include <memory>
#include <cmath>

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data) {
    if (!data || !data->f) { //перевірка на нульовий показжик
        return nullptr;
    }
    int iterations = 0;
    double a = data->a;
    double b = data->b;

    const double eps = data->epsilon;
    const double delta = eps / 4.0;

    while (std::abs(b - a) > eps) {
        ++iterations;

        double mid = (a + b) / 2.0;
        double x1 = mid - delta;
        double x2 = mid + delta;

        double f1 = data->f(x1);
        double f2 = data->f(x2);

        if (f1 < f2) {
            b = x2;
        }
        else {
            a = x1;
        }

       
       
    }
    double extremum_x = (a + b) / 2.0;
    double extremum_y = data->f(extremum_x);

    return std::make_unique<Result>(Result{ extremum_x, extremum_y, iterations });
}
