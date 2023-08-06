#include<stdio.h>
#include<math.h>
#define E 1e-5
double g(double x){
    return sqrt((10-pow(x,3))/(4));
}
double f(double x){
    return  (x*x*x+4*x*x -10);
}


void fixedPoint(double a){
	printf("No:	a		b		f(a)		f(b)\n");
    int i = 1;
    while(1){
        double b = g(a);
        printf("%d	%lf	%lf	%lf	%lf\n",i,a,b,f(a),f(b));
        if(fabs(f(b)) < E){
            printf("The root of this equation is: %lf\n",b);
            break;
        }
        a = b;
        i++;
    }
}


int main(){
    double a;
    printf("Enter the end points: ");
    scanf("%lf",&a);
    fixedPoint(a);
    return 0;
}
