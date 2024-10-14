#include <stdio.h>
#define SIZE 5
#define SIZE2 5

//Adding matrices function with added array global variable
int added[SIZE][SIZE2];
void addMatrices(int matrix1[SIZE][SIZE2], int matrix2[SIZE][SIZE2]){
    for (int i = 0; i < SIZE; i++){
        for (int x = 0; x < SIZE2; x ++){
            added[i][x] = (matrix1[i][x] + matrix2[i][x]);
        }
    }
}

//Multiply matrices function with multiply array global variable
int multiply[SIZE][SIZE2];
void multiplyMatrices(int matrix1[SIZE][SIZE2], int matrix2[SIZE][SIZE2]){
    for (int i = 0; i < SIZE; i++){
        for (int x = 0; x < SIZE2; x++){
            multiply[i][x] = 0;
            for (int v = 0; v < SIZE; v++){
                //a11*b11 + a12*b21 + a13*b31...
                //a21*b21 + a21*b21...
                multiply[i][x] = (multiply[i][x] + (matrix1[i][v]*matrix2[v][x]));
            }
        }
    }
}

//Transpose matrix function with transpose array global variable
int transpose[SIZE][SIZE2];
void transposeMatrix(int matrix1[SIZE][SIZE2]){
    for (int i = 0; i < SIZE; i++){
        for (int x = 0; x < SIZE2; x++){
            //Switch rows and columns in matrix
            int temp_value = matrix1[i][x];
            transpose[x][i] = temp_value;
        }
    }
}

//Formatting of printing matrices
int printMatrix(int matrix1[SIZE][SIZE2]){
    printf("\n");
    for (int i = 0; i < SIZE; i++){
        for (int x = 0; x < SIZE2; x ++){
            printf("%d", matrix1[i][x]);
            printf("\t");
        }
        printf("\n");
    }
}


int main() {
    
    //Example array m1
    int m1[SIZE][SIZE2] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    //Example array m2
    int m2[SIZE][SIZE2] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    
    //Functions Called
    addMatrices(m1, m2);
    multiplyMatrices(m2, m1);
    transposeMatrix(m1);
    
//Printing section
    //Matrices Added
    if (SIZE == SIZE2){  //If cols and rows of 1 match 2, add
        printf("Matrices added: ");
        addMatrices(m1, m2);
        printMatrix(added);
        printf("\n");
        printf("\n");
    }
    else{
        printf("Matrices cannot be added. Incompatible sizes");
        printf("\n");
    }
    
    //Matrices Multiplied
    if (SIZE2 == SIZE){  //If columns of 1 == rows of 2, multiply
        multiplyMatrices(m2, m1);
        printf("Matrices multiplied: ");
        printMatrix(multiply);
        printf("\n");
        printf("\n");
    }
    else{
        printf("Matrices cannot be multiplied. Incompatible sizes");
        printf("\n");
    }
    
    //Matrix 1 transposed
    printf("Matrices 1 transposed: ");
    transposeMatrix(m1);
    printMatrix(transpose);
    printf("\n");
    printf("\n");

    //Matrix 2 transposed
    printf("Matrices 2 transposed: ");
    transposeMatrix(m2);
    printMatrix(transpose);
    printf("\n");
    printf("\n");

    return 0;
}