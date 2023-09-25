#include<stdio.h>
#include<math.h>
#define eps 1e-5
double inverse[3][3];
void printMat(int dim,double mat[dim][dim]){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%.2lf   ",mat[i][j]);
        }
        printf("\n");
    }
}

double output[3][3];
void matrixMultiplication(int rowX,int colX,int rowY,int colY,double matX[rowX][colX],double matY[rowY][colY]){
    for(int i=0; i<rowX; i++){
        for(int j=0; j<colY; j++){
            double sum=0;
            for(int k=0; k<rowY; k++){
                sum += matX[i][k] * matY[k][j];
            }
            output[i][j]= sum;
        }
    }
}

double inverse[3][3];
void matInverse(int dim,double augMat[dim][2*dim]){
    for(int i=0; i<dim-1; i++){
        if(augMat[i][i]==0){
            int index = -1;
            for(int j=i+1; j<dim; j++){
                if(augMat[j][i]!=0){
                    index = j;
                    break;
                }
            }
            double temp[2*dim];
            for(int j=0; j<2*dim; j++){
                temp[j] = augMat[i][j];
            }
            for(int j=0; j<2*dim; j++){
                augMat[i][j] = augMat[index][j];
            }
            for(int j=0; j<2*dim; j++){
                augMat[index][j] = temp[j];
            }
        }
        double pivot = augMat[i][i];
        double ratio;
        for(int j=i+1; j<dim; j++){
            ratio = augMat[j][i]/pivot;
            for(int k=0; k<2*dim; k++){
                augMat[j][k] = fabs(augMat[j][k] - (augMat[i][k]*ratio)) < eps ? 0 : augMat[j][k] - (augMat[i][k]*ratio);
            }
        }
    }
    for(int i=dim-1; i>0; i--){
        double pivot = augMat[i][i];
        double ratio;
        for(int j=i-1; j>=0; j--){
            ratio = augMat[j][i]/pivot;
            for(int k=0; k<2*dim; k++){
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
        for(int j=dim; j<2*dim; j++){
            inverse[i][j-dim] = augMat[i][j];
        }
    }
}

void matReduce(int dim,double augMat[dim][dim],double l[dim][dim]){
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
            double temp[dim];
            for(int j=0; j<dim; j++){
                temp[j] = augMat[i][j];
            }
            for(int j=0; j<dim; j++){
                augMat[i][j] = augMat[index][j];
            }
            for(int j=0; j<dim; j++){
                augMat[index][j] = temp[j];
            }
        }
        double pivot = augMat[i][i];
        double ratio;
        for(int j=i+1; j<dim; j++){
            ratio = augMat[j][i]/pivot;
            for(int k=0; k<dim; k++){
                augMat[j][k] = fabs(augMat[j][k] - (augMat[i][k]*ratio)) < eps ? 0 : augMat[j][k] - (augMat[i][k]*ratio);
            }
            l[j][i] = ratio;
        }
    }
    printf("Your changed L matrix: \n");
    printMat(dim,l);
    printf("\n");
    printf("Your changed U matrix: \n");
    printMat(dim,augMat);
    printf("\n");
    matrixMultiplication(dim,dim,dim,dim,l,augMat);
}

int main(){
    freopen("luMat.txt","r",stdin);
    int dim;
    scanf("%d",&dim);
    double mat[dim][dim];
    double l[dim][dim];
    double u[dim][dim];
    double val;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            scanf("%lf",&val);
            mat[i][j] = val;
            u[i][j] = val;
            if(i==j)l[i][j] = 1;
            else l[i][j] = 0;
        }
    }
    printf("Your A matrix is: \n");
    printMat(dim,mat);
    printf("\n");
    printf("Your L matrix is: \n");
    printMat(dim,l);
    printf("\n");
    printf("Your U matrix is: \n");
    printMat(dim,u);
    printf("\n");
    matReduce(dim,u,l);
    printf("After multiply L and U result is: \n");
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%.2lf ",output[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}