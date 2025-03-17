#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "turtle.h"

// Convert radian to degree
double r2d(double radian) {
  return radian * 180 / M_PI;
}

// Convert degree to radian
double d2r(double degree) {
  return degree * M_PI / 180;
}