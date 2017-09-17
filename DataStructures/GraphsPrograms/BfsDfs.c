#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int NoOfVertices, NoOfEdges, startingVertex;
int visited[MAX];

struct node{
    int vertex;
    struct node *next;
};
void create();
void insert(int, int);
void BFS(int);
void enqueue(int);
int dequeue();
int QEmpty();
void DFSArray();
void DFS(int);

struct node *adjArr[MAX], *n;   //array of pointer acts as a head of link
struct node *head = NULL;

/*Breadth First Search & Depth First search Using Adjacency list*/

/*creation of adjacency list starts here*/
void create(){
    int i, v1, v2;
    printf("Create Graph\n");
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
    if(v1>NoOfVertices || v2>NoOfVertices){
        printf("Invalid Entry!!!\n");
        goto ENTERAGAIN;
    }
    else{
    insert(v1, v2);
    insert(v2, v1);
    }
    /*above function is called two times because the number of nodes in 
     *adjacency list is 2 times the number of edges in case of 
     *undirected graph. However, in case of directed graph insert() 
     *function will be called only once as number of nodes here will
     *be equal to the number of edges.*/
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

/*BFS starts here*/

void BFS(int v){
    int i, u;
    for(i=1; i<=NoOfVertices; i++){
        visited[i] = 0;
    }
    visited[v] = 1;
    printf("BFS: ");
    printf("%d  ", v);
    u = v;
    do{
    n = adjArr[u];
    while(n->next!=NULL){
        if(visited[n->vertex]==0){
            enqueue(n->vertex);
            visited[n->vertex] = 1;
            printf("%d  ", n->vertex);
        }
            n = n->next;
        }
    if(visited[n->vertex]==0){
        enqueue(n->vertex);
        visited[n->vertex] = 1;
        printf("%d  ", n->vertex);
        }
    u = dequeue();
    }while(QEmpty() == -2);
}

void enqueue(int n){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if(head == NULL){
        head = newNode;
        newNode->vertex=n;
        newNode->next = NULL;
    }
    else{
        struct node *p;
        p = head;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = newNode;
        newNode->vertex = n;
        newNode->next = NULL;
    }
}

int dequeue(){
    int r;
    r = head->vertex;
    head = head->next;
    return r;
}

int QEmpty(){
    if(head==NULL){
    return -1;
    }
    else{
        return -2;
    }
}
/*BFS ends here*/

/*DFS Starts here*/
void DFSArray(){
int i;
    for(i=1; i<=NoOfVertices; i++){
        visited[i] = 0;
    }
}
void DFS(int v){
    struct node *s;
    int u;
    visited[v] = 1;
    printf("%d  ", v);
    u = v;
    s = adjArr[u];
    while(s->next!=NULL){
        if(visited[s->vertex] == 0){
            DFS(s->vertex);
        }
        s = s->next;
    }
    if(visited[s->vertex] == 0){
            DFS(s->vertex);
    }
}
/*DFS ends here*/

void main(){
    char ch;
    int choice;
    create();
    do{
    printf("\nMENU\n");
    printf("1- BFS\n");
    printf("2- DFS\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the starting node: ");
            scanf("%d", &startingVertex);
            BFS(startingVertex);
            break;
        case 2:
            DFSArray();
            printf("Enter the starting node: ");
            scanf("%d", &startingVertex);
            printf("DFS: ");
            DFS(startingVertex);
            break;
        default:
            printf("Wrong Choice\n");
            break;
    }
    printf("\nDo you want to continue(y or n): ");
    scanf(" %c", &ch);
    }while(ch=='Y' || ch=='y');
}