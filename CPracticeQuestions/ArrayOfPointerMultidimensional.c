#include<stdio.h>
void main(){
    char *name[] = {"ravi", "ravindra", "ravindrababu"};
    printf("%s\n",*(name+1));
    printf("%s\n", *name+1);
    printf("%d\n",(*(name+2)+6));
    printf("%d\n",(*(name+2)+7));
    printf("%d\n",(*(name+2)+8));
    printf("%c\n", *(*(name+2)));
    printf("%c\n", *(*(name+2)+7));
    printf("%c\n", *(*(name+2)+8));
    printf("%c\n", *(*(name+1)+5));
    printf("%c\n", name[2][7]);
}