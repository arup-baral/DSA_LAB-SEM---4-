/**
 * 
 * Implement Stack using dynamic memory representations. 
 * In the representation, code the primitive stack functions. 
 * Add a display function to show the content of your stack after every operation.
 * 
 **/


#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

struct node {

    int data;
    struct node *next;

};

int size = 0;

bool isEmpty(struct node *top){

    return top == NULL;

}

void push(struct node **top_ref, int data){

    struct node* newnode = (struct node*) malloc(sizeof(struct node));

    newnode->data = data;

    newnode->next = *top_ref;
    *top_ref = newnode;

    size++;

}

int pop(struct node **top_ref){

    if(isEmpty(*top_ref)){
        printf("\nThe stack is empty\n");
        return INT_MIN;
    }

    struct node *temp = *top_ref;

    *top_ref = (*top_ref)->next;
    size--;

    return temp->data;

}

int peek(struct node *top){

    if(isEmpty(top)){
        printf("\nThe stack is empty\n");
        return INT_MIN;
    }

    return top->data;
}

void printStack(struct node *top){

    struct node *temp = top;

    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int main(){

    int n, data;

    struct node *top = NULL;

    while(1){

        printf("Push an item to stack(1)\n");
        printf("Pop item from stack(2)\n");
        printf("Peek the item from stack(3)\n");
        printf("Exit(0)\n");

        scanf("%d", &n);

        switch(n){
            case 1:
                printf("Enter an item: ");
                scanf("%d", &data);
                push(&top, data);
                printStack(top);
                break;
            
            case 2:
                pop(&top);
                printStack(top);
                break;

            case 3:
                printf("%d\n", peek(top));
                break;

            case 0:
                exit(1);
        }
    }

    return 0;
    
}