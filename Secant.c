#include<stdio.h>
#include<math.h>
#define E 1e-6
double calculate(double x){
    return (x*x*x) + (4*x*x) - 10;
}


void secant(double a,double b){
	printf("No:	a		b		c		f(a)		f(b)		f(c)\n");
    int i = 1;
    while(1){
        double mid = b - ((calculate(b)*(b-a))/(calculate(b)-calculate(a)));
        printf("%d	%lf	%lf	%lf	%lf	%lf	%lf\n",i,a,b,mid,calculate(a),calculate(b),calculate(mid));
        if(fabs(calculate(mid)) < E){
            printf("The root of this equation is: %lf\n",mid);
            break;
        }
        a = b;
        b = mid;
        i++;
    }
}


int main(){
    double a,b;
    printf("Enter the end points: ");
    scanf("%lf %lf",&a,&b);
    secant(a,b);
    return 0;
}
