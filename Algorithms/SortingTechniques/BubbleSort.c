#include<stdio.h>
void BubbleSort(int *, int);

void BubbleSort(int Array[], int size){
    int i, j ,k, count = 0, swapped;
    for(i = 0; i<size; i++){
        swapped = 0;
        for(j = 0; j<(size-1)-i; j++){
            if(Array[j]>Array[j+1]){
                int temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
                swapped = 1;
            }
        }
        if(swapped==0){
            break;
        }
        count++;
        printf("Array after iteration %d: ", count);
        for(k = 0; k<size; k++){
            printf("%d ",Array[k]);
        }
        printf("\n");
    }
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
    BubbleSort(array, size);
    printf("Final Sorted array\n");
    for(i=0; i<size; i++){
        printf("%d ", array[i]);
    }
}

/*Time Complexity
 Worst-case performance: O(n^2)
 Best-case performance:	 O(n)
 Average performance:	 O(n^2)*/
