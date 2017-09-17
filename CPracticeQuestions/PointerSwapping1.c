#include<stdio.h>
void main(){
    int a=5, b=9;
    swap(&a, &b);
    printf("Value of a after swapping is changed to %d\n", a);
    printf("Value of b after swapping is changed to %d\n", b);
}
int swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
