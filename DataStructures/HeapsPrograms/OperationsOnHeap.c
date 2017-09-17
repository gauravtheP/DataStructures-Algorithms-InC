#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void Built_Heap();
void Max_Heapify(int);
int ExtractMax();
void Insert(int);
void increase(int, int);

int heapSize;
int array[MAX];

void Built_Heap(){
    int i;
    for(i = heapSize/2; i>=1; i--){
        Max_Heapify(i);
    }
}

void Max_Heapify(int i){
    
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
        Max_Heapify(largest);
    }
}

int ExtractMax(){
    int max;
    if(heapSize<1){
        printf("Heap Underflow\n");
    }
    max = array[1];
    array[1] = array[heapSize];
    heapSize--;
    Max_Heapify(1);
    return max;
}

void Insert(int newElement){
    heapSize++;
    int j = heapSize;
    array[j] = newElement;
        while((j>1) && (array[j]>array[j/2])){
            int temp = array[j];
            array[j] = array[j/2];
            array[j/2] = temp;
            j = j/2;
        }
  printf("Element inserted successfully\n");  
}
void increase(int newElement, int i){
    if(newElement<array[i]){
        printf("New value should be greater than the present value\n");
    }
    else{
        array[i] = newElement;
        while(i>1 && array[i]>array[i/2]){
            if(array[i]>array[i/2]){
            int temp = array[i];
            array[i] = array[i/2];
            array[i/2] = temp;
            i = i/2;
            }
        }
        printf("Element value changed successfully\n");
    }
}
void main(){
    char ch;
    int i, choice;
    int maximum, newElement, newElement1, position, newElement2, position2;
    
    printf("How many array elements you want to enter(Max 50)\n");
    scanf("%d", &heapSize);
    printf("Enter array elements\n");
    for(i = 1; i<=heapSize; i++){
        scanf("%d", &array[i]);
    }
    Built_Heap();
    
    do{
        printf("\n  Operations on Heap\n");
        printf("1-Print Max-Heap\n");
        printf("2-Extract maximum element\n");
        printf("3-Insert an element\n");
        printf("4-Increase the value of an element\n");
        printf("5-Decrease the value of an element\n");
        printf("Enter your choice(1 to 5): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Max Heap = ");
                for(i = 1; i<=heapSize; i++){
                    printf("%d ", array[i]);
                }
                break;
            case 2:
                maximum = ExtractMax();
                printf("Maximum  element = %d\n", maximum);    
                break;
            case 3:
                printf("Enter an element you want to insert: ");
                scanf("%d", &newElement);
                Insert(newElement);
                break;
            case 4:
                printf("Enter the new value\n");
                scanf("%d", &newElement1);
                printf("Enter the position where you want to change the value\n");
                scanf("%d", &position);
                increase(newElement1, position);  
                break;
            case 5:
                printf("Enter the new value\n");
                scanf("%d", &newElement2);
                printf("Enter the position where you want to change the value\n");
                scanf("%d", &position2);
                if(array[position2]<newElement2){
                    printf("New value should be less than the present value\n");
                }
                else{
                array[position2] = newElement2;
                Max_Heapify(position2);
                printf("Element value changed successfully\n");
                }
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    printf("\nDo you want to continue(y or n): ");
    scanf(" %c", &ch);
    }while(ch =='y' || ch =='Y');
}