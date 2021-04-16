
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct CircularQueue {
    struct Node *front;
    struct Node *rear;
    int size;
};

struct CircularQueue* createCircularQueue(){
    struct CircularQueue *queue = (struct CircularQueue *) malloc(sizeof(struct CircularQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(struct CircularQueue *queue, int data){
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    /*Check if the queue is empty or not */
    if(queue->front == NULL){
        queue->front = newnode;
        queue->rear = newnode;
        newnode->next = newnode;
        queue->size++;
        return;
    }
    queue->rear->next = newnode;
    queue->rear = newnode;
    newnode->next = queue->front;
    queue->size++;
}

int dequeue(struct CircularQueue *queue){
    /*Check whether the queue is empty or not*/
    if(queue->front == NULL){
        printf("The Queue is empty\n");
        return INT_MIN;
    }
    /*When the queue has single element*/
    if(queue->front == queue->rear){
        int del = queue->front->data;
        queue->front = NULL;
        queue->rear = NULL;
        queue->size--;
        return del;
    }
    /*Other case*/
    int item = queue->front->data;
    queue->front = queue->front->next;
    queue->rear->next = queue->front;
    queue->size--;
    return item;
}

int frontNode(struct CircularQueue *queue){
    if(queue->front == NULL){
        printf("The queue is empty\n");
        return INT_MIN;
    }
    return queue->front->data;
}

int rearNode(struct CircularQueue *queue){
    if(queue->rear == NULL){
        printf("The queue is empty\n");
        return INT_MIN;
    }
    return queue->rear->data;
}

void printQueue(struct CircularQueue *queue){
    struct Node *temp = queue->front;
    int size = queue->size;
    printf("The Circular Queue is:\n");
    while(size-->0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    struct CircularQueue *queue = createCircularQueue();

    int n, data;

    while(1){

        printf("Insert an item to queue(1)\n");
        printf("Remove item from queue(2)\n");
        printf("Retrieve the front item from stack(3)\n");
        printf("Retrieve theL last item from stack(4)\n");
        printf("Exit(0)\n");

        scanf("%d", &n);

        switch(n){
            case 1:
                printf("Enter an item: ");
                scanf("%d", &data);
                enqueue(queue, data);
                printQueue(queue);
                break;
            
            case 2:
                dequeue(queue);
                if(queue->front != NULL){
                    printQueue(queue);
                }
                break;

            case 3:
                printf("%d\n", frontNode(queue));
                break;

            case 4:
                printf("%d\n", rearNode(queue));
                break;

            case 0:
                exit(1);
        }
    }

    return 0;
}