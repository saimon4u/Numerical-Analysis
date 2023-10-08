#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define eps 10e-3
int eqn[3][4] = {
    {20,1,-2,17},
    {3,20,-1,-18},
    {2,-3,20,25}
};
int main(){
    bool dominant = true;
    double sum = 0;
    bool iterate = true;
    double oldVal[3],newVal[3];
    int itNum = 0;
    for(int i=0; i<3; i++)oldVal[i] = 0.0;
    for(int i=0; i<3; i++){
        sum = 0.0;
        for(int j=0; j<3; j++){
            if(i != j) sum += fabs(eqn[i][j]);
        }
        if(eqn[i][i] <= sum) dominant = false;
    }
    if(!dominant){
        printf("The matrix is not diagonally dominant!\n");
    }
    while(iterate){
        itNum++;
        newVal[0] = (eqn[0][3] - ((eqn[0][1]*oldVal[1]) + (eqn[0][2]*oldVal[2])))/eqn[0][0];
        newVal[1] = (eqn[1][3] - ((eqn[1][0]*oldVal[0]) + (eqn[1][2]*oldVal[2])))/eqn[1][1];
        newVal[2] = (eqn[2][3] - ((eqn[2][0]*oldVal[0]) + (eqn[2][1]*oldVal[1])))/eqn[2][2];
        if((fabs(newVal[0]-oldVal[0]) < eps) && (fabs(newVal[1]-oldVal[1]) < eps) && (fabs(newVal[2]-oldVal[2]) < eps)){
            iterate = false;
        }
        for(int i=0; i<3; i++) oldVal[i] = newVal[i];
    }
    printf("Iteration needed in Jackobian = %d\n",itNum);
    printf("Solutions are: ");
    for(int i=0; i<3; i++) printf("%lf  ",newVal[i]);
    printf("\n\n\n");

// For Gauss Siddle part

    for(int i=0; i<3; i++){
        newVal[i] = 0.0;
        oldVal[i] = 0.0;
    }
    iterate = true;
    itNum = 0;
    while(iterate){
        itNum++;
        newVal[0] = (eqn[0][3] - ((eqn[0][1]*newVal[1]) + (eqn[0][2]*newVal[2])))/eqn[0][0];
        newVal[1] = (eqn[1][3] - ((eqn[1][0]*newVal[0]) + (eqn[1][2]*newVal[2])))/eqn[1][1];
        newVal[2] = (eqn[2][3] - ((eqn[2][0]*newVal[0]) + (eqn[2][1]*newVal[1])))/eqn[2][2];
        if((fabs(newVal[0]-oldVal[0]) < eps) && (fabs(newVal[1]-oldVal[1]) < eps) && (fabs(newVal[2]-oldVal[2]) < eps)){
            iterate = false;
        }
        for(int i=0; i<3; i++) oldVal[i] = newVal[i];
    }
    printf("Iteration needed in GaussSiddle = %d\n",itNum);
    printf("Solutions are: ");
    for(int i=0; i<3; i++) printf("%lf  ",newVal[i]);
    printf("\n");
    return 0;
}