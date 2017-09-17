#include<stdio.h>
int queue[5], front = 0, rear = 0, size = 0;

void enqueue(int data){
    rear = (rear+1)%5;
    if(rear == front){
        printf("Queue is Full\n");
    if(rear==0)
        rear = 5 - 1;
    }
    else{
        size++;
        queue[rear] = data;
    }
}

void dequeue(){
    if(front == rear){
        printf("Queue is Empty\n");
    }
    else{
        size--;
        front = (front+1)%5;
        int deleteItem = queue[front];
        printf("Deleted item = %d\n", deleteItem);
    }
}

int getSize(){
    return size;
}

void display(){
    int i, range;
    if(rear>=front){
    range = rear-front;
    printf("Elements in circular Queue = ");
    for(i = front; i<(front+range)-1; i++){
        printf("%d->",queue[i+1]);
    }
    printf("%d\n", queue[rear]);
    }
    else{
        int run = front - rear, loopEnd = 5-run, i, j;
        j =  front+1;
        printf("Elements in circular Queue = ");
        for(i = 1; i<loopEnd; i++){
            if(j==5){
                j = (j%5);
            }
            printf("%d->", queue[j]);
            j++;
        }
        printf("%d\n", queue[rear]);
    }
}

void main(){
    int data, choice;
    char ch;
    
    do{
    printf("MENU\n");
    printf("1-Pushing into Queue\n");
    printf("2-Popping from Queue\n");
    printf("3-Size of Queue\n");
    printf("4-Check empty\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter the number you want to push\n");
            scanf("%d", &data);
            enqueue(data);
            display();
            break;
            
        case 2:
            dequeue();
            display();
            break;
            
        case 3:
            printf("Size of Queue = %d\n",getSize());
            break;
            
        case 4:
            if(size==0){
                printf("Empty status: TRUE\n");
            }
            else{
                printf("Empty status: FALSE\n");
            }
            break;
            
        default:
            printf("Wrong choice\n");
            break;
    }
    printf("Do you want to continue(y or n)\n");
    scanf(" %c", &ch);
    }while(ch=='Y' || ch=='y');
}