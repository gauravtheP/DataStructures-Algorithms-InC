#include<stdio.h>
void conversion(int n){
    char s[10];
    int i = 0, sign;
    if((sign = n)<0){
        n = -1*n;
    }
    do{
        s[i++] = n%10 + '0';
    }while((n/=10)>0);
    
    if(sign<0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[]){
    int i, j;
    for(i = 0; s[i]!='\0'; i++);
    for(j = i; j>=0; j--){
        printf("%c", s[j]);
    }
   
}
void main(){
    int n;
printf("Enter any number\n");
scanf("%d",&n);
conversion(n);
}