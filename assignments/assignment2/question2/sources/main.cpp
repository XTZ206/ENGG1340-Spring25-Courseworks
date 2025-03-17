#include <iostream>
#include <iomanip>
#include "turtle.h"
using namespace std;

int main()
{

  double x, y, distance, direction;

  returnToHome(x, y);

  cout << fixed << setprecision(1);

  while (readInput(distance, direction))
  {
    move(x, y, distance, direction);
    cout << distance << " @ " << direction << " -> " << x << ", " << y << endl;
  }

  findHome(x, y, distance, direction);
  cout << distance << " @ " << direction << " -> Home" << endl;

  return 0;
}