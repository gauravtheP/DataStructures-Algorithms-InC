#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node *next;
    };
    int size = 0;
    struct node *head = NULL;
    
    void pushing(int data){
        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        if(newNode==NULL){
            printf("Memory Error\n");
        }
            if(head==NULL){
                size++;
                head = newNode;
                newNode->data = data;
                newNode->next = NULL;
            }
            else{
                size++;
                newNode->next=head;
                head = newNode;
                newNode->data = data;
            }
        }
    
    void popping(){
        if(size==0 || head==NULL){
            printf("Underflow\n");
        }
        if(size==1){
            struct node *p = head;
            head = NULL;
            printf("Popped item = %d\n", p->data);
            size--;
            free(p);
            printf("Stack is empty now\n");
        }
        if(size>1){
            struct node *p = head;
            head = head->next;
            printf("Popped item = %d\n", p->data);
            size--;
            free(p);
            display();
        }
    }
    
    int getSize(){
        return size;
    }
    void display(){
        if(size==0 || head==NULL){
                printf("Stack is Empty\n");
            }
            if(size>=1){
                struct node *t = head;
                printf("Stack = ");
                while(t->next!=NULL){
                    printf("%d<-", t->data);
                    t=t->next;
                }
                printf("%d\n", t->data);
            }
    }
    void main(){
    int data, choice;
    char ch;
    
    do{
    printf("MENU\n");
    printf("1-Pushing into stack\n");
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
            if(head==NULL || size==0){
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