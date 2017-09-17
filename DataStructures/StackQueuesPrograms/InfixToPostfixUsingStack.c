#include<stdio.h>
#include<ctype.h>
char stack[20];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    if(top==-1){
        return -1;
    }
    else{
        return stack[top--];
    }
}
    
    int precedence(char x){
        if(x=='('){
            return 0;
        }
        if(x=='+' || x=='-'){
            return 1;
        }
        if(x=='*' || x=='/'){
            return 2;
        }
    }
    
    void main(){
        char expression[20];
        char *e, x;
        printf("Enter infix expression: ");
        scanf("%s", &expression);
        e = expression;
        printf("Equivalent postfix expression = ");
        while(*e!='\0'){
            if(isalnum(*e)) 
   /*above isalnum() function is an inbuilt function defined inside
    ctype.h. This function checks for alphabets and numbers. If given
    character is alphabet or number then it will return true else
    false*/
                printf("%c", *e);
            else if(*e=='(')
                push(*e);
            else if(*e==')')
                while((x=pop())!='('){
                    printf("%c", x);
                }
            else{
                while(precedence(stack[top])>=precedence(*e)){
                    printf("%c", pop());
                }
                push(*e);
            }
            e++;
            }
        while(top!=-1){
            printf("%c", pop());
        }
    }