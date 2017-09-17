#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct details{
    int rollNo;
    char name[MAX];
    int age;
};

struct studDetails{
    struct details data;
} HashTable[MAX];

int SizeOfTable;

int rehash(int, int);
void insertion(int, char *, int);
void searching(int);
void deletion(int);

//Here below we are recomputing the hash Value if there is a collision
int rehash(int key, int newM){
    int i, flag = 0;
        for(i = 2; i<=newM/2; i++){
        if(newM % i==0){
            flag = 1;
            break;
        }
    }
    if(flag==0){
        int newHashValue = newM - (key % newM);
        return newHashValue;
    }
    else{
        newM = newM-1;
        rehash(key, newM);
    }
}
//checking for prime starts here

void insertion(int rollNo, char *name, int age){
    int hashIndex1 = rollNo % SizeOfTable;
    if(HashTable[hashIndex1].data.rollNo == -121){
        HashTable[hashIndex1].data.rollNo = rollNo;
        strcpy(HashTable[hashIndex1].data.name, name);
        HashTable[hashIndex1].data.age = age;
    }
    else{
        int m = SizeOfTable - 1; 
        int hashIndex2 = rehash(rollNo, m);
        int hashIndex3 = (hashIndex1 + hashIndex2) % SizeOfTable;
        HashTable[hashIndex3].data.rollNo = rollNo;
        strcpy(HashTable[hashIndex3].data.name, name);
        HashTable[hashIndex3].data.age = age;
    }
}

void searching(int rollNo){
    int hashIndex1 = rollNo % SizeOfTable;
    int m = SizeOfTable - 1; 
    int hashIndex2 = rehash(rollNo, m);
    int hashIndex3 = (hashIndex1 + hashIndex2) % SizeOfTable;
    
    if(HashTable[hashIndex1].data.rollNo == rollNo){
        printf("Details:\n");
        printf("Roll No = %d\n", HashTable[hashIndex1].data.rollNo);
        printf("Name = %s\n", HashTable[hashIndex1].data.name);
        printf("Age = %d\n", HashTable[hashIndex1].data.age);
    }
    
    if(HashTable[hashIndex3].data.rollNo == rollNo){
        printf("Details:\n");
        printf("Roll No = %d\n", HashTable[hashIndex3].data.rollNo);
        printf("Name = %s\n", HashTable[hashIndex3].data.name);
        printf("Age = %d\n", HashTable[hashIndex3].data.age);
    }
    
    if((HashTable[hashIndex1].data.rollNo != rollNo) && (HashTable[hashIndex3].data.rollNo != rollNo)){
        printf("Roll No does not exist\n");
    }
}

int checking(int rollNo){
    int hashIndex1 = rollNo % SizeOfTable;
    if(HashTable[hashIndex1].data.rollNo == rollNo){
        printf("Roll Number already exists!!!Enter Again\n");
        return -1;
    }
    else{
        int m = SizeOfTable - 1; 
        int hashIndex2 = rehash(rollNo, m);
        int hashIndex3 = (hashIndex1 + hashIndex2) % SizeOfTable;
        if(HashTable[hashIndex3].data.rollNo == rollNo){
            printf("Roll Number already exists!!!Enter Again\n");
            return -1;
        }
    }
}
void main(){
    int choice, rollNo, age, size, i, check;
    char name[MAX], ch;
    printf("Enter the size of hash table\n");
    scanf("%d", &size);
    SizeOfTable = size;
    for(i = 0; i<SizeOfTable; i++){
        HashTable[i].data.rollNo = -121;
    }
    
    do{
    printf("\nOperations on chaining in Hashing\n");
    printf("1-Insertion\n");
    printf("2-Searching\n");
    printf("Enter your choice(1-2)\n");
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
        default:
            printf("Wrong choice\n");
            break;
    }
    printf("\nDo you want to continue(y or n): ");
    scanf(" %c", &ch);
    }while(ch =='y'||ch =='Y');
}