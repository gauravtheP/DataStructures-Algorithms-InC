#include<stdio.h>
void main(){
    int n,i;
        printf("How many Fibonacci Series numbers you want to print\n");
        scanf("%d", &n);
        int last = 0;
        int previous = 1;
        printf("Fibonacci Series is: %d   %d ",last, previous);
        for(i = 0; i<n-2; i++){
            int next = last+previous;
            printf("  %d", next);
            printf(" ");
            last = previous;
            previous = next;
        }
        printf("...");
    }