#include<stdio.h>
#include<math.h>
#define E 1e-6
double calculate(double x){
    return sqrt((10-pow(x,3))/(4));
}


void fixedPoint(double a){
	printf("No:	a		b		c		f(a)		f(b)		f(c)\n");
    int i = 1;
    while(1){
        double mid = calculate(a);
        printf("%d	%lf	%lf	%lf	%lf\n",i,a,mid,calculate(a),calculate(mid));
        if(fabs(calculate(mid)) < E){
            printf("The root of this equation is: %lf\n",mid);
            break;
        }
        a = mid;
        i++;
    }
}


int main(){
    double a;
    printf("Enter the end points: ");
    scanf("%lf ",&a);
    fixedPoint(a);
    return 0;
}
