#include<stdio.h>
#include<string.h>
char *copying(char *s, char *t){
    char *r = s;
    while((*s++ = *t++)!='\0');
return r;
}

void main(){
    char firstName[] = "Ananta", firstName2[] = "Gaurav";
    printf("Value after copying is = %s\n", copying(firstName, firstName2));
    printf("Value of first character = %c", *copying(firstName, firstName2));
}