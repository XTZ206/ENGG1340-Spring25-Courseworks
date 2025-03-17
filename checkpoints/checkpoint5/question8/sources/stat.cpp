#include <iostream>
#include <iomanip>
#include <cmath>

double calc_mean(double x1, double x2, double x3, double x4, double x5)
{
    return (x1 + x2 + x3 + x4 + x5) / 5;
}

double calc_stddev(double x1, double x2, double x3, double x4, double x5)
{
    return sqrt(calc_mean(x1 * x1, x2 * x2, x3 * x3, x4 * x4, x5 * x5) - calc_mean(x1, x2, x3, x4, x5) * calc_mean(x1, x2, x3, x4, x5));
}

int main(void)
{
    double x1, x2, x3, x4, x5, mean, stddev;
    std::cin >> x1 >> x2 >> x3 >> x4 >> x5;
    mean = calc_mean(x1, x2, x3, x4, x5);
    stddev = calc_stddev(x1, x2, x3, x4, x5);

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << "Mean = " << mean << std::endl;
    std::cout << "Standard deviation = " << stddev << std::endl;

    return 0;
}