#include<stdio.h>
#include<string.h>
int compare(char *s, char *t){
    while(*s!='\0'){
        if(*s == *t){
            s++;
            t++;
        }
        else{
            return *s-*t;
        }
    }
    if(*t=='\0' && *s=='\0'){
        return 0;
        }
        else{
            return *s-*t;
        }
}

void main(){
    char firstName[] = "Gauravy", firstName2[] = "Gaurav";
    int result = compare(firstName, firstName2);
    printf("%d", result);
    printf("\n");
    if(result == 0){
        printf("Both the strings are same\n");
    }
    else{
        printf("Strings are not same");
    }
}