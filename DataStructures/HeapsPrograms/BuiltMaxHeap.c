#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void createArrayTree();
void Max_Heapify(int *, int, int);
void Built_Heap(int *, int);

void createArrayTree(){
    int i, j, l, heapSize;
    int *array = (int *) calloc(MAX, sizeof(int));
    printf("How many array elements you want to enter(Max 50)\n");
    scanf("%d", &heapSize);
    
    printf("Enter array elements\n");
    for(i = 1; i<=heapSize; i++){
        scanf("%d", &array[i]);
    }
    
    Built_Heap(array, heapSize);
    printf("Heap: ");
    for(j = 1; j<=heapSize; j++){
        printf("%d ", array[j]);
    }
}

void Built_Heap(int array[], int heapSize){
    int i;
    for(i = heapSize/2; i>=1; i--){
        Max_Heapify(array, i, heapSize);
    }
}

void Max_Heapify(int array[], int i, int heapSize){
    
    int l = 2*i, r = ((2*i)+ 1);
    int largest;
    if(l<=heapSize && array[l] > array[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r<=heapSize && array[r]>array[largest]){
        largest = r;
    }
    if(largest!=i){
        int temp = array[largest];
        array[largest] = array[i];
        array[i] = temp;
        Max_Heapify(array, largest, heapSize);
    }
}

void main(){
    char ch;
    do{
    createArrayTree();
    printf("\nDo you want to continue(y or n): ");
    scanf(" %c", &ch);
    }while(ch =='y' || ch =='Y');
}

/*
 Time complexity: Max_Heapify = O(logn)
 Time complexity: Built_Heap = O(n)*/