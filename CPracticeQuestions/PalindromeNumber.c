#include<stdio.h>
void main(){
    int number;
    printf("Enter the number for checking a palindrome number\n");
    scanf("%d", &number);
        int number2 = number;
        int reverse = 0;
            while (number!= 0) {
                reverse = reverse * 10;
                reverse = reverse + number % 10;
                number = number / 10;
            }
            printf("Original number entered is: %d\n",number2);
            printf("Reverse of a number is: %d\n",reverse);
            if(number2 == reverse){
                printf("Number is palindrome");
            }
            else{
                printf("Number is not palindrome");
            }
    }