#include <stdio.h>
#include <math.h>
#define PI 3.14159265

void GetSinCos(int degree, double *dSin, double *dCos)
{
    *dSin = sin(degree * PI / 180);
    *dCos = cos(degree * PI / 180);
}

int main(void)
{
    double dSin;
    double dCos;
    int degree;

    scanf("%d", &degree);
    GetSinCos(degree, &dSin, &dCos);
    printf("The sin is %g \n", dSin);
    printf("The cos is %g \n", dCos);

    return 0;
}
