#include<stdio.h>
#include<math.h>
#define eps 1e-5
void printMat(int dim,double mat[dim][dim+1]){
    for(int i=0; i<dim; i++){
        for(int j=0; j<=dim; j++){
            printf("%.2lf   ",mat[i][j]);
        }
        printf("\n");
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
    printf("Your matrix is: \n");
    printMat(dim,augMat);
    printf("\n");
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
                return 0;
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

    for(int i=0; i<dim; i++){
        if(augMat[i][i] != 1){
            double divisor = augMat[i][i];
            for(int j=0; j<=dim; j++){
                augMat[i][j] /= divisor;
            }
        }
    }
    for(int i=0; i<dim; i++){
        printf("%c = %.2lf\n",'z' - dim + 1 + i,augMat[i][dim]);
    }
    return 0;
}