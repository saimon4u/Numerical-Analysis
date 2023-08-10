#include<stdio.h>
#define N 10
int main(){
	double x[] = {0.0,0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0},
	y[] = {1.0,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5.0};
	double h = x[1] - x[0];
	double sum_X = y[0] + y[N];
	double sum_E= 0,sum_O = 0;
	for(int i=1; i<N; i++){
		if(i%2==0)sum_E += y[i];
		else sum_O += y[i];
	}
	double I = ((sum_X + 4*sum_O + 2*sum_E)*h)/3;
	printf("Simpson's 1/3 Rule:.....................................\n");
	printf("Integral value = %lf\n",I);
	printf("...........................................................................\n");
	return 0;
}
