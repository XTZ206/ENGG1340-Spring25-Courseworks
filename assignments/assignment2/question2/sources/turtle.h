#ifndef TURTLE_H
#define TURTLE_H

double r2d(double radian);
double d2r(double degree);

void returnToHome(double & x, double & y);
bool readInput(double & distance, double & direction);
void move(double & x, double & y, double distance, double direction);
void findHome(double x, double y, double & distance, double & direction);

#endif