#include<stdio.h>
#include<math.h>
#define MAX 50

struct jobs{
    int number;
    int profit;
    int deadline;
};
struct jobs jobNumber[MAX];

void Merging(int, int, int);
void SortingProfits(int, int);
int jobSequencing(struct jobs *, int, int);

void Merging(int first, int middle, int last){
    int n1 = middle - first + 1;
    int n2 = last - middle;
    int i, j, k;
    struct jobs left[n1+1], right[n2+1];
    for(i = 0; i<n1; i++){
        left[i] = jobNumber[first + i];
    }
    for(j = 0; j<n2; j++){
        right[j] = jobNumber[middle + j + 1];
    }
    left[n1].profit = -INFINITY;
    right[n2].profit = -INFINITY;
    i = 0;
    j = 0;
    for(k = first; k<last+1; k++){
        if(left[i].profit < right[j].profit){
            jobNumber[k] = right[j];
            j = j+1;
        }
        else{
            jobNumber[k] = left[i];
            i = i+1;
        }
    }
}

void SortingProfits(int first, int last){
    int middle;
    if(first < last){
        middle = (first + last)/2;
        SortingProfits(first, middle);
        SortingProfits(middle+1, last);
        Merging(first, middle, last);
    }
}

int jobSequencing(struct jobs array[], int MaximumDeadline, int difference){
    int i, j, maxProfit = 0;
    int k = MaximumDeadline + difference;
    for(i = 1; i<=k; i++){
        if(array[jobNumber[i-1].deadline].profit == -1){
            array[jobNumber[i-1].deadline] = jobNumber[i-1];
        }
        else{
            for(j = jobNumber[i-1].deadline - 1; j>=1; j--){
                if(array[j].profit == -1){
                    array[j] = jobNumber[i-1];
                    break;
                }
            }
        }
    }
    for(i = 1; i<=MaximumDeadline; i++){
        maxProfit = maxProfit + array[i].profit;
    }
    return maxProfit;
}

void main(){
    int n, i, MaximumDeadline = 0;
    printf("How many jobs you want to check: ");
    scanf("%d", &n);    
    for(i = 0; i<n; i++){
        jobNumber[i].number = i+1;
        printf("Enter profit then deadline of Job%d: ", i+1);
        scanf("%d %d", &jobNumber[i].profit, &jobNumber[i].deadline);
        
        if(MaximumDeadline < jobNumber[i].deadline){
            MaximumDeadline = jobNumber[i].deadline;
        }
    }
    
    int first = 0, last = n-1;
    SortingProfits(first, last);
    
    int difference = n - MaximumDeadline;
    
    struct jobs array[MaximumDeadline];
    for(i = 1; i<=MaximumDeadline; i++){
        array[i].profit = -1;
    }
    int maximumProfit = jobSequencing(array, MaximumDeadline, difference);
    
    printf("\nJob Sequence = ");
    for(i = 1; i<MaximumDeadline; i++){
        printf("Job%d->", array[i].number);
    }
    printf("Job%d\n", array[MaximumDeadline].number);
    printf("Maximum Profit = %d", maximumProfit);
}