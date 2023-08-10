#include<stdio.h>
#define N 10
#define f(x) (((x)*(x)) + 1)
int main(){
    double a,b;
    printf("Enter a & b: ");
    scanf("%lf %lf",&a,&b);
    double h = (b-a)/N;
    double x[N+1],y[N+1];
    x[0] = a;
    for(int i=1; i<N; i++){
        x[i] = x[i-1] + h;
    }
    x[N] = b;
    for(int i=0; i<=N; i++){
    	y[i] = f(x[i]);
    }
    double sum_X = y[0] + y[N];
    double sum_O = 0,sum_E = 0;
    for(int i=1; i<N; i++){
    	if(i%2==0)sum_E += y[i];
    	else sum_O += y[i];
    }
    double I = ((sum_X + 4*sum_O + 2*sum_E)*h)/3;
    printf("Simpson's  1/3 Rule..........................\n");
    printf("Integral value = %lf\n",I);
    printf("...............................................................\n");
    return 0;
}
