#include<stdio.h>
#include<math.h>
#define f(x) (x*x)+1
const double PI = 3.1416;
int main(){
    int i,n=10;
    double a = 0.0,b = 2.0;
    double h = (b-a)/n;
    double x[101],y[101],dy[101];
    x[0] = a;
    y[0] = f(x[0]);
    for(i=1; i<=n; i++){
        x[i] = x[i-1] + h;
        y[i] = f(x[i]);
    }
    x[n] = b;
    y[n] = f(x[n]);
    for(i=1; i<=n; i++){
        dy[i] = (y[i]-y[i-1])/h;
    }
    printf("-------------------------------------------\n");
    printf("%4s%12s%12s%12s","i","x[i]","f(x[i])","f'(x[i])\n");
    printf("-------------------------------------------\n");
    for(i=0; i<=n; i++){
        printf("%4d%12lf%12lf%12lf\n",i,x[i],y[i],dy[i]);
    }
    printf("-------------------------------------------\n");
    return 0;
}