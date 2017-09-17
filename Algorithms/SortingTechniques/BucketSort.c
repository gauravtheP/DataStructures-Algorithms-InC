#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct node{
    float data;
    struct node *next;
};

struct buckets{
    int bucketNo;
    struct node *head;
};

void createBuckets();
void createNode();
void insert(struct node *);
void display();

struct buckets b[MAX];
int noOfElements;

void createBuckets(){
    int i;
    for(i = 0; i<10; i++){
        b[i].bucketNo = i;
        b[i].head = NULL;
    }
    createNode();
}

void createNode(){
    int i;
    float number;
    printf("How many elements you want to sort(Max 50): ");
    scanf("%d", &noOfElements);
    
    printf("Only floating point numbers are allowed\n");
    
    for(i = 0; i<noOfElements; i++){
        printf("Enter element %d: ", i+1);
        scanf("%f", &number);
        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        newNode->data = number;
        newNode->next = NULL;
        insert(newNode);
    }
}

void insert(struct node *newNode){
    int nodeToBucket;
    float data;
    data = newNode->data;
    nodeToBucket = 10 * data;
    struct node *p = b[nodeToBucket].head;
    
    if(!p){
    b[nodeToBucket].head = newNode;
    }
    
    else if(p->data > newNode->data){
        b[nodeToBucket].head = newNode;
        newNode->next = p;
    }
    //Above is insertion at the beginning
    
    else {
        struct node *q;
        q = p->next;
        
        while(p->next!=NULL){
            if(q->data < newNode->data){
                p = p->next;
                q = q->next;
            }
            else{
                break;
            }
        }
        p->next = newNode;
        newNode->next = q;
    }
}
//above is insertion at a position and insertion in the end

void display(){
    int i, j;
    struct node *p;
    for(i = 0; i<10; i++){
        p = b[i].head;
        while((p!=NULL) && (p->next!=NULL)){
        printf("%0.5f ", p->data);
        p = p->next;
    }
        if(p!=NULL){
       printf("%0.5f ", p->data); 
        }
    }
}

void main(){
    createBuckets();
    printf("\nSorted list: ");
    display();
}

/*Time Complexity:
 Best-case performance:    O(n)
 Average Performance:      O(n)
 Worst-case Performance:   O(n^2)*/