/*************************************************************************
	> File Name: 02.NewTon.c
	> Author: 
	> Mail: 
	> Created Time: Sat 16 Sep 2023 10:06:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define EPSL 1e-6
double F(double x) {
    return x * x - 2;
}

double f(double x) {
    return 2 * x;
}

double NewTon(double (*F)(double), double (*f)(double)) {
    double x = -1.0;
    while (fabs(F(x)) > EPSL) {
        x -= F(x) / f(x);
    }
    return x;
}

int main() {
    double x = NewTon(F, f);
    printf("%lf\n", x);
    printf("%lf * %lf - 2 = %lf\n", x, x,  x * x - 2);
    return 0;
}
