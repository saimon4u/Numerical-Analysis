#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 10
#define h(x) (pow(x,2) - sqrt(x))
#define E 1e-5
double bisection(double a,double b){
    int i = 1;
    while(1){
        if((h(a)*h(b)) >= 0){
            break;
        }
        double mid = (a+b)/2;
        if(fabs(h(mid)) < E){
            return mid;
        }
        if((h(a)*h(mid)) < 0)b = mid;
        else a = mid;
    	i++;
    }
}
int main(){
    double ra,rb;
    printf("Enter ra and rb: ");
    scanf("%lf %lf",&ra,&rb);
    double a = bisection(ra,rb);
    double h = (a-0.0)/N;
    double x[N+1],y[N+1];
    x[0] = 0.0;
    for(int i=1; i<N; i++){
        x[i] = x[i-1] + h;
    }
    x[N] = a;
    for(int i=0; i<=N; i++){
        y[i] = fabs(h(x[i]));
        //printf("%d %lf\n",i,y[i]);
    }
    double sum_X = y[0] + y[N];
    double sum_I = 0;
    for(int i=1; i<N; i++){
        sum_I += y[i];
    }
    double I = ((sum_X + 2*sum_I)*h)/2;
    printf("The area between g(x) & f(x) is: %lf square unit\n",I);
    return 0;
}
