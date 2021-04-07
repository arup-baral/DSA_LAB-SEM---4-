/**
 * 
 * Implement a Queue using dynamic memory representation.
 * You should implement the two primitive operations, namely, insert and delete with proper guards. 
 * You should experiment with a set of insert and delete operations. 
 * Show the contents of your queue after each operation.
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
    int size;
};

struct Queue* create_new_queue(){
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void insert(struct Queue *queue, int data){
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if(queue->rear == NULL){
        queue->front = queue->rear = newnode;
        queue->size++;
        return;
    }
    queue->rear->next = newnode;
    queue->rear = newnode;
    queue->size++;
}

void delete(struct Queue *queue){
    if(queue->front == NULL){
        printf("The queue is empty.\n");
    }
    else if(queue->front == queue->rear){
        queue->front = queue->rear = NULL;
        queue->size--;
    }
    else{
        queue->front = queue->front->next;
        queue->size--;
    }
}

int front(struct Queue *queue){
    if(queue->front == NULL){
        printf("The queue is empty.\n");
        return INT_MIN;
    }
    return queue->front->data;
}

int rear(struct Queue *queue){
    if(queue->rear == NULL){
        printf("The queue is empty.\n");
        return INT_MIN;
    }
    return queue->rear->data;
}

void print_queue(struct Queue *queue){
    struct Node *temp = queue->front;
    printf("The queue is : \n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    struct Queue *queue = create_new_queue();

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
                insert(queue, data);
                print_queue(queue);
                break;
            
            case 2:
                delete(queue);
                if(queue->front != NULL){
                    print_queue(queue);
                }
                break;

            case 3:
                printf("%d\n", front(queue));
                break;

            case 4:
                printf("%d\n", rear(queue));
                break;

            case 0:
                exit(1);
        }
    }

    return 0;
}