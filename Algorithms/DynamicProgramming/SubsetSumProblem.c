#include<stdio.h>

void computingSubsetSum(int, int *, int);

void computingSubsetSum(int n, int array[], int s){
    int i, j;
    int outputTable[n+1][s+1];
    outputTable[0][0] = 1;
    for(i = 1; i<=s; i++){
        outputTable[0][i] = 0;
    }
    for(i = 1; i<=n; i++){
        outputTable[i][0] = 1;
    }
    for(i = 1; i<=n; i++){
        for(j = 1; j<=s; j++){
            if(array[i] > j){
                outputTable[i][j] = outputTable[i-1][j];
            }
            else{
                outputTable[i][j] = (outputTable[i-1][j-array[i]] + outputTable[i-1][j]);
                if(outputTable[i][j] == 2){
                    outputTable[i][j]--;
                }
            }
        }
    }
    if(outputTable[n][s] == 1){
        printf("\nSum %d is possible among the elements entered\n", s);
    }
    else{
        printf("\nSum %d is not possible among the elements entered\n", s);
    }
}

void main(){
    int n, i, s;
    printf("*********Computing SubSet Sum Problem************\n");
    printf("How many elements you want to enter\n");
    scanf("%d", &n);
    int array[n];
    for(i = 1; i<=n; i++){
        printf("Enter elements %d: ", i);
        scanf("%d", &array[i]);
    }
    printf("Enter target sum: ");
    scanf("%d", &s);
    computingSubsetSum(n, array, s);
}