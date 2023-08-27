#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int output[5][5];
void matrixMultiplication(int rowX,int colX,int rowY,int colY,int matX[rowX][colX],int matY[rowY][colY])
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
            int sum=0;
            for(int k=0; k<rowY; k++)
            {
                sum += matX[i][k] * matY[k][j];
            }
            output[i][j]= sum;
        }
    }
}

void printMat(int row,int col,int mat[row][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(mat[i][j])printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(0));
    int rowA,rowB,colA,colB;
    freopen("matrix.txt","r",stdin);
    scanf("%d %d %d %d",&rowA,&colA,&rowB,&colB);
    int matX[rowA][colA];
    int matY[rowB][colB];
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d",&matX[i][j]);
            // matX[i][j] = rand()%100 + 1;
        }
    }
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d",&matY[i][j]);
            // matY[i][j] = rand()%100 + 1;
        }
    }
    matrixMultiplication(rowA,colA,rowB,colB,matX,matY);
    printf("Your first matrix is: \n");
    printMat(rowA,colA,matX);
    printf("Your second matrix is: \n");
    printMat(rowB,colB,matY);
    printf("Your result matrix is: \n");
    printMat(5,5,output);
    return 0;
}