#include<stdio.h>
#include<math.h>
const double PI = 3.1416;
int main(){
    int i,n=100;
    double a = 0,b = 2*PI;
    double h = (b-a)/n;
    double x[101],y[101],dy[101];
    x[0] = a;
    y[0] = sin(x[0]);
    for(i=1; i<n; i++){
        x[i] = x[i-1] + h;
        y[i] = sin(x[i]);
    }
    x[n] = b;
    y[n] = sin(x[n]);
    dy[0] = (y[1]-y[0])/(x[1]-x[0]);
    for(i=1; i<n; i++){
        dy[i] = (y[i+1]-y[i-1])/(x[i+1]-x[i-1]);
    }
    dy[n] = (y[n]-y[n-1])/(x[n]-x[n-1]);
    printf("\"x\",\"f(x)\",\"f'(x)\"\n");
    for(i=0; i<n; i++){
        printf("%lf,%lf,%lf\n",x[i],y[i],dy[i]);
    }
    return 0;
}