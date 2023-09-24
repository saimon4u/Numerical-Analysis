#include<stdio.h>
#include<math.h>
#define eps 1e-5
double inverse[3][3];
void printMat(int dim,double mat[dim][dim+1]){
    for(int i=0; i<dim; i++){
        for(int j=0; j<=dim; j++){
            printf("%.2lf   ",mat[i][j]);
        }
        printf("\n");
    }
}
void printInverse(int dim,double mat[dim][2*dim]){
    for(int i=0; i<dim; i++){
        for(int j=0; j<2*dim; j++){
            printf("%.2lf   ",mat[i][j]);
        }
        printf("\n");
    }
}
void matReduce(int dim,double augMat[dim][dim+1]){
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
    printf("Your changed matrix: \n");
    printMat(dim,augMat);
    printf("\n");



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
    printf("Your changed matrix: \n");
    printMat(dim,augMat);
    printf("\n");
}
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
            if(index==-1){
                printf("Solution doesn't exist\n");
                return;
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
    printf("Your changed matrix: \n");
    printInverse(dim,augMat);
    printf("\n");



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
            // printf("%.2lf ",augMat[i][j]);
            inverse[i][j-dim] = augMat[i][j];
        }
    }
}

double output[3][3];
void matrixMultiplication(int rowX,int colX,int rowY,int colY,double matX[rowX][colX],double matY[rowY][colY])
{
    if(colX != rowY)
    {
        printf("The dimentions are not suitable for multiplication\n");
        return;
    }
    for(int i=0; i<rowX; i++)
    {
        for(int j=0; j<colY; j++)
        {
            double sum=0;
            for(int k=0; k<rowY; k++)
            {
                sum += matX[i][k] * matY[k][j];
            }
            output[i][j]= sum;
        }
    }
}

int main(){
    freopen("augmat.txt","r",stdin);
    int dim;
    scanf("%d",&dim);
    double augMat[dim][dim+1];
    for(int i=0; i<dim; i++){
        for(int j=0; j<=dim; j++){
            scanf("%lf",&augMat[i][j]);
        }
    }
    double mainMat[dim][dim];
    double mat[dim][2*dim];
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            mat[i][j] = augMat[i][j];
            mainMat[i][j] = augMat[i][j];
        }
    }
    for(int i=0; i<dim; i++){
        for(int j=dim; j<2*dim; j++){
            if(i+dim==j)mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
    printf("Your matrix is: \n");
    printMat(dim,augMat);
    printf("\n");
    matReduce(dim,augMat);
    double determinant = augMat[0][0] * augMat[1][1] * augMat[2][2];
    printf("Determinant is: %.2lf\n",determinant);
    printf("\n");
    matInverse(dim,mat);
    matrixMultiplication(3,3,3,3,mainMat,inverse);
    printf("Matrix after multiplication: \n");
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%.2lf ",output[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Your inverse matrix: \n");
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%.2lf ",inverse[i][j]);
        }
        printf("\n");
    }
    return 0;
}