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

    printf("\n");

}

int main(){

    int len;

    printf("Enter the size of the stack: ");
    scanf("%d", &len);

    struct Stack* stack = newStack(len);

    int n, data;

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
                push(stack, data);
                printStack(stack);
                break;
            
            case 2:
                pop(stack);
                printStack(stack);
                break;

            case 3:
                printf("%d\n", peek(stack));
                break;

            case 0:
                exit(1);
        }
    }

    return 0;
    
}