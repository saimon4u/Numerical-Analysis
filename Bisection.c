#include<stdio.h>
#include<math.h>
#define E 1e-6
double calculate(double x){
    return (x*x*x) + (4*x*x) - 5;
}


void bisection(double a,double b){
	// printf("No:	a		b		c		f(a)		f(b)		f(c)\n");
    int i = 1;
    while(1){
        if((calculate(a)*calculate(b)) >= 0){
            // printf("Solution doesn't exists!\n");
            printf("[%lf,%lf]: No Root Found!\n",a,b);
            break;
        }
        double mid = (a+b)/2;
        // printf("%d	%lf	%lf	%lf	%lf	%lf	%lf\n",i,a,b,mid,calculate(a),calculate(b),calculate(mid));
        if(fabs(calculate(mid)) < E){
            // printf("The root of this equation is: %lf\n",mid);
            printf("[%lf,%lf]: Root = %lf\n",a,b,mid);
            break;
        }
        if((calculate(a)*calculate(mid)) < 0)b = mid;
        else a = mid;
    	i++;
    }
}


int main(){
    double a,b;
    printf("Enter the end points: ");
    scanf("%lf %lf",&a,&b);
    double diff = (b-a)/6;
    for(int i=0; i<6; i++){
        bisection(a,a+diff);
        a = a+diff;
    }
    return 0;
}
