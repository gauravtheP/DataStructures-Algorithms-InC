#include<stdio.h>
void main(){
    int number, i, flag = 0;
    printf("Enter number\n");
    scanf("%d", &number);
    for(i = 2; i<=number/2; i++){
        if(number%i==0){
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("Number is Prime");
    }
    else{
        printf("Number is not prime");
    }
}