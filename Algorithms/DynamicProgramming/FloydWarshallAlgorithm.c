#include<stdio.h>
#include<math.h>
#define MAX 15

void MatrixBuilding();
void floydWarshall();

int adjacencyOriginalMatrix[MAX][MAX], minEdgeWeightMatrix[MAX][MAX], noOfVertices;

void MatrixBuilding(){
    int i, j, v1, v2, edgeWeight, noOfEdges;
    printf("How many vertices you want to enter: ");
    scanf("%d", &noOfVertices);
    
    for(i = 1; i<=noOfVertices; i++){
            adjacencyOriginalMatrix[i][i] = 0;
            minEdgeWeightMatrix[i][i] = 0;
    }
    printf("How many edges you want to enter: ");
    scanf("%d", &noOfEdges);
    
    for(i = 1; i<=noOfEdges; i++){
    printf("Enter first vertex number, second vertex number and weight of edge between them: ");
    ENTERAGAIN:
    scanf("%d %d %d", &v1, &v2, &edgeWeight);
    if(v1<1 || v2<1){
        printf("Vertex number cannot be less than 1\n");
        goto ENTERAGAIN;
    }
    if(v1==v2){
        printf("Both the vertices cannot be same. Enter again!!!\n");
        goto ENTERAGAIN;
    }
    adjacencyOriginalMatrix[v1][v2] = edgeWeight;    
    adjacencyOriginalMatrix[v2][v1] = edgeWeight;
    }
}

void floydWarshall(){
    int i, j, k;
    for(k = 1; k<=noOfVertices; k++){
        for(i = 1; i<=noOfVertices; i++){
            for(j = 1; j<=noOfVertices; j++){
                int smallest = adjacencyOriginalMatrix[i][j];
                if(smallest > (adjacencyOriginalMatrix[i][k] + adjacencyOriginalMatrix[k][j])){
                   smallest = adjacencyOriginalMatrix[i][k] + adjacencyOriginalMatrix[k][j]; 
                }
                minEdgeWeightMatrix[i][j] = smallest;
                adjacencyOriginalMatrix[i][j] = minEdgeWeightMatrix[i][j];
            }
        }
    }
}

void main(){
    int i, j;
    MatrixBuilding();
    floydWarshall();
    printf("\nAll pair shortest path matrix:\n");
    for(i = 1; i<=noOfVertices; i++){
        for(j = 1; j<=noOfVertices; j++){
            printf("%d ", adjacencyOriginalMatrix[i][j]);
        }
        printf("\n");
    }
}