#include <stdio.h>

void inputMatrix(int r, int c, int m[r][c]){
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            printf("Enter Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &m[i][j]);
        }
    }
}

void printMatrix(int r, int c, int m[r][c]){
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

void additionMatrix(int r, int c, int a[r][c], int b[r][c]){
    int result[r][c];
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }
        printf("Result Matrix (Addition):\n");
    printMatrix(r, c, result);
}

void subtractionMatrix(int r, int c, int a[r][c], int b[r][c]){
    int result[r][c];
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Result Matrix (Addition):\n");
    printMatrix(r, c, result);
}

void multiplyMatrix(int r1, int c1, int A[r1][c1], int r2, int c2, int B[r2][c2]){
    if (c1!=r2){
        printf("\nMatrix Multiplication Not Possible\n");
        return;
    }
    int result[r1][c2];
    for (int i = 0; i<r1; i++){
        for (int j = 0; j<c2; j++){
            result[i][j] = 0;
            for (int k = 0; k <c1; k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\nMultiplication Result:\n");
    printMatrix(r1, c2, result);
}

int main(){
    int choice;
    printf("---------------Matrix Solver---------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Transpose\n");
    scanf("%d", &choice);

    if (choice==1 || choice == 2){
        int r, c;
        printf("Enter Row & Column: ");
        scanf("%d %d", &r, &c);

        int a[r][c], b[r][c];

        printf("Enter Matrix A:\n");
        inputMatrix(r, c, a);
        
        printf("Enter Matrix B:\n");
        inputMatrix(r, c, b);

        if (choice == 1){
            additionMatrix(r, c, a, b);
        } else {
            subtractionMatrix(r, c, a, b);
        }
    } else if (choice == 3){
        int r1, c1, r2, c2;
        printf("Enter Rows & Columns For Matrix A: ");
        scanf("%d %d", &r1, &c1);
        int A[r1][c1];
        printf("Enter Matrix A:\n");
        inputMatrix(r1, c1, A);

        printf("Enter Rows & Columns For Matrix B: ");
        scanf("%d %d", &r2, &c2);
        int B[r2][c2];
        printf("Enter Matrix B:\n");
        inputMatrix(r2, c2, B);
        multiplyMatrix(r1,c1,A,r2,c2,B);

    }
    return 0;
}