#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
struct node *create(int, char *, int);
void insertion(int, char *, int);
void searching(int);
void deletion(int);
int checking(int);

struct hash *hashTable = NULL;
int SizeOfTable = 0;

struct node{
    int rollNo;
    char name[MAX];
    int age;
    struct node *next;
};

struct hash{
    struct node *head;
};

struct node *create(int rollNo, char *name, int age){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

void insertion(int rollNo, char *name, int age){
    int hashIndex = rollNo % SizeOfTable;
    struct node *newNode = create(rollNo, name, age);
    if(!hashTable[hashIndex].head){
        hashTable[hashIndex].head = newNode;
    }
    else{
        struct node *p;
        p = hashTable[hashIndex].head;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = newNode;
    }
}

void searching(int rollNo){
    int i;
    struct node *q;
    int hashIndex = rollNo % SizeOfTable;
    q = hashTable[hashIndex].head;
    
    if(q){
        while(q->rollNo!=rollNo){
        q = q->next;
        if(q == NULL){
            printf("Roll number does not exist\n");
            break;
        }
    }
        if(q){
            printf("\nDetails:\n");
            printf("Roll No: %d\n", q->rollNo);
            printf("Name: %s\n", q->name);
            printf("Age: %d\n", q->age);
        }}
    else{
        printf("Roll number does not exist\n");
    }
}

void deletion(int rollNo){
    int hashIndex = rollNo % SizeOfTable;
    if(hashTable[hashIndex].head == NULL){
        printf("Roll number does not exist\n");
    }
    else if(hashTable[hashIndex].head->rollNo == rollNo){
        struct node *r = hashTable[hashIndex].head;
        hashTable[hashIndex].head = hashTable[hashIndex].head->next;
        free(r);
        printf("Element deleted successfully\n");
    }
    else{
        struct node *t = hashTable[hashIndex].head;
        while((t->next) && (t->next->rollNo!=rollNo)){
            t=t->next;
        }
        if((t->next) && (t->next->rollNo == rollNo)){
            struct node *u = t->next;
            t->next = t->next->next;
            free(u);
            printf("Element deleted successfully\n");
        }
        else{
            printf("Element does not exist\n");
        }
    }
}

int checking(int rollNo){
    struct node *v;
    int hashIndex = rollNo % SizeOfTable;
    v = hashTable[hashIndex].head;
    if(v){
        while(v->rollNo!=rollNo){
            v = v->next;
            if(v == NULL){
                return 1;
            }
            if(v->rollNo == rollNo){
                printf("Roll No already exists!!!Enter again\n");
                return -1;
            }
        }
        if(v->rollNo == rollNo){
            printf("Roll No already exists!!!Enter again\n");
            return -1;
        }
    }
}

void main(){
    int choice, rollNo, age, size, check;
    char name[MAX], ch;
    
    printf("Enter the size of hash table\n");
    scanf("%d", &size);
    SizeOfTable = size;
    hashTable = (struct hash *) calloc(SizeOfTable, sizeof(struct hash));
    
    do{
    printf("\nOperations on chaining in Hashing\n");
    printf("1-Insertion\n");
    printf("2-Searching\n");
    printf("3-Deletion\n");
    printf("Enter your choice(1-3)\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter roll No.\n");
            ENTERAGAIN:
            scanf("%d", &rollNo);
            check = checking(rollNo);
            if(check == -1){
                goto ENTERAGAIN;
            }
            getchar();   
            //This getchar above consumes one extra lines which
            //might be printed somewhere. This problem is similar
            //to giving one extra space in %c while reading a character.
            //Link you every time in do-while loop while asking for:
            //Do you want to continue or not.
            printf("Enter Name\n");
            fgets(name, MAX, stdin);
            name[strlen(name)-1] = '\0';
            printf("Enter age\n");
            scanf("%d", &age);
            insertion(rollNo, name, age);
            printf("Element inserted successfully\n");
            break;
            
        case 2:
            printf("Enter roll No.you want to search\n");
            scanf("%d", &rollNo);
            searching(rollNo);
            break;
        case 3:
            printf("Enter roll No.you want to delete\n");
            scanf("%d", &rollNo);
            deletion(rollNo);
            break;
        default:
            printf("Wrong choice\n");
            break;
    }
    printf("\nDo you want to continue(y or n): ");
    scanf(" %c", &ch);
    }while(ch =='y'||ch =='Y');
}