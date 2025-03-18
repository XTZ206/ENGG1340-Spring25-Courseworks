#include <iostream>

int main(void)
{
    double array[20];
    int size;

    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    double mean = 0;
    for (int i = 0; i < size; i++)
    {
        mean += array[i];
    }
    mean /= size;

    double variance = 0;
    for (int i = 0; i < size; i++)
    {
        variance += (array[i] - mean) * (array[i] - mean);
    }
    variance /= size;

    std::cout << "Variance = " << variance << std::endl;
    return 0;
}