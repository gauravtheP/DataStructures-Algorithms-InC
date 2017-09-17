#include<stdio.h>
void countingSort(int *, int);

void countingSort(int array[], int n){
    int output[n], temp, range, smallest, largest, i, j, k, l, m, p, q;
    
    smallest = array[1];
    for(i = 2; i<=n; i++){
        if(smallest > array[i]){
            smallest = array[i];
        }
    }
    temp = smallest - 1;
    
    largest = array[1];
    for(j = 2; j<=n; j++){
        if(largest < array[j]){
            largest = array[j];
        }
    }
    
    range = (largest - smallest) + 1;
    
    int count[range];
    
    for(k = 1; k<=range; k++){
        count[k] = 0;
    }
    
    for(l = 1; l<=n; l++){
        count[array[l] - temp] = count[array[l] - temp] + 1;
    }
    
    for(p = 2; p<= range; p++){
        count[p] = count[p-1] + count[p];
    }
    
    for(m = n; m>=1; m--){
        output[count[array[m] - temp]] = array[m];
        count[array[m] - temp] = count[array[m] - temp] - 1;
    }
    
    printf("Sorted Array elements = ");
    for(q = 1; q<=n; q++){
        printf("%d ", output[q]);
    }
}

void main(){
    int n;
    printf("How many array elements you want to enter\n");
    scanf("%d", &n);
    int array[n], i, j;
    printf("Enter array elements\n");
    for(i = 1; i<=n; i++){
        scanf("%d", &array[i]);
    }
    countingSort(array, n);
}
/*Time Complexity:
  Best performance:   O(n+r)
  Average Performance:O(n+r)
  Worst Performance:  O(n^2)
 **here, 'r' is the range of numbers = largest - smallest + 1*/
