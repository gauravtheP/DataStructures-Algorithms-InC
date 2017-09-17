#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int NoOfVertices, NoOfEdges;
int whiteSet[MAX], greySet[MAX], blackSet[MAX], flag = 0;

struct node{
    int vertex;
    struct node *next;
};
void create();
void insert(int, int);
void DFS(int);
void checking();

struct node *adjArr[MAX], *n;   //array of pointer acts as a head of link

/*Checking for acyclic graph Using DFS in directed graph.*/


/*creation of adjacency list starts here*/

void create(){
    int i, v1, v2;
    printf("Checking for cycle in a Graph\n\n");
    printf("Enter the number of vertices(Max 20)\n");
    scanf("%d", &NoOfVertices);
    
    for(i = 1; i<=NoOfVertices; i++){
        adjArr[i] = NULL;
    }
    
    printf("Enter the number of edges\n");
    scanf("%d", &NoOfEdges);
    
    for(i = 1; i<=NoOfEdges; i++){
    ENTERAGAIN:
    printf("Enter an edge starting from 1 (u to v) in format(u v): ");
    scanf("%d %d",&v1, &v2);
    if(v1>NoOfVertices || v2>NoOfVertices || v1 == v2){
        printf("Invalid Entry!!!\n");
        goto ENTERAGAIN;
    }
    else{
    insert(v1, v2);
    }
    /*in case of directed graph insert() function will be called only 
      once*/
    }
}

void insert(int v1, int v2){
    struct node *newNode; 
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vertex = v2;
    newNode->next = NULL;
    if(adjArr[v1]==NULL){
        adjArr[v1] = newNode;
    }
    else{
        n = adjArr[v1];
        while(n->next!=NULL){
            n = n->next;
        }
        n->next = newNode;
    }
}
/*creation of adjacency list ends here*/

/*Checking for acyclic starts*/

void DFS(int v){
    struct node *s;
    int u;
    u = v;
    s = adjArr[u];
    
    if(blackSet[u] == 1){
         return;
     }
    
    if(greySet[u] == 1){
        flag = 1;
        return;
    }
    else{
        whiteSet[u] = 0;
        greySet[u] = 1;
    }

    if(s == NULL){
        greySet[u] = 0;
        blackSet[u] = 1;
        
    }
    else{
        while(s->next!=NULL){
        if(whiteSet[s->vertex] == 1){
            DFS(s->vertex);
            greySet[u] = 0;
            blackSet[u] = 1;
        }
        else if(greySet[s->vertex] == 1){
            flag = 1;
            return;
        }
        s = s->next;
        }
        if(whiteSet[s->vertex] == 1){
            DFS(s->vertex);
            greySet[u] = 0;
            blackSet[u] = 1;
        }
        else if(greySet[s->vertex] == 1){
            flag = 1;
            return;
        }
    }
}
/*Above DFS is modified to suit the requirement of the goal of the program*/
void checking(){
    int i;
    
    for(i = 1; i<=NoOfVertices; i++){
        whiteSet[i] = 1;
        greySet[i] = 0;
        blackSet[i] = 0;
    }
    for(i = 1; i<=NoOfVertices; i++){
        if(whiteSet[i]==1){
          DFS(i);  
        }
    }
    
    if(flag==1){
        printf("\nThere is a cycle in the graph. Graph is not acyclic\n");
    }
    else{
        printf("\nGraph is acyclic\n");
    }
}

/*checking for acyclic ends here*/

void main(){
    create();
    checking();
}