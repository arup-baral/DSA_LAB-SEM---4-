/**
 * 
 * Implement a min-priority queue. Your program should contain all the
 * necessary functions like extract_min() and others.
 * 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct PriorityQueue {
    int size;
    int lastPosition;
    int* array;
};

struct PriorityQueue* createQueue(int size){
    struct PriorityQueue *queue = (struct PriorityQueue *) malloc(sizeof(struct PriorityQueue));
    queue->size = size;
    queue->lastPosition = -1;
    queue->array = (int *) malloc(queue->size * sizeof(int));
    return queue;
}

void swap(struct PriorityQueue *q, int parent, int child){
    int temp = q->array[parent];
    q->array[parent] = q->array[child];
    q->array[child] = temp;
}

void trickleUp(struct PriorityQueue *queue, int child){
    if(child==0){
        return;
    }
    int parent = (int) floor((child-1)/2);
    if(queue->array[parent] > queue->array[child]){
        swap(queue, parent, child);
        trickleUp(queue, parent);
    }
}

void trickleDown(struct PriorityQueue *queue, int parent){
    int left = (2*parent) + 1;
    int right = (2*parent) + 2;

    if(left==queue->lastPosition && queue->array[parent]>queue->array[left]){
        swap(queue, parent, left);
        return;
    }
    if(right==queue->lastPosition && queue->array[parent]>queue->array[right]){
        if(queue->array[right]<queue->array[left]){
            swap(queue, parent, right);
        }
        else{
            swap(queue, parent, left);
        }
        return;
    }
    if(left>=queue->lastPosition || right>=queue->lastPosition){
        return;
    }
    if(queue->array[left]<queue->array[right] && queue->array[parent]>queue->array[left]){
        swap(queue, parent, left);
        trickleDown(queue, left);
    }
    else if(queue->array[left]>queue->array[right] && queue->array[parent]>queue->array[right]){
        swap(queue, parent, right);
        trickleDown(queue, right);
    }
}

void insert(struct PriorityQueue *pq, int data){
    if(pq->lastPosition < pq->size - 1){
        pq->array[++pq->lastPosition] = data;
        trickleUp(pq, pq->lastPosition);
    }
}

void extract_min(struct PriorityQueue *pq){
    if(pq->lastPosition == -1){
        printf("The queue is empty.\n");
    }
    else{
        swap(pq, 0, pq->lastPosition--);
        trickleDown(pq, 0);
    }
}

int peek(struct PriorityQueue *pq){
    return (pq->lastPosition==-1) ? INT_MIN : pq->array[0];
}

void printQueue(struct PriorityQueue *q, int root){
    if(root > q->lastPosition){
        return;
    }
    int left = (2*root) + 1;
    int right = (2*root) + 2;
    printf("%d ", q->array[root]);
    printQueue(q, left);
    printQueue(q, right);
}

int main(){

    int size;
    printf("Enter the size of the Queue: ");
    scanf("%d", &size);

    struct PriorityQueue *queue = createQueue(size);

    int n, data;

    while(1){

        printf("Insert an item to queue(1)\n");
        printf("Extract minimum priority item from queue(2)\n");
        printf("Retrieve the minimum priority item from queue(3)\n");
        printf("Exit(0)\n");

        scanf("%d", &n);

        switch(n){
            case 1:
                printf("Enter an item: ");
                scanf("%d", &data);
                insert(queue, data);
                printQueue(queue, 0);
                printf("\n");
                break;
            
            case 2:
                extract_min(queue);
                if(queue->lastPosition != -1){
                    printQueue(queue, 0);
                    printf("\n");
                }
                break;

            case 3:
                printf("%d\n", peek(queue));
                break;

            case 0:
                exit(1);
        }
    }

    return 0;
}