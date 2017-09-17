#include<stdio.h>
char *squeeze(char *s, char c){
    int i, j;
    char *r = s;
    for(i=j=0; s[i]!='\0'; i++){
        if(s[i]!=c){
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
    return r;
}
void main(){
    char str[] = "Gaurav";
    char c;
    printf("Enter the character you want to delete from String\n");
    scanf("%c", &c);
    printf("String after squeezing = %s", squeeze(str, c));
}
