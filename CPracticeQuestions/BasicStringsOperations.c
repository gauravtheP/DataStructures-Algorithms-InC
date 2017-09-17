#include<stdio.h>
#include<string.h>
void main(){
    char s[] = "abc", t[] = "def";
    strcat(s,t);
    printf("String after concatenation: %s\n",s);
    
    char s1[] = "ghi", t1[] = "jkl";
    strncat(s1,t1,2);
    printf("String after 2 characters concatenation: %s\n",s1);
    
    int comp1 = strcmp(s1,t1);
    printf("comparison: %d\n",comp1);
    
    int comp2 = strncmp(s1,t1,1);
    printf("comparison: %d\n",comp2);
    
    char s2[10]="", t2[] = "pqr";
    strcpy(s2,t2);
    printf("String after copying is: %s\n",s2);
    
    char s3[10]="", t3[] = "Gaurav";
    strncpy(s3,t3,2);
    printf("String after copying is: %s\n",s3);
    
    int length = strlen(t3);
    printf("Length of string t3 is= %d", length);
}