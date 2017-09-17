#include<stdio.h>
#include <stdlib.h>
#define MAX 50

int HuffmanCode();
void Min_Heapify(int, int);
void Built_Heap(int);
int Extract_Min(int);
void Insert(int);

struct node{
    int left;
    int right;
    int freq;
};
int array[MAX];
int NewSize1;

void Built_Heap(int Size){
    int i;
    for(i = Size/2; i>=1; i--){
        Min_Heapify(i, Size);
    }
}

void Min_Heapify(int i, int Size){
    
    int l = 2*i, r = ((2*i)+ 1);
    int smallest;
    if(l<=Size && array[l] < array[i]){
        smallest = l;
    }
    else{
        smallest = i;
    }
    if(r<=Size && array[r]<array[smallest]){
        smallest = r;
    }
    if(smallest!=i){
        int temp = array[smallest];
        array[smallest] = array[i];
        array[i] = temp;
        Min_Heapify(smallest, Size);
    }
}

int Extract_Min(int size){
    int min;
    if(size<1){
        printf("Heap Underflow");
    }
    else{
        min = array[1];
        array[1] = array[NewSize1];
        NewSize1 = NewSize1 - 1;
        Min_Heapify(1, NewSize1);
    }
    return min;
}

void Insert(int newElement){
    NewSize1++;
    int j = NewSize1;
    array[j] = newElement;
        while((j>1) && (array[j]<array[j/2])){
            int temp = array[j];
            array[j] = array[j/2];
            array[j/2] = temp;
            j = j/2;
        }
}

int HuffmanCode(){
    int i, j, heapSize;
    printf("How many characters you want to enter(Max 50)\n");
    scanf("%d", &heapSize);
    NewSize1 = heapSize;
    
    for(i = 1; i<=heapSize; i++){
        printf("Enter frequency of character %d: ", i);
        scanf("%d", &array[i]);
    }
    Built_Heap(heapSize);
    
    for(i = 1; i<heapSize; i++){
        struct node *z = (struct node *) malloc(sizeof(struct node));
        z->left = Extract_Min(heapSize);
        z->right = Extract_Min(heapSize);
        z->freq = z->left + z->right;
        Insert(z->freq);
    }
    return Extract_Min(heapSize);
}

void main(){
    int finalMerge = HuffmanCode();
    printf("\nFinal element = %d", finalMerge);
}