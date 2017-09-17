#include<stdio.h>
int stack[10000], top = -1, size = 0;

void pushing(int data){
    if(top == 10000-1){
        printf("Overflow\n");
    }
    else{
        size++;
        stack[++top] = data;
    }
}

void popping(){
    if(top==-1){
        printf("Underflow\n");
    }
    if(size==1){
        size--;
        int temp = stack[top--];
        printf("Deleted item = %d\n", temp);
        printf("Stack is Empty now\n");
    }
    if(size>1){
        size--;
        int temp = stack[top--];
        printf("Deleted item = %d\n", temp);
        display();
    }
}

int getSize(){
    return size;
}

void display(){
    int i;
    printf("Stack = ");
    for(i = 0; i<top; i++){
        printf("%d->", stack[i]);
    }
    printf("%d\n",stack[top]);
}

void main(){
int data, choice;
    char ch;
    
    do{
    printf("MENU\n");
    printf("1-Pushing into stack(maximum size of stack = 10000)\n");
    printf("2-Popping from stack\n");
    printf("3-Size of stack\n");
    printf("4-Check empty\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the number you want to push\n");
            scanf("%d", &data);
            pushing(data);
            display();
            break;
            
        case 2:
            popping();
            break;
            
        case 3:
            printf("Size of stack = %d\n",getSize());
            break;
            
        case 4:
            if(top==-1){
                printf("Empty status: TRUE\n");
            }
            else{
                printf("Empty status: FALSE\n");
            }
            break;
    }
    printf("Do you want to continue(y or n)\n");
    scanf(" %c", &ch);
    }while(ch=='Y' || ch=='y');
}