#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *previous;
    int data;
    struct node *next;
    };
    int size = 0;
    struct node *head = NULL;
    
    void insertAtBeginning(int data){
        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        size++;
            if(head==NULL){
                head = newNode;
                newNode->previous = NULL;
                newNode->data = data;
                newNode->next = NULL;
            }
            else{
                newNode->previous = NULL;
                newNode->next=head;
                head->previous = newNode;
                head = newNode;
                newNode->data = data;
            }
    }
    
    void insertAtPosition(int data, int position){
        if(position<1 || position>=size+2){
                printf("Invalid Position\n");
            }
            if(position==1){
                struct node *newNode = (struct node *) malloc(sizeof(struct node));
                size++;
                if(head==NULL){
                    head = newNode;
                    newNode->previous = NULL;
                    newNode->data = data;
                    newNode->next = NULL;
                }   
                else{
                    newNode->previous = NULL;
                    newNode->next=head;
                    head->previous = newNode;
                    head = newNode;
                    newNode->data = data;
                }
            }
            if(position>1 && position<=size){
                struct node *newNode = (struct node *) malloc(sizeof(struct node));
                size++;
                struct node *p;
                p = head;
                int i;
                for(i = 1;i<position-1;i++){
                    p=p->next;
                }
                struct node *t = p->next;
                p->next = newNode;
                newNode->previous = p;
                newNode->next = t;
                newNode->data = data;
                t->previous = newNode;
            }
        if(position==size+1){
            struct node *newNode = (struct node *) malloc(sizeof(struct node));
                size++;
                struct node *p;
                p = head;
                int i;
                for(i = 1;i<position-1;i++){
                    p=p->next;
                }
                p->next = newNode;
                newNode->previous = p;
                newNode->data = data;
                newNode->next = NULL;
        }
    }
    
    void insertAtEnd(int data){
        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        size++;
            if(head==NULL){
                head = newNode;
                newNode->previous = NULL;
                newNode->data = data;
                newNode->next = NULL;
            }
            else{
                struct node *p;
                p = head;
                while(p->next!=NULL){
                    p = p->next;
                }
                p->next = newNode;
                newNode->previous = p;
                newNode->data = data;
                newNode->next = NULL;
            }
    }
    
    void deleteAtPosition(int position){
        if(size==0){
                printf("List is already Empty\n");
            }
            if(position<0 || position>size){
                printf("Invalid Position\n");
            }
            if(position==0){
                printf("Invalid Position\n");
            }
            if(size==1){
                if(position==1){
                struct node *p = head;
                head = NULL;
                free(p);
                size--;
                printf("List is Empty now\n");
            }
            }
            if(size>1) {
                if (position == 1) {
                    struct node *p = head;
                    head = head->next;
                    head->previous = NULL;
                    free(p);
                    size--;
                    display();
                }
            }
            if(position>1 && position<size){
                struct node *p = head;
                int i;
                for(i = 1; i<position-1; i++){
                    p=p->next;
                }
                struct node *p1 = p->next->next;
                struct node *pd = p->next;
                p->next = p1;
                p1->previous = p;
                pd->previous = NULL;
                pd->next = NULL;
                free(pd);
                size--;
                display();
            }
        if(position==size){
            struct node *p = head;
                int i;
                for(i = 1; i<position-1; i++){
                    p=p->next;
                }
                struct node *p1 = p->next;
                p->next = NULL;
                p1->previous = NULL;
                free(p1);
                size--;
                display();
        }
    }
    
    void reverse(){
        struct node *p = head;
        int i;
        while(p->next){
            p=p->next;
        }
        struct node *temp;
        head = p;
        for(i=1; i<=size; i++){
            temp = p->previous;
            p->previous = p->next;
            p->next = temp;
            p = p->next;
        }
    }
    
    void displayReverse(){
        if(size==0){
            printf("List is Empty\n");
            }
        if(size>=1){
            struct node *t = head;
            while(t->next!=NULL){
                t = t->next;
            }
            printf("Linked List in REVERSE order = ");
            while(t->previous!=NULL){
                printf("%d->", t->data);
                t = t->previous;
            }
                printf("%d\n", t->data);
        }
    }
    
    void display(){
        if(size==0){
                printf("List is Empty\n");
            }
            if(size>=1){
                struct node *t = head;
                printf("Linked list = ");
                while(t->next!=NULL){
                    printf("%d->", t->data);
                    t=t->next;
                }
                printf("%d\n", t->data);
            }
    }
    
void main(){
    int data, position;
    int choice;
    char ch;
    
    do{
    printf("MENU\n");
    printf("1-Insert at the beginning\n");
    printf("2-Insert at a position\n");
    printf("3-Insert at the end\n");
    printf("4-Delete at a position\n");
    printf("5-Reversing a Linked List\n");
    printf("6-Displaying list in reverse order\n");
    printf("7-Size of a Linked List\n");
    printf("8-Check Empty\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the number you want to insert\n");
            scanf("%d", &data);
            insertAtBeginning(data);
            display();
            break;
        case 2:
            printf("Enter the position where you want to insert\n");
            scanf("%d", &position);
            printf("Enter the number you want to insert\n");
            scanf("%d", &data);
            insertAtPosition(data, position);
            display();
            break;
            
        case 3:
            printf("Enter the number you want to insert\n");
            scanf("%d", &data);
            insertAtEnd(data);
            display();
            break;
            
        case 4:
            printf("Enter Position where you want to delete a node\n");
            scanf("%d", &position);
            deleteAtPosition(position);
            break;
            
        case 5:
            reverse();
            display();
            break;
            
        case 6:
            displayReverse();
            break;
            
        case 7:
            printf("Size of Linked list = %d\n", size);
            break;
            
        case 8:
            if(head==NULL){
                printf("Empty status: TRUE\n");
            }
            else{
                printf("Empty status: FALSE\n");
            }
            break;
            
        default:
            printf("Wrong choice\n");
            break;
    }
    printf("Do you want to continue(Type y or n)\n");
    scanf(" %c",&ch); 
    }while (ch == 'Y' || ch == 'y');
}