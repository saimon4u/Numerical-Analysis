#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define eps 1e-6
#define N 2
double D[N][N];
double RT[N][N];
double S[N][N];
double output[N][N];

void generateRT(double R[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            RT[i][j] = R[j][i];
        }
    }
}

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

void updateD(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            D[i][j] = output[i][j];
        }
    }
}

void updateS(double R[N][N]){
    matrixMultiplication(N,N,N,N,S,RT);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            S[i][j] = output[i][j];
        }
    }
}

int main(){
    double mat[N][N];
    double R[N][N];
    printf("Enter the elements rowwise:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%lf",&mat[i][j]);
            D[i][j] = mat[i][j];
        }
    }
    printf("The given matrix is: \n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%lf\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) S[i][j] = 1;
            else S[i][j] = 0;
        }
    }
    int iter = 1;
    while(true){
        int p,q;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(i!=j && fabs(D[i][j])>eps){
                    p = i;
                    q = j;
                }
            }
        }
        if(fabs(D[p][q])<eps) break;
        double angle = (.5)*atan((D[p][q])/(D[q][q]-D[p][p]));
        double ctheta = cos(angle);
        double stheta = sin(angle);
        R[0][0] = ctheta;
        R[0][1] = stheta*(-1);
        R[1][0] = stheta;
        R[1][1] = ctheta;
        generateRT(R);
        matrixMultiplication(N,N,N,N,RT,D);
        updateD();
        matrixMultiplication(N,N,N,N,D,R);
        updateD();
        updateS(R);
    }
    printf("Eigen values are: %lf   %lf\n\n",D[0][0],D[1][1]);
    printf("Corresponding EigenVectores are: \n\n");
    for(int i=0; i<N; i++){
        printf("( ");
        for(int j=0; j<N; j++){
            printf("%lf ",S[i][j]);
        }
        printf(")^T\n");
    }
    return 0;
}