/**
 * 
 * Write a program for the Tower of Hanoi problem. 
 * Experiment with a varying number of discs. 
 * Show the intermediate moves in form of messages like the following:
 * Move disk ... from rod ... to rod ...
 *
 **/


/* Import necessary header files */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Stack {

    int top;

    unsigned capacity;

    int* array;

};

bool isEmpty(struct Stack* stack){

    return stack->top == -1;

}

bool isFull(struct Stack* stack){

    return stack->top == stack->capacity - 1;

}

struct Stack* create_new_stack(unsigned length){

    struct Stack* stack = (struct Stack *) malloc(sizeof(struct Stack));

    stack->top = -1;
    stack->capacity = length;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));

    return stack;

}

void push(struct Stack* stack, int data){

    if(isFull(stack)){

        printf("The stack is empty.\n");
        exit(1);

    }

    stack->array[++stack->top] = data;

}

int pop(struct Stack* stack){

    if(isEmpty(stack)){

        return INT_MIN;

    }

    return stack->array[stack->top--];

}

void printMoves(int disc, char s, char d){

    printf("Move %d no disc from %c to %c\n", disc, s, d);

}

void ethical_move(struct Stack *src, struct Stack *dst, char s, char d){

    int element_src = pop(src);
    int element_dst = pop(dst);

    if(element_dst == INT_MIN){

        push(dst, element_src);
        printMoves(element_src, s, d);

    }

    else if(element_src == INT_MIN){

        push(src, element_dst);
        printMoves(element_dst, d, s);

    }

    else if(element_dst > element_src){

        push(dst, element_dst);

        push(dst, element_src);
        printMoves(element_src, s, d);

    }

    else{

        push(src, element_src);

        push(src, element_dst);
        printMoves(element_dst, d, s);

    }
}


void function(int moves, struct Stack *source, struct Stack *destination, struct Stack *auxilary){

    for(int i=3; i>0; i--){
        push(source, i);
    }

    for(int i=1; i<=moves; i++){

        if(i%3 == 1){

            ethical_move(source, destination, 'S', 'D');

        }
        else if(i%3 == 2){

            ethical_move(source, auxilary, 'S', 'A');

        }
        else{

            ethical_move(auxilary, destination, 'A', 'D');

        }
    }
}

int main(){

    struct Stack *src = create_new_stack(3);
    struct Stack *dst = create_new_stack(3);
    struct Stack *aux = create_new_stack(3);

    function(7, src, dst, aux);


    return 0;
}