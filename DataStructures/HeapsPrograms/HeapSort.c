#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void HeapSorting(int *, int);
void Max_Heapify(int *, int, int);
void Built_Heap(int *, int);

void HeapSorting(int array[], int heapSize){
    int i;
    Built_Heap(array, heapSize);
    for(i = heapSize; i>=2; i--){
        int temp = array[heapSize];
        array[heapSize] = array[1];
        array[1] = temp;
        heapSize = heapSize - 1;
        Max_Heapify(array, 1, heapSize);
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
    int heapSize, i;
    printf("How many array elements you want to enter(Max 50)\n");
    scanf("%d", &heapSize);
    
    int *array = (int *) calloc(MAX, sizeof(int));
    printf("Enter array elements\n");
    for(i = 1; i<=heapSize; i++){
        scanf("%d", &array[i]);
    }
    HeapSorting(array, heapSize);
    printf("Sorted array elements: ");
    for(i = 1; i<=heapSize; i++){
        printf("%d ", array[i]);
    }
}