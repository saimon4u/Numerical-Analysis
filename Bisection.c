#include<stdio.h>
#define E 1e-4
double calculate(double x){
    return (x*x*x) + (4*x*x) - 10;
}
int main(){
    double a,b;
    printf("Enter the end points: ");
    scanf("%lf %lf",&a,&b);
    while(1){
        if((calculate(a)*calculate(b)) >= 0){
            printf("Solution doesn't exists!\n");
            break;
        }
        double mid = (a+b)/2;
        if(calculate(mid) < E){
            printf("The root of this equation is: %lf\n",mid);
            break;
        }
        if((calculate(a)*calculate(mid)) < 0)b = mid;
        else a = mid;
    }
}