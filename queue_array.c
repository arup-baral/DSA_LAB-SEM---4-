/**
 * 
 * Implement a Queue using fixed memory representation.
 * You should implement the two primitive operations, namely, insert and delete with proper guards. 
 * You should experiment with a set of insert and delete operations. 
 * Show the contents of your queue after each operation.
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Structure of the Queue */
struct Queue {
    int front; // Stores the index of front element
    int rear; // Stores the index of last element
    unsigned capacity; // Capacity of the Queue
    int* array; // Array to store the elements
    int size; // Current size of the Queue
};

struct Queue* create_new_queue(unsigned capacity){
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = queue->capacity - 1;
    queue->array = (int *) malloc(queue->capacity * sizeof(int));
}

bool isEmpty(struct Queue* queue){
    return (queue->size == 0);
}

bool isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}

void insert(struct Queue* queue, int data){
    if(isFull(queue)){
        printf("The queue is full.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
    (queue->size)++;
}

int delete(struct Queue* queue){
    if(isEmpty(queue)){
        printf("The queue is empty.\n");
        return INT_MIN;
    }
    int deleted_item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    (queue->size)--;
    return deleted_item;
}

int Front(struct Queue* queue){
    if(isEmpty(queue)){
        printf("The queue is empty.\n");
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int Rear(struct Queue* queue){
    if(isEmpty(queue)){
        printf("The queue is empty.\n");
        return INT_MIN;
    }
    return queue->array[queue->rear];
}

void print_queue(struct Queue* queue){
    int temp = queue->front;
    int size = queue->size;
    printf("The queue is :\n");
    while(size-- != 0){
        printf("%d ", queue->array[temp++]);
    }
    printf("\n");
}

int main(){
    int len;
    printf("Enter the size of Queue: ");
    scanf("%d", &len);

    struct Queue *queue = create_new_queue(len);

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
                if(!isFull(queue)){
                    printf("Enter an item: ");
                    scanf("%d", &data);
                    insert(queue, data);
                }
                else{
                    printf("The queue is full.\n");
                }
                print_queue(queue);
                break;
            
            case 2:
                delete(queue);
                if(queue->size != 0){
                    print_queue(queue);
                }
                break;

            case 3:
                printf("%d\n", Front(queue));
                break;

            case 4:
                printf("%d\n", Rear(queue));
                break;

            case 0:
                exit(1);
        }
    }

    return 0;
}