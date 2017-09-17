#include<stdio.h>
void concatenate(char s[], char t[]){
    int i = 0;
    while(s[i]!='\0'){
        i++;
    }
    int j = 0;
    while((s[i++] = t[j++])!='\0');
    printf("String after concatenation = %s", s);
}
void main(){
    char s[] = "Gaurav", t[] = " Claudia";
    concatenate(s,t);
}