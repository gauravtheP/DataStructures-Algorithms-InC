#include<stdio.h>
void main(){
    int n, i, j ,k;
        printf("How many rows of star pattern you want to print\n");
        scanf("%d", &n);
        for(i = 1; i<=n*2; i+=2){
            for(j = 1; j<=((2*n)-i)/2; j++){
                printf(" ");
            }
            for(k=1; k<=i; k++) {
                printf("*");
            }
            printf("\n");
        }
    }