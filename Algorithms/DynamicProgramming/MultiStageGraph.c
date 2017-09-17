#include<stdio.h>
#include<math.h>
#define MAX 15

void costMatrixBuilding();
void computingShortestDistance();

int adjacencyMatrix[MAX][MAX], noOfVertices;

void computingShortestDistance(){
    int shortestDistanceArray[noOfVertices], i, j;
    
    for(i = 1; i<=noOfVertices; i++){
        shortestDistanceArray[i] = 10000;
    }
    shortestDistanceArray[noOfVertices] = 0;
    
    for(i = noOfVertices-1; i>=1; i--){
        for(j = i+1; j<=noOfVertices; j++){
          int distance = adjacencyMatrix[i][j] + shortestDistanceArray[j];
           if(shortestDistanceArray[i] > distance){
               shortestDistanceArray[i] = distance;
           }
        }
    }
    int vertex;
    printf("\nEnter the vertex from which you want to check the shortest distance to %d: ", noOfVertices);
    scanf("%d", &vertex);
    printf("\nShortest distance from vertex %d to vertex %d = ", vertex, noOfVertices);
    printf("%d", shortestDistanceArray[vertex]);
    printf("\n");
}

void costMatrixBuilding(){
    int i, j, v1, v2, edgeWeight, noOfEdges;
    printf("How many vertices you want to enter: ");
    scanf("%d", &noOfVertices);
    
    for(i = 1; i<=noOfVertices; i++){
        for(j = 1; j<=noOfVertices; j++){
            adjacencyMatrix[i][j] = 1111111;
        }
    }
    printf("How many edges you want to enter: ");
    scanf("%d", &noOfEdges);
    
    printf("First vertex of graph should be 1, otherwise, result will not be as expected.\n\n");
    for(i = 1; i<=noOfEdges; i++){
    printf("Enter first vertex number, second vertex number and weight of edge between them: ");
    ENTERAGAIN:
    scanf("%d %d %d", &v1, &v2, &edgeWeight);
    
    if(v1 > v2){
        printf("First vertex should be lesser than the second connecting vertex. Enter again!!!\n");
        goto ENTERAGAIN;
    }
    
    if(v1<1 || v2<1 || edgeWeight<1){
        printf("Vertex number or edge weight cannot be negative\n");
        goto ENTERAGAIN;
    }
    if(v1==v2){
        printf("Both the vertices cannot be same. Enter again!!!\n");
        goto ENTERAGAIN;
    }
    adjacencyMatrix[v1][v2] = edgeWeight;    
    }
}

void main(){
    costMatrixBuilding();
    computingShortestDistance();
}