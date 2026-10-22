/* CS100 Fall 2026 - HW2 Problem 3: Polynomial evaluation
 *
 * Evaluate P(x) at m given points; print each value rounded to 3 decimals.
 * An array is enough for the coefficients; do not use heap memory and do
 * not use <math.h> (your program is not linked against the math library).
 * Do not rename this file.
 */
#include <stdio.h>

double fpow(double base,int exp){
    double result =1;
    for(int i = 0; i<exp; i++){
        result=result* base;
    }
    return result;
}

int main(void)
{
    int n;
    
    scanf("%d",&n);
    double a[n+1];
    for(int i=0;i<n+1;i++){
        scanf("%lf",&a[i]);
    }




    int nx;
    
    scanf("%d",&nx);
    double x[nx];
    for(int i=0;i<nx;i++){
        scanf("%lf",&x[i]);
    }


    double sum;
    double d;
    for(int i=0;i<nx;i++){
        sum=0;
        for(int j=0;j<n+1;j++){
            d=a[j]*fpow(x[i],j);
            sum+=d;
        }
        printf("%.3f\n",sum);


    }
    return 0;
}
