#include<stdio.h>
#include<math.h>
void main(){
    int number, originalNumber,reminder, result=0, n = 0;
    printf("Enter number\n");
    scanf("%d",&originalNumber);
    number = originalNumber;
    while(number!=0){
        number/=10;
        n++;
    }
    number = originalNumber;
    while(number!=0){
        reminder = number % 10;
        result+=(int)pow(reminder, n);
        number/=10;
    }
    (originalNumber==result)?printf("Armstrong Number\n"):printf("Not an Armstrong Number\n");
}