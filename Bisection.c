#include<stdio.h>
#include<math.h>
#define E 1e-6
#define f(x) (x*x*x + 4*x*x - 10)

void bisection(double a,double b){
	printf("No:	a		b		mid		f(a)		f(b)		f(mid)\n");
    int i = 1;
    while(1){
        if((f(a)*f(b)) >= 0){
            printf("Solution doesn't exists!\n");
            break;
        }
        double mid = (a+b)/2;
        printf("%d	%lf	%lf	%lf	%lf	%lf	%lf\n",i,a,b,mid,f(a),f(b),f(mid));
        if(fabs(f(mid)) < E){
            printf("The root of this equation is: %lf\n",mid);
            break;
        }
        if((f(a)*f(mid)) < 0)b = mid;
        else a = mid;
    	i++;
    }
}


int main(){
    double a,b;
    printf("Enter the end points: ");
    scanf("%lf %lf",&a,&b);
    bisection(a,b);
    return 0;
}
