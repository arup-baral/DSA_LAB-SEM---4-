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

void print(struct node *top){

    struct node *temp = top;

    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }

}

int main(){

    struct node *top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 56);
    push(&top, 17);
    push(&top, 56);
    push(&top, 48);

    print(top);
    printf("\n\n");

    pop(&top);
    printf("\n\n");
    print(top);
    printf("\n\n");
    printf("%d\n", peek(top));

    return 0;
}