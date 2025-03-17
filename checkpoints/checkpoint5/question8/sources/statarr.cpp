#include <iostream>
#include <iomanip>
#include <cmath>

double calc_mean(double *arr, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}

double calc_stddev(double *arr, int n)
{
    double *squared = new double[n];
    for (int i = 0; i < n; i++)
    {
        squared[i] = arr[i] * arr[i];
    }
    double ret = sqrt(calc_mean(squared, n) - calc_mean(arr, n) * calc_mean(arr, n));
    delete[] squared;
    return ret;
}

int main(void)
{
    double array[5];
    double mean, stddev;
    std::cin >> array[1] >> array[2] >> array[3] >> array[4] >> array[5];
    mean = calc_mean(array, 5);
    stddev = calc_stddev(array, 5);

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << "Mean = " << mean << std::endl;
    std::cout << "Standard deviation = " << stddev << std::endl;

    return 0;
}