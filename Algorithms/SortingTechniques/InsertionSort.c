#include<stdio.h>
void main(){
    int size,temp,i,j,k;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    int array[size];
    
    for(i=1;i<=size;i++){
        printf("Enter Array Elements: %d: ", i);
        scanf("%d", &array[i]);
    }
    
    for(j=2; j<=size; j++){
        temp = array[j];
        k = j-1;
        while(k>0 && array[k]>temp){
                array[k+1]=array[k];
                k--;
        }
        array[k+1]=temp;
    }
    printf("\nFinal Sorted array by Insertion sort is: ");
    for(i=1;i<=size;i++){
        printf("%d ", array[i]);
    }
}
/*Time Complexity
Worst-case performance: О(n^2)
Best-case performance:	O(n)
Average performance:	О(n^2)*/