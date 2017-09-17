#include<stdio.h>
#include<string.h>
void main(){
    char s[] = "Gaurav";
    
    printf("%s\n", s);
    //Here, above string 's' will be printed from the start.
    
    printf("%s\n", s+1);
    //Here, above string 's' will be printed from the second character.
    
    printf("%s\n", s+2);
    //Here, above string 's' will be printed from the third character.
    
    printf("%u\n", s);
    //Here, above address of first character of array 's' will be printed 
    
    printf("%u\n", s+1);
    //Here, above address of second character of array 's' will
    
    printf("%u\n", s+2);
    //Here, above address of third character of array 's' will
    
    printf("%c\n", *s);
    //Here, above first character of array 's' will be printed
    
    printf("%c\n", *(s+1));
    //Here, above second character of array 's' will be printed
    
    printf("%c\n", *(s+2));
    //Here, above third character of array 's' will be printed
    
    printf("%c\n", *(s+3));
    //Here, above fourth character of array 's' will be printed
}