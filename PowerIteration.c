#include<stdio.h>
#include<math.h>
#define MAX 100
#define eps 1e-6
double mat[3][3] = {
    {2,-1,0},
    {-1,2,-1},
    {0,-1,2}
};
double trans[3][1];
void TransposeEigenVec(double vec[3]){
    trans[0][0] = vec[0];
    trans[1][0] = vec[1];
    trans[2][0] = vec[2];
}
double EuclideanNorm(double vec[3]){
    double max = -99999999999;
    for(int i=0; i<3; i++){
        if(fabs(vec[i]) > max) max = fabs(vec[i]);
    }
    return max;
}

double output[3][1];
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

void getResult(double eigenVec[3]){
    TransposeEigenVec(eigenVec);
    matrixMultiplication(3,3,3,1,mat,trans);
}
int main(){
    double eigenVec[MAX][3];
    eigenVec[0][0] = 1;
    eigenVec[0][1] = 0;
    eigenVec[0][2] = 0;
    double lambda[MAX];
    int i=1;
    printf("    ");
    for(int j=0; j<3; j++){
        printf("%lf\t",eigenVec[0][j]);
    }
    printf("\n");
    while(1){
        getResult(eigenVec[i-1]);
        eigenVec[i][0] = output[0][0];
        eigenVec[i][1] = output[1][0];
        eigenVec[i][2] = output[2][0];
        double norm = EuclideanNorm(eigenVec[i]);
        for(int j=0; j<3; j++){
            eigenVec[i][j] /= norm;
        }
        lambda[i] = norm;
        printf("%2d  ",i);
        for(int j=0; j<3; j++){
            printf("%lf\t",eigenVec[i][j]);
        }
        printf("  ");
        printf("EigenValue: %lf\n",lambda[i]);



        if(i>1 && fabs(lambda[i]-lambda[i-1]) < eps) break;
        i++;
    }
    return 0;
}