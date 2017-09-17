#include<stdio.h>
void main(){
    char a[] = "Rock";
    char b[10];
    copying(b, a);
}
void copying(char *c, char *f){
    while(*c++ = *f++){
         printf("%c",*--c);
}
}