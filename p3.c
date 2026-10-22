/* CS100 Fall 2026 - HW2 Problem 3: Polynomial evaluation
 *
 * Evaluate P(x) at m given points; print each value rounded to 3 decimals.
 * An array is enough for the coefficients; do not use heap memory and do
 * not use <math.h> (your program is not linked against the math library).
 * Do not rename this file.
 */
#include <stdio.h>

double fpow(double base, int exp)
{
    double result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;

    double a[1000];
    for (int i = 0; i <= n; i++) {
        if (scanf("%lf", &a[i]) != 1) return 1;
    }

    int m;
    if (scanf("%d", &m) != 1) return 1;

    for (int k = 0; k < m; k++) {
        double x;
        if (scanf("%lf", &x) != 1) return 1;

        double sum = 0;
        for (int j = 0; j <= n; j++) {
            sum += a[j] * fpow(x, j);
        }
        printf("%.3f\n", sum);
    }
    return 0;
}