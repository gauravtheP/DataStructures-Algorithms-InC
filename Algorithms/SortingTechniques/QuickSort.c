#include<stdio.h>

void doQuickSort(int, int);
int Partition(int, int);

int array[];

void doQuickSort(int lowerIndex, int higherIndex) {
    if (lowerIndex < higherIndex) {
        int q;
        q = Partition(lowerIndex, higherIndex);
        doQuickSort(lowerIndex, q-1);
        doQuickSort(q + 1, higherIndex);
    }
}

     int Partition(int lowerIndex, int higherIndex){

        int i = lowerIndex - 1, j;
        for(j=lowerIndex; j<=higherIndex-1; j++) {
            if (array[j] <= array[higherIndex]) {
                i = i + 1;
                int temp1 = array[j];
                array[j] = array[i];
                array[i] = temp1;
            }
        }
        int temp2 = array[higherIndex];
        array[higherIndex] = array[i + 1];
        array[i + 1] = temp2;
        return i + 1;
    }

     void main() {
        int i, size;
        printf("Enter the size of array\n");
        scanf("%d", &size);
        printf("Enter array Elements\n");
        for(i=0; i<size; i++){
            scanf("%d", &array[i]);
        }
        doQuickSort(0, size - 1);

        printf("Sorted array elements are: ");
        for (i = 0; i < size; i++) {
            printf("%d ",array[i]);
        }
    }
//here above "pivot" element is the last element of array every time means
//array[higherIndex].
     
/*Time Complexity
Worst-case performance:	O(n^2)
Best-case performance:	O(n log n)
Average performance:	O(n log n)*/