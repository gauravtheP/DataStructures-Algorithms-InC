#include<stdio.h>
void main(){
    int i, a[5];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    printf("Value of a[0] is: %d. Address of a[0] is: %u\n",a[0], a);
    printf("Value of a[1] is: %d. Address of a[1] is: %u\n",a[1], a+1);
    printf("Value of a[2] is: %d. Address of a[2] is: %u\n",a[2], a+2);
    printf("Value of a[3] is: %d. Address of a[3] is: %u\n",a[3], a+3);
    printf("Value of a[4] is: %d. Address of a[4] is: %u\n",a[4], a+4);
    printf("&a simply means address of a[0] itself: %u\n", &a); 
    //here above '&a' will simply show the address of first element which is
    //nothing but a[0] because as you know the name 'a' is just an array name
    //and no address is allocated to an array name 'a'.
    printf("*a simply means value of variable whose address is stored in a: %d\n", *a);
    printf("*a+1 simply means value of variable whose address is stored in a+1: %d\n", *(a+1)); 
    printf("*a+2 simply means value of variable whose address is stored in a+2: %d\n", *(a+2)); 
    printf("*a+3 simply means value of variable whose address is stored in a+3: %d\n", *(a+3)); 
    printf("*a+4 simply means value of variable whose address is stored in a+4: %d\n", *(a+4)); 
}