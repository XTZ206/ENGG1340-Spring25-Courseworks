#include <iostream>
#include <cmath>

double r2d(double radian);
double d2r(double degree);

void returnToHome(double &x, double &y)
{
    x = 0;
    y = 0;
}

bool readInput(double &distance, double &direction)
{
    std::cin >> distance;
    if (distance <= 0)
    {
        return false;
    }
    std::cin >> direction;
    while (direction < 0)
    {
        direction += 360;
    }
    while (direction >= 360)
    {
        direction -= 360;
    }
    return true;
}

void move(double &x, double &y, double distance, double direction)
{
    x += distance * sin(d2r(direction));
    y += distance * cos(d2r(direction));
}

void findHome(double x, double y, double &distance, double &direction)
{
    distance = sqrt(x * x + y * y);
    direction = r2d(atan2(x, y)) + 180;
}
