#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "random.h"
using namespace std;

int main() {

  // Set a random seed for consistent output
  srand(21131340);
  
  int n;
  cin >> n;
  int count = 0;

  for(int i = 0; i < n; ++i) {
    double x, y;
    randomPoint(x, y);
    if(x*x + y*y < 1) {
      ++count;
    }
  }

  cout << fixed << setprecision(4) << 4.0 * count / n << endl;

  return 0;
}