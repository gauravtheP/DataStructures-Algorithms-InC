#include<stdio.h>
void SelectionSort(int *, int);

void SelectionSort(int array[], int size){
    int i, j, k;
    for(i = 0; i<size; i++){
        for(j = i+1; j<size; j++){
            if(array[i]>array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("Sorted array list: ");
    for(i = 0; i<size-1; i++){
        printf("%d",array[i]);
        printf(", ");
    }
    printf("%d",array[size-1]);
}

void main(){
    int size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    
    int array[size], i;
    
    for(i=0; i<size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &array[i]);
    }
    SelectionSort(array, size);
}

/*Time Complexity of Selection Sort
 Worst-case performance: О(n^2)
 Best-case performance:	 О(n^2)
 Average performance:	 О(n^2)*/