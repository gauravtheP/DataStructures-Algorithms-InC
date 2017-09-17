#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int CheckingForSame[MAX];
struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL;
struct node *child, *parent;

void create(int);
struct node *insert(struct node*, int);
void inOrder(struct node*);
void preOrder(struct node*);
void postOrder(struct node*);
int CountingNodes(struct node *);
int CountingLeaves(struct node *);
int countingFullNodes(struct node *);
int heightOfTree(struct node *);
int CheckingCompleteBinary(struct node *);
int FindingMinimum(struct node *);
int FindingMaximum(struct node *);
void Deletion(struct node *, int);
void DeleteLeaf(struct node *, int);
void DeleteNodeWithTwoChild(struct node *, int);
void DeleteNodeWithOneChild(struct node *, int);
struct node *Searching(struct node *, int);

/*Creation of tree starts here*/
/*Here the elements smaller than the root is placed on the left of the 
 *root and the elements greater than the root is placed on the right of
 the root and so on.*/
void create(int NoOfElements){
    int i, j, element;
    for(i = 0; i<NoOfElements; i++){
        CheckingForSame[i] = -1;
    }
    for(i = 0; i<NoOfElements; i++){
        ENTERAGAIN:
        printf("Enter node %d (except -1): ", i+1);
        scanf("%d", &element);
        if(element == -1){
            printf("-1 is not allowed. Enter again\n");
            goto ENTERAGAIN;
        }
        CheckingForSame[i] = element;
        for(j = 0; j<i; j++){
        if(element == CheckingForSame[j]){
            printf("Same nodes are not allowed! Enter again\n");
            goto ENTERAGAIN;
        }
        }
        root = insert(root, element);
    }
}
struct node *insert(struct node *newNode, int element){
    if(newNode == NULL){
        newNode = (struct node *) malloc(sizeof(struct node));
        newNode->left = NULL;
        newNode->data = element;
        newNode->right = NULL;
    }
    else if(element < newNode->data){
        newNode->left = insert(newNode->left, element);
    }
    else{
        newNode->right = insert(newNode->right, element);
    }
    return newNode;
}
/*Creation of tree ends here*/

/*In order starts here*/
void inOrder(struct node *t){
    
    if(t){
    inOrder(t->left);
    printf("%d ", t->data);
    inOrder(t->right);
    }
}
/*In order ends here*/

/*Pre order ends here*/
void preOrder(struct node *t){
    
    if(t){
    printf("%d ", t->data);
    preOrder(t->left);
    preOrder(t->right);
    }
}
/*Pre order ends here*/

/*Post order ends here*/
void postOrder(struct node *t){
    
    if(t){
    postOrder(t->left);
    postOrder(t->right);
    printf("%d ", t->data);
    }
}
/*Post order ends here*/

/*counting the number of nodes starts here*/
int CountingNodes(struct node *t){
    if(t){
        int NodesOnLeft = CountingNodes(t->left);
        int NodesOnRight = CountingNodes(t->right);
        return (1+ NodesOnLeft + NodesOnRight);
    }
}
/*counting the number of nodes ends here*/

/*counting no of leaves & non-leaves starts here*/
int CountingLeaves(struct node *t){
    if(!t){
        return 0;
    }
    if(!t->left && !t->right){
        return 1;
    }
    else{
        return (CountingLeaves(t->left) + CountingLeaves(t->right));
    }
}

int CountingNonLeaves(struct node *t){
    if(!t){
        return 0;
    }
    if(!t->left && !t->right){
        return 0;
    }
    else{
        return (1 + CountingNonLeaves(t->left) + CountingNonLeaves(t->right));
    }
}
/*counting no of leaves & non-leaves starts here*/

/*counting number of full nodes starts here*/
int countingFullNodes(struct node *t){
     if(!t){
        return 0;
    }
    if(!t->left && !t->right){
        return 0;
    }
    else{
        return ((countingFullNodes(t->left)) + (countingFullNodes(t->right)) + ((t->left && t->right)?1:0));
    }
}
/*counting number of full nodes ends here*/

/*height of a tree starts here*/
int heightOfTree(struct node *t){
    if(!t){
        return 0;
    }
    if(!t->left && !t->right){
        return 0;
    }
    else{
       int l = heightOfTree(t->left);
       int r = heightOfTree(t->right);
        return (1 + ((l>r)?l:r));
    }
}
/*height of a tree ends here*/

/*Checking for complete binary tree starts here*/
int CheckingCompleteBinary(struct node *t){
    if(!t){
        return 0;
    }
    if(!t->left && !t->right){
        return 1;
    }
    if(t->left && t->right){
        return ((CheckingCompleteBinary(t->left)) && (CheckingCompleteBinary(t->right)));
    }
    else{
        return 0;
    }
}
/*Checking for complete binary tree ends here*/

/*Finding Max-Min Starts here*/
int FindingMinimum(struct node *t){
    if(t){
       while(t->left){
           t = t->left;
       } 
       return t->data;
    }
}

int FindingMaximum(struct node *t){
    if(t){
       while(t->right){
           t = t->right;
       } 
       return t->data;
    }
}
/*Finding Max-Min ends here*/

/*Deletion starts here*/
void Deletion(struct node *t, int NoOfElements){
    struct node *found;
    int i, flag = 0, DeletedElement;
    DELETEAGAIN:
    printf("Enter element to be deleted: ");
    scanf("%d", &DeletedElement);
    for(i = 0; i<NoOfElements; i++){
        if(DeletedElement == CheckingForSame[i]){
            flag = 1;
            CheckingForSame[i] = -1;
            break;
        }
    }
    if(flag == 0 || DeletedElement == -1){
        printf("Element does not exist. Enter again\n");
        goto DELETEAGAIN;
    }
        
    //Deletion by in order successor
    found = Searching(t, DeletedElement);
        
    if(!found->left && !found->right){
        DeleteLeaf(found, DeletedElement);
    }
    else if(found->left && found->right){
        DeleteNodeWithTwoChild(found, DeletedElement);
    }
    else{
        DeleteNodeWithOneChild(found, DeletedElement);
    }
    
}
void DeleteLeaf(struct node *found, int DeletedElement){
    if((parent->left) && (parent->left->data == found->data)){
        parent->left = NULL;
        printf("Element %d deleted successfully\n", DeletedElement);
    }
    else{
        parent->right = NULL;
        printf("Element %d deleted successfully\n", DeletedElement);
    }
}
void DeleteNodeWithTwoChild(struct node *found, int DeletedElement){
        parent = found;
        child = parent->right;
        while(child->left!= NULL){
            parent = child;
            child = child->left;
        }
        found->data = child->data;
        if(parent->left->data == child->data){
            parent->left = NULL;
            printf("Element %d deleted successfully\n", DeletedElement);
        }
        else{
            parent->right = NULL;
            printf("Element %d deleted successfully\n", DeletedElement);
        }
}
void DeleteNodeWithOneChild(struct node *found, int DeletedElement){
    parent = found;
    if(parent->right){
        child = parent->right;
    while(child->left!= NULL){
            parent = child;
            child = child->left;
        }
    found->data = child->data;
    if(parent->left && parent->left->data == child->data){
        parent->left = NULL;
        printf("Element %d deleted successfully\n", DeletedElement);
    }
    else{
        parent->right = child->right;
        child->right = NULL;
        printf("Element %d deleted successfully\n", DeletedElement);
    }
    }
    else{
        child = parent->left;
        while(child->right){
            parent = child;
            child= child->right;
        }
        found->data = child->data;
        if(parent->right && parent->right->data == child->data){
        parent->right = NULL;
        printf("Element %d deleted successfully\n", DeletedElement);
    }
        else{
            parent->left = child->left;
            child->left = NULL;
            printf("Element %d deleted successfully\n", DeletedElement);
        }
    }
}
    struct node *Searching(struct node *s, int DeletedElement){
        parent = s;
        child = s;
        while(child->data!= DeletedElement){
            parent = child;
            if(DeletedElement < child->data){
                child = parent->left;
            }
            else{
                child = parent->right;
            }
        }
        return child;
    }
/*Deletion ends here*/
    
void main(){
    int NoOfElements, choice, TotalNoOfNodes, NumberOfLeaves;
    int NumberOfNonLeaves, NumberOfFullNodes, CalHeightOfTree;
    int CheckingCompBinary, Minimum, Maximum;
    char ch;
    CREATEAGAIN:
    printf("Create tree\n");
    printf("How many nodes you want to enter in a tree: ");
    scanf("%d", &NoOfElements);
    if(NoOfElements<1){
        printf("\nNo of elements has to be greater than 0\n");
        goto CREATEAGAIN;
    }
    create(NoOfElements);
    do{
    printf("***********Tree Operations*************\n");
    printf("* 1-In Order Traversal                *\n");
    printf("* 2-Pre Order Traversal               *\n");
    printf("* 3-Post Order Traversal              *\n");
    printf("* 4-Counting total number of nodes    *\n");
    printf("* 5-Counting leaves and non-leaves    *\n");
    printf("* 6-Counting full nodes               *\n");
    printf("* 7-Height of a tree                  *\n");
    printf("* 8-Sorting tree nodes                *\n");
    printf("* 9-Checking for complete binary tree *\n");
    printf("* 10-Maximum and Minimum in a tree    *\n");
    printf("* 11-Deletion in a tree               *\n");
    printf("***************************************\n");
    printf("Enter your Choice(1 to 11): ");
    scanf("%d", &choice);
    printf("\n");
    switch(choice){
    case 1:
        printf("In Order: ");
        inOrder(root);
        break;
        
    case 2:
        printf("Pre Order: ");
        preOrder(root);
        break;
        
    case 3:
        printf("Post Order: ");
        postOrder(root);
        break;
        
    case 4:
        TotalNoOfNodes = CountingNodes(root);
        printf("Total Number of nodes in a tree = %d\n", TotalNoOfNodes);
        break;
        
    case 5:
        NumberOfLeaves = CountingLeaves(root);
        printf("Total number of leaves = %d\n", NumberOfLeaves);
        NumberOfNonLeaves = CountingNonLeaves(root);
        printf("Total number of Non Leaves = %d\n", NumberOfNonLeaves);
        break;
        
    case 6:
        NumberOfFullNodes = countingFullNodes(root);
        printf("Total number of full nodes = %d", NumberOfFullNodes);
        break;
        
    case 7:
        CalHeightOfTree = heightOfTree(root);
        printf("Height of a tree = %d", CalHeightOfTree);
        break;
    case 8:
        printf("Sorted tree nodes: ");
        inOrder(root);
        break;
        
    case 9:
        CheckingCompBinary = CheckingCompleteBinary(root);
        if(CheckingCompBinary == 1){
            printf("Tree is complete binary tree");
        }
        else{
            printf("Tree is not complete binary tree");
        }
        break;
        
    case 10:
        Minimum = FindingMinimum(root);
        printf("Minimum element in a tree = %d\n", Minimum);
        Maximum = FindingMaximum(root);
        printf("Maximum element in a tree = %d\n", Maximum);
        break;
        
    case 11:
        Deletion(root, NoOfElements);
        break;
        
    default:
        printf("Wrong Choice\n");
        break;
}
    printf("\nDo you want to continue(y or n): ");
    scanf(" %c", &ch);
    } while(ch == 'Y' || ch == 'y');
}