#include<stdio.h>
#include<math.h>
#define MAX 15

void costMatrixBuilding();
void prerequisitesForMinHeap();
void Built_Heap();
void Min_Heapify(int);
void prims();
struct keyHeap Extract_Min();
void decreaseKey(int);

struct keyHeap{
    int keyNumber;
    int key;
    int parent;
}keyParentTable[MAX];

int adjacencyMatrix[MAX][MAX], noOfVertices, tempVertices, finalMinWeight = 0;

void costMatrixBuilding(){
    int i, j, v1, v2, edgeWeight, noOfEdges;
    printf("How many vertices you want to enter: ");
    scanf("%d", &noOfVertices);
    tempVertices = noOfVertices;
    
    for(i = 1; i<=noOfVertices; i++){
        for(j = 1; j<=noOfVertices; j++){
            adjacencyMatrix[i][j] = 0;
        }
    }
    printf("How many edges you want to enter: ");
    scanf("%d", &noOfEdges);
    
    for(i = 1; i<=noOfEdges; i++){
    printf("Enter first vertex number, second vertex number and weight of edge between them: ");
    ENTERAGAIN:
    scanf("%d %d %d", &v1, &v2, &edgeWeight);
    if(v1<1 || v2<1 || edgeWeight<1){
        printf("Vertex number and edge weight cannot be less than 1\n");
        goto ENTERAGAIN;
    }
    if(v1==v2){
        printf("Both the vertices cannot be same. Enter again!!!\n");
        goto ENTERAGAIN;
    }
    adjacencyMatrix[v1][v2] = edgeWeight;    
    adjacencyMatrix[v2][v1] = edgeWeight;
    }
    prerequisitesForMinHeap();
    prims();
}

void prerequisitesForMinHeap(){
    int i;
    for(i = 1; i<=noOfVertices; i++){
        keyParentTable[i].keyNumber = i;
        keyParentTable[i].key = INFINITY;
        keyParentTable[i].parent = 0;
    }
    keyParentTable[1].key = 0;
    Built_Heap();
}

void Built_Heap(){
    int i;
    for(i = noOfVertices/2; i>=1; i--){
        Min_Heapify(i);
    }
}

void Min_Heapify(int i){
    
    int l = 2*i, r = ((2*i)+ 1);
    int smallest;
    if(l<=tempVertices && keyParentTable[l].key < keyParentTable[i].key){
        smallest = l;
    }
    else{
        smallest = i;
    }
    if(r<=tempVertices && keyParentTable[r].key < keyParentTable[smallest].key){
        smallest = r;
    }
    if(smallest!=i){
        struct keyHeap temp = keyParentTable[smallest];
        keyParentTable[smallest] = keyParentTable[i];
        keyParentTable[i] = temp;
        Min_Heapify(smallest);
    }
}

void prims(){
    int i, j, adjacentVertexEdgeWeight, adjacentVertexNumber;
    printf("\nSequence-Weight\n");
    while(tempVertices>0){
        struct keyHeap minimum = Extract_Min();
        printf("%d-%d ", minimum.keyNumber, minimum.key);
        
        if(minimum.key!=INFINITY){
        finalMinWeight = finalMinWeight + minimum.key;
        }
        
        for(i = 1; i<=noOfVertices; i++){
            if(adjacencyMatrix[minimum.keyNumber][i]!=0){
                
                adjacentVertexNumber = i;
                adjacentVertexEdgeWeight = adjacencyMatrix[minimum.keyNumber][i];
                
                for(j = 1; j<=tempVertices; j++){
                    if(adjacentVertexNumber == keyParentTable[j].keyNumber){
                        if(keyParentTable[j].key > adjacentVertexEdgeWeight){
                            keyParentTable[j].key = adjacentVertexEdgeWeight;
                        }
                        keyParentTable[j].parent = minimum.keyNumber;
                        decreaseKey(j);
                        break;
                    }
                }
            }
        }
    }
}

struct keyHeap Extract_Min(){
    struct keyHeap min;
    if(tempVertices<1){
        printf("Heap Underflow");
    }
    else{
        min = keyParentTable[1];
        keyParentTable[1] = keyParentTable[tempVertices];
        tempVertices--;
        Min_Heapify(1);
    }
    return min;
}

void decreaseKey(int k){
    while(k>1 && keyParentTable[k].key < keyParentTable[k/2].key){
        struct keyHeap temp = keyParentTable[k];
        keyParentTable[k] = keyParentTable[k/2];
        keyParentTable[k/2] = temp;
        k = k/2;
    }
}

void main(){
    costMatrixBuilding();
    printf("\nTotal Minimum weight of Spanning tree = %d", finalMinWeight);
}