#include<stdio.h>
#include<math.h>
void MergeSort(int *, int, int);
void Merging(int *, int, int, int);

void Merging(int array[], int first, int middle, int last){
    int n1 = middle - first + 1;
    int n2 = last - middle;
    int left[n1+1], right[n2+1], i, j, k;
    for(i = 0; i<n1; i++){
        left[i] = array[first + i];
    }
    for(j = 0; j<n2; j++){
        right[j] = array[middle + j + 1];
    }
    left[n1] = INFINITY;
    right[n2] = INFINITY;
    i = 0;
    j = 0;
    for(k = first; k<last+1; k++){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i = i+1;
        }
        else{
            array[k] = right[j];
            j = j+1;
        }
    }
}

void MergeSort(int array[], int first, int last){
    int middle;
    if(first < last){
        middle = (first + last)/2;
        MergeSort(array, first, middle);
        MergeSort(array, middle+1, last);
        Merging(array, first, middle, last);
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
    int first = 0, last = size-1;
    printf("Sorted Array: ");
    MergeSort(array, first, last);
    for(i = 0; i<size; i++){
        printf("%d ", array[i]);
    }
}

///*Time Complexity
//Worst-case performance:	O(n log n)
//Best-case performance:	O(n log n)
//Average performance:	O(n log n)*/
