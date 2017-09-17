#include<stdio.h>
#include<math.h>
#define MAX 5

void MATRIX_CHAIN(int *, int);
void matrixCreation();

int s[MAX][MAX], m[MAX][MAX];

void MATRIX_CHAIN(int p[], int length){
    int n = length - 1;
    int i, j, k, l, q;
    for(i = 1; i<=n; i++){
        m[i][i] = 0;
    }
    for(l = 2; l<=n; l++){
        for(i = 1; i<= n-l+1; i++){ 
            j = i + l - 1;
            m[i][j] = 111111;
            for(k = i; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void matrixCreation(){
    int noOfMatrices, d11 , d12, d21, d22;
    printf("How many matrices you want to multiply: ");
    scanf("%d", &noOfMatrices);
    
    int i, check, p[noOfMatrices+1];
    printf("Enter row and column of matrices in the order in which they will be multiplied.\n");
    printf("\nEnter row and column of first matrix (i*j) in the format (i j): ");
    
    ENTERAGAIN1:
    scanf("%d %d", &d11, &d12);
    check = d12;
    p[0] = d11;
    p[1] = d12;
    if(d11<1 || d12<1){
        printf("Row and column cannot be negative. Enter Again: ");
        goto ENTERAGAIN1;
    }
    for(i = 2; i<=noOfMatrices; i++){
    printf("Enter row and column of next matrix (i*j) in the format (i j): ");
    
    ENTERAGAIN2:
    scanf("%d %d", &d21, &d22);
    
    p[i] = d22;
    
    if(check!=d21){
        printf("Matrices are not compatible. Enter again: ");
        goto ENTERAGAIN2;
    }
    else{
        check = d22;
    }
    
    if(d21<1 || d22<1){
        printf("Row and column cannot be negative. Enter Again: ");
        goto ENTERAGAIN2;
    }
    }
    
    MATRIX_CHAIN(p, noOfMatrices+1);
    printf("\nNumber of multiplications for %d matrices at best = %d\n", noOfMatrices, m[1][noOfMatrices]);
    printf("Best split for multiplications for %d matrices = %d\n", noOfMatrices, s[1][noOfMatrices]);
}

void main(){
    matrixCreation();
}