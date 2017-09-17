#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int NoOfVertices, NoOfEdges;
int indegreeArray[MAX];
int whiteSet[MAX], greySet[MAX], blackSet[MAX], flag = 0;
struct node{
    int vertex;
    struct node *next;
};
void create();
void insert(int, int);
void creatingInDegreeArray();
void checking();
void DFS(int);
void TSort();
void enqueue(int);
int dequeue();

struct node *adjArr[MAX], *n;   //array of pointer acts as a head of link
struct node *head = NULL;
/*Topological Sort Using Adjacency list*/

/*creation of adjacency list starts here*/
void create(){
    int i, v1, v2;
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
    }
    /*in case of directed graph insert() function will be called only 
     *once as number of nodes here will be equal to the number of edges.*/
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
void DFS(int x){
    struct node *p;
    int u;
    u = x;
    p = adjArr[u];
    
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

    if(p == NULL){
        greySet[u] = 0;
        blackSet[u] = 1;
        
    }
    else{
        while(p->next!=NULL){
        if(whiteSet[p->vertex] == 1){
            DFS(p->vertex);
            greySet[u] = 0;
            blackSet[u] = 1;
        }
        else if(greySet[p->vertex] == 1){
            flag = 1;
            return;
        }
        p = p->next;
        }
        if(whiteSet[p->vertex] == 1){
            DFS(p->vertex);
            greySet[u] = 0;
            blackSet[u] = 1;
        }
        else if(greySet[p->vertex] == 1){
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
    
    if(flag == 1){
        printf("\nThere is a cycle in the graph. Graph is not acyclic\n");
    }
    else{
        printf("\nTopological Sorting Order: ");
        TSort();
    }
}
/*checking for acyclic ends here*/

/*Sorting starts here*/
void creatingInDegreeArray(){
    int i;
    struct node *x;
    for(i = 1; i<=NoOfVertices; i++){
        indegreeArray[i] = 0;
    }
    for(i = 1;i<=NoOfVertices; i++){
        x = adjArr[i];
        if(x==NULL){
            i = i+1;
            x = adjArr[i];
        }
        if(i == (NoOfVertices+1)){
            break;
        }
        while(x->next!=NULL){
            indegreeArray[x->vertex]++;
            x=x->next;
        }
        indegreeArray[x->vertex]++;
    }
}

void TSort(){
    int i, popped;
    struct node *s;
    for(i = 1; i<=NoOfVertices; i++){
        if(indegreeArray[i] == 0){
            enqueue(i);
        }
    }
    while(head!=NULL){
    popped = dequeue();
    printf("%d ", popped);
    
    s = adjArr[popped];
    if(s == NULL){
        goto NULLCONDITION;
    }
    
    while(s->next!=NULL){
            indegreeArray[s->vertex]--;
            s = s->next;
        }
        indegreeArray[s->vertex]--;
        
        NULLCONDITION:
        indegreeArray[popped]--;
    }
    
    for(i = 1;i<=NoOfVertices; i++){
        if(indegreeArray[i]!= -1){
            TSort();
        }
    }
}

void enqueue(int v){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if(head == NULL){
        head = newNode;
        newNode->vertex = v;
        newNode->next = NULL;
    }
    else{
        struct node *f;
        f = head;
        while(f->next!=NULL){
            f = f->next;
        }
        f->next = newNode;
        newNode->vertex = v;
        newNode->next = NULL;
        f = NULL;
    }
}

int dequeue(){
    int r;
    r = head->vertex;
    if(head->next!= NULL){
        head = head->next;
    }
    else{
        head = NULL;
    }
    return r;
}

/*Sorting ends here*/

void main(){
    printf("Create Graph\n");
    create();
    creatingInDegreeArray();
    checking();
}