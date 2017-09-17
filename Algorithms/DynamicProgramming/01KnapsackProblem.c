#include<stdio.h>
#include<math.h>

#define MAX 50

void insertKnapsack();
void computeKnapsack(int, int);

struct knapsack{
    int profit;
    int weight;
};
struct knapsack object[MAX];

void insertKnapsack(){
    int i;
    int NoOfObjects, capacity;
    printf("How many objects you want to enter(Max 50)\n");
    scanf("%d", &NoOfObjects);
    printf("Enter the capacity of bag\n");
    scanf("%d", &capacity);
    
    for(i = 1; i<=NoOfObjects; i++){
    printf("Enter profit then weight of Object %d: ",i);
    scanf("%d %d", &object[i].profit, &object[i].weight);
    }
    computeKnapsack(NoOfObjects, capacity);
}

void computeKnapsack(int NoOfObjects, int capacity){
    int outputTable[NoOfObjects+1][capacity+1], i, j;
    for(i = 0; i<=capacity; i++){
        outputTable[0][i] = 0;
    }
    for(i = 0; i<=NoOfObjects; i++){
        outputTable[i][0] = 0;
    }
    for(i = 1; i<=NoOfObjects; i++){
        for(j = 1; j<=capacity; j++){
            if((object[i].weight <= j) && ((outputTable[i-1][j-object[i].weight] + object[i].profit) > outputTable[i-1][j])){
                outputTable[i][j] = (outputTable[i-1][j-object[i].weight] + object[i].profit);
            }
            else{
                outputTable[i][j] = outputTable[i-1][j];
            }
        }
    }
    printf("Maximum profit = %d", outputTable[NoOfObjects][capacity]);
}

void main(){
    insertKnapsack();
}