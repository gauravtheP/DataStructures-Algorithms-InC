#include<stdio.h>

void ShellSorting(int *, int);
void SortOldOnes(int *, int, int, int);

int size;

void SortOldOnes(int array[], int first, int last, int gap){
    
        if((first >= 0) && (array[first] > array[last])){
        int temp = array[first];
        array[first] = array[last];
        array[last] = temp;
        first--;
        last--;
        SortOldOnes(array, first, last, gap);
        }
    }

void ShellSorting(int array[], int x){
    int gap, front, end;
    
    front = 0;
    gap = x/2;
    end = gap;
    
    if(gap > 0){
        while(end <= size - 1){
            if(array[front] > array[end]){
                int temp = array[front];
                array[front] = array[end];
                array[end] = temp;
                
                if(front >= gap){
                    int last = front;
                    int first = last - gap;
                    SortOldOnes(array, first, last, gap);
                }
            }
            front++;
            end++;
        }
        x = gap;
        ShellSorting(array, x);
    }
}

void main(){
    int i;
    printf("How many array elements you want to sort\n");
    scanf("%d", &size);
    int array[size];
    for(i = 0; i<size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &array[i]);
    }
    int x = size;
    ShellSorting(array, x);
    
    printf("\nSorted array elements = ");
    for(i = 0; i<size; i++){
        printf("%d ", array[i]);
    }
}
/*Time Complexity:
 Worst-case performance: O(n^2)
 Best-case performance:  O(n log n
 Average performance:	 depends on gap sequence*/