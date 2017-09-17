#include<stdio.h>
#include<math.h>

#define MAX 50

void SortingRatio(int, int);
void Merging(int, int, int);
float GreedyKnapsack(float, int);

struct knapsack{
    float profit;
    float weight;
    float ratio;
};
struct knapsack object[MAX];

void Merging(int first, int middle, int last){
    int n1 = middle - first + 1;
    int n2 = last - middle;
    int i, j, k;
    struct knapsack left[n1+1], right[n2+1];
    for(i = 0; i<n1; i++){
        left[i] = object[first + i];
    }
    for(j = 0; j<n2; j++){
        right[j] = object[middle + j + 1];
    }
    left[n1].ratio = -INFINITY;
    right[n2].ratio = -INFINITY;
    i = 0;
    j = 0;
    for(k = first; k<last+1; k++){
        if(left[i].ratio <= right[j].ratio){
            object[k] = right[j];
            j = j+1;
        }
        else{
            object[k] = left[i];
            i = i+1;
        }
    }
}

void SortingRatio(int first, int last){
    int middle;
    if(first < last){
        middle = (first + last)/2;
        SortingRatio(first, middle);
        SortingRatio(middle+1, last);
        Merging(first, middle, last);
    }
}
//Above is Merge Sorting which sorts full structure on the basis of 
//profit to weight ratio.

float GreedyKnapsack(float capacity, int NoOfObjects){
    float MaxProfit = 0;
    int i;
    for(i= 0; i<NoOfObjects; i++){
        if(capacity>0 && object[i].weight<=capacity){
            capacity = capacity - object[i].weight;
            MaxProfit = MaxProfit + object[i].profit;
        }
        else{
            break;
        }
    }
    if(capacity>0){
        MaxProfit = MaxProfit + (object[i].profit * (capacity/object[i].weight));
    }
    return MaxProfit;
}
void main(){
    int NoOfObjects, i;
    float capacity;
    printf("How many objects you want to enter(Max 50)\n");
    scanf("%d", &NoOfObjects);
    printf("Enter the capacity of bag\n");
    scanf("%f", &capacity);
    
    for(i = 0; i<NoOfObjects; i++){
    printf("Enter profit then weight of Object %d: ",i+1);
    scanf("%f %f", &object[i].profit, &object[i].weight);
    object[i].ratio = object[i].profit / object[i].weight;
    }
    int first = 0, last = NoOfObjects-1;
    
    SortingRatio(first, last);
    float MaximumProfit = GreedyKnapsack(capacity, NoOfObjects);
    printf("Maximum Profit = %0.2f", MaximumProfit);
}
/*Time Complexity: O(nlogn)*/