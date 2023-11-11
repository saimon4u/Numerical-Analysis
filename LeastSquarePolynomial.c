#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>


#define MAX 100
#define eps 1e-5
double x[MAX];
double fx[MAX];
double mat[MAX][MAX];
double transFx[3][1];
double transMat[MAX][MAX];
double outputMat[MAX][MAX];
double outputFx[MAX][MAX];
double augMat[MAX][MAX];
double soln[MAX];


bool Operator(char x){
    return (x=='+' || x=='-' || x=='/' || x=='*');
}


int GetDegree(char *eqn){
    int size = strlen(eqn);
    int deg = 0;
    for(int i=size-1; i>=0; i--){
        if(eqn[i] == 'x' && i==size-1){
            deg = 1;
            break;
        }
        else if(eqn[i] == 'x' && !Operator(eqn[i+1])){
            deg = eqn[i+1] - '0';
            break;
        }
        else if(eqn[i] == 'x' && Operator(eqn[i+1])){
            deg = 1;
            break;
        }
    }
    return deg;
}


void TransposeFx(){
    transFx[0][0] = fx[0];
    transFx[1][0] = fx[1];
    transFx[2][0] = fx[2];
    transFx[3][0] = fx[3];
}


void TransposeMat(int deg,int num){
    for(int i=0; i<deg; i++){
        for(int j=0; j<num; j++){
            transMat[i][j] = mat[j][i];
        }
    }
}


void matrixMultiplication(int rowX,int colX,int rowY,int colY){
    if(colY==1){
        for(int i=0; i<rowX; i++){
            for(int j=0; j<colY; j++){
                double sum=0;
                for(int k=0; k<rowY; k++){
                    sum += transMat[i][k] * transFx[k][j];
                }
                outputFx[i][j]= sum;
            }
        }
        return;
    }
    for(int i=0; i<rowX; i++){
        for(int j=0; j<colY; j++){
            double sum=0;
            for(int k=0; k<rowY; k++){
                sum += transMat[i][k] * mat[k][j];
            }
            outputMat[i][j]= sum;
        }
    }
}

void MatSolve(int dim){
    for(int i=0; i<dim-1; i++){
        if(augMat[i][i]==0){
            int index = -1;
            for(int j=i+1; j<dim; j++){
                if(augMat[j][i]!=0){
                    index = j;
                    break;
                }
            }
            if(index==-1){
                printf("Solution doesn't exist\n");
                return;
            }
            double temp[dim+1];
            for(int j=0; j<=dim; j++){
                temp[j] = augMat[i][j];
            }
            for(int j=0; j<=dim; j++){
                augMat[i][j] = augMat[index][j];
            }
            for(int j=0; j<=dim; j++){
                augMat[index][j] = temp[j];
            }
        }
        double pivot = augMat[i][i];
        double ratio;
        for(int j=i+1; j<dim; j++){
            ratio = augMat[j][i]/pivot;
            for(int k=0; k<=dim; k++){
                augMat[j][k] = fabs(augMat[j][k] - (augMat[i][k]*ratio)) < eps ? 0 : augMat[j][k] - (augMat[i][k]*ratio);
            }
        }
    }

    for(int i=dim-1; i>0; i--){
        double pivot = augMat[i][i];
        double ratio;
        for(int j=i-1; j>=0; j--){
            ratio = augMat[j][i]/pivot;
            for(int k=0; k<=dim; k++){
                augMat[j][k] = fabs(augMat[j][k] - (augMat[i][k]*ratio)) < eps ? 0 : augMat[j][k] - (augMat[i][k]*ratio);
            }
        }
    }

    for(int i=0; i<dim; i++){
        if(augMat[i][i] != 1){
            double divisor = augMat[i][i];
            for(int j=0; j<2*dim; j++){
                augMat[i][j] /= divisor;
            }
        }
    }
    
    for(int i=0; i<dim; i++){
        soln[i] = augMat[i][dim];
    }
}


int main(){
    freopen("Polynomial.txt","r",stdin);
    char eqn[100];
    gets(eqn);
    int degree = GetDegree(eqn);
    degree++;
    int number;
    scanf("%d",&number);
    for(int i=0; i<number; i++){
        scanf("%lf %lf",&x[i],&fx[i]);
    }
    for(int i=0; i<number; i++){
        for(int j=0; j<degree; j++){
            if(j==0){
                mat[i][j] = 1;
            }
            else{
                mat[i][j] = pow(x[i],j);
            }
        }
    }
    TransposeFx();
    TransposeMat(degree,number);
    matrixMultiplication(degree,number,number,degree);
    matrixMultiplication(degree,number,number,1);
    for(int i=0; i<degree; i++){
        for(int j=0; j<=degree; j++){
            if(j==degree){
                augMat[i][j] = outputFx[i][0];
            }
            else{
                augMat[i][j] = outputMat[i][j];
            }
        }
    }
    MatSolve(degree);
    printf("\n\nThe final equation is: \nF(x) = %.1lf%.1lfx+%.1lfx^2\n\n",soln[0],soln[1],soln[2]);
}