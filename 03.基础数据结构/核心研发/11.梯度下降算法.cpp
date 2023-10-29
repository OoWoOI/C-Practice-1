/*************************************************************************
	> File Name: 11.梯度下降算法.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 29 Oct 2023 09:00:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double gradientDesc(double a, double b, double c, int cnt) {
    double l = 0.1;
    double x = rand() % RAND_MAX * 20 - 10;
    int i;
    for (int i = 0; i < cnt; i++) {
        double gradient = 2 * a * x + b;
        if (a > 0) { 
            x -= gradient * l;
        } else {
            x += gradient * l;
        }

        double fx = a * x * x + b * x + c;
        printf("i = %d x = %lf fx = %lf gradient = %lf\n", i, x, fx, gradient);
    }

    return x;
}

int main() {
    srand(time(0));
    double a, b, c;
    a = rand() % 20 - 10;
    b = rand() % 20 - 10;
    c = rand() % 20 - 10;
    a = a == 0 ? 1 : a;
    printf("fx = (%lf * x ^ 2 + %lf * x + %lf\n", a, b, c);
    gradientDesc(a, b, c, 100);
    return 0;
}
