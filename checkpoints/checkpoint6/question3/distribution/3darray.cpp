#include <iostream>

int main(void)
{
    double x[2][2][3] = {{{3, 4, 2}, {0, -3, 9}}, {{13, 4, 56}, {5, 9, 3}}};
    double max = x[0][0][0];
    double min = x[0][0][0];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                max = (x[i][j][k] > max) ? x[i][j][k] : max;
                min = (x[i][j][k] < min) ? x[i][j][k] : min;
            }
        }
    }

    std::cout << max << std::endl;
    std::cout << min << std::endl;

    return 0;
}