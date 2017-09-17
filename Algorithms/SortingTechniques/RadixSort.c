#include<stdio.h>
void radixsort(int *, int);
int getMax(int *, int);
void countSort(int *, int, int);

int getMax(int array[], int n){
    int i;
    int max = array[0];
    for(i = 1; i<n; i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}

void countSort(int array[], int n, int exponent){
    int output[n], count[10], i;
    for(i = 0; i<10; i++){
        count[i] = 0;
    }
    
    for(i = 0; i<n; i++){
        count[(array[i]/exponent) % 10]++;
    }
    
    for(i = 1; i<10; i++){
         count[i] += count[i - 1];
    }
    
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exponent) % 10] - 1] = array[i];
        count[(array[i] / exponent) % 10]--;
    }
    
    for(i = 0; i<n; i++){
        array[i] = output[i];
    }
}

void radixSort(int array[], int n){
    int max = getMax(array, n);
    int exponent;
    for(exponent = 1; max/exponent > 0; exponent *= 10){
        countSort(array, n ,exponent);
    }
}

void main(){
    int n;
    printf("How many array elements you want to enter\n");
    scanf("%d", &n);
    int array[n], i;
    printf("Enter array elements\n");
    for(i = 0; i<n; i++){
        scanf("%d", &array[i]);
    }
    radixSort(array, n);
    printf("Sorted array elements = ");
    for(i = 0; i<n; i++){
        printf("%d ", array[i]);
    }
}

/*Time Complexity:
 O(n+b) where 'b' is the base*/