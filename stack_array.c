/**
 * 
 * Implement Stack using fixed memory representations. 
 * In the representation, code the primitive stack functions. 
 * Add a display function to show the content of your stack after every operation.
 * 
 **/



#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

/* Structure of the stack */
struct Stack{

    /* Top element of the stack */
    int top;

    /* Array to store the elements */
    int* array;

    /* Capacity/length of the stack */
    unsigned length;

};

/* Creating the stack */
struct Stack *newStack(unsigned len){

    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->length = len;
    stack->array = (int*) malloc(stack->length * sizeof(int));
    return stack;
}


/* Method to check the stack is empty or not */
bool isEmpty(struct Stack *stack){

    return stack->top == -1;

}

/* Method to check the stack is full or not */
bool isFull(struct Stack *stack){

    return stack->top == stack->length -1;

}

void push(struct Stack* stack, int data){

    if(isFull(stack)){
        printf("\nThe stack is already full\n");
        return;
    }
    
    stack->array[++stack->top] = data;

}

int pop(struct Stack* stack){

    int item = INT_MIN;

    if(isEmpty(stack)){
        printf("\nThe stack is empty\n");
    }
    else{
        item = stack->array[stack->top--];
    }

    return item;

}

int peek(struct Stack* stack){

    int item = INT_MIN;
    
    if(isEmpty(stack)){
        printf("\nThe stack is empty\n");
    }
    else{
        item = stack->array[stack->top];
    }

    return item;

}

void printStack(struct Stack* stack){

    int temp = stack->top;

    while(temp != -1){
        printf("%d\t", stack->array[temp]);
        temp--;
    }

}

int main(){

    struct Stack* stack = newStack(6);

    printf("%d\n", pop(stack));

    push(stack, 15);
    push(stack, 63);
    push(stack, 85);
    push(stack, 10);
    printStack(stack);
    printf("\n%d\n", peek(stack));
    printf("%d\n", pop(stack));
    printStack(stack);

    return 0;
    
}