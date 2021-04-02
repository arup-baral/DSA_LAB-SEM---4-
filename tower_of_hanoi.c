/**
 * 
 * Write a program for the Tower of Hanoi problem. 
 * Experiment with a varying number of discs. 
 * Show the intermediate moves in form of messages like the following:
 * Move disk ... from rod ... to rod ...
 *
 **/


/* Import the necessary header files */

/* for standard input output */
#include <stdio.h> 

/* for standard library, here it's imported for malloc function */
#include <stdlib.h>

/* this header file is imported for boolean datatype */
#include <stdbool.h>

/* math header file for the use of pow() function */
#include <math.h>


/* define the structure of the stack */
struct Stack {
    
    /* store the index of top element */
    int top;
    
    /* declaring the capacity of the stack */
    unsigned capacity;
    
    /* Array to store the element */
    int* array;

};

/* Method to check whether the stack is empty or not */
bool isEmpty(struct Stack* stack){

    return stack->top == -1;

}

/* Method to check whether the stack is full or not */
bool isFull(struct Stack* stack){

    return stack->top == stack->capacity - 1;

}

/* Create new stack */
/* @return stack */
struct Stack* create_new_stack(unsigned length){

    /* allocate memory for stack */
    struct Stack* stack = (struct Stack *) malloc(sizeof(struct Stack));
    
    /* No element in stack
       so top = - */
    stack->top = -1;
    stack->capacity = length;

    /* allocate memory for the array */
    stack->array = (int *) malloc(stack->capacity * sizeof(int));

    return stack;

}
 
/* Method to push an item to the stack */
void push(struct Stack* stack, int data){

    /* Check the overflow condition */
    /* if the stack is full exit */
    if(isFull(stack)){

        printf("The stack is full.\n");
        exit(1);

    }

    /* First increment the top index, then push the item */
    stack->array[++stack->top] = data;

}

/* Method to remove the top element from the stack */
int pop(struct Stack* stack){

    /* Check underflow condition */
    /* If stack is empty return min integer */
    if(isEmpty(stack)){

        return INT_MIN;

    }

    /* Return the top element and then decrement the top index */
    return stack->array[stack->top--];

}

/* Method to print the stack */
void print_src_stack(struct Stack *stack){

    int top = stack->top;

    while(top != -1){
        printf("%19d\n", stack->array[top]);
        top--;
    }
    
}

void print_aux_stack(struct Stack *stack){

    int top = stack->top;

    while(top != -1){
        printf("%44d\n", stack->array[top]);
        top--;
    }
    
}

void print_dst_stack(struct Stack *stack){

    int top = stack->top;

    while(top != -1){
        printf("%78d\n", stack->array[top]);
        top--;
    }
    
}

/* Method for printing the movement of the particular disc */
/* In the method disc represents the specified disc, 's' represents source,
   'd' represents destination */
void printMoves(int disc, char *s, char *d){

    printf("Move %d no disc from %s to %s\n\n", disc, s, d);

}

/* Method to implement legal move between two towers */
void ethical_move(struct Stack *src, struct Stack *dst, char *s, char *d){

    int element_src = pop(src); // element of source stack
    int element_dst = pop(dst); // element of destination stack
    

    /* when destination stack is empty */
    if(element_dst == INT_MIN){

        push(dst, element_src);
        printMoves(element_src, s, d);

    }
    
    /* when source stack is empty */
    else if(element_src == INT_MIN){

        push(src, element_dst);
        printMoves(element_dst, d, s);

    }
    
    /* when dst_item is greater than src_item
       push both the dst and src item to dst stack */
    else if(element_dst > element_src){

        push(dst, element_dst);

        push(dst, element_src);
        printMoves(element_src, s, d);

    }
    
    /* when dst_item is less than src_item
       push both the dst and src item to src stack */
    else{

        push(src, element_src);

        push(src, element_dst);
        printMoves(element_dst, d, s);

    }

}

/* Method to implement the operation */
void function(int disc, struct Stack *source, struct Stack *destination, struct Stack *auxilary){

    for(int i=disc; i>0; i--){
        push(source, i);
    }

    printf("Initially stack is \n");
    print_src_stack(source);

    /* Declare the src, dst and aux characters */
    char *s = "'Source'", *d = "'Destination'", *a = "'Auxilary'";
    
    /* if no of discs is even swap *d and *a */
    if(disc % 2 == 0){

        char *temp = d;
        d = a;
        a = temp;

    }

    int moves = (int) pow(2, disc) - 1;

    for(int i=1; i<=moves; i++){

        if(i%3 == 1){

            ethical_move(source, destination, s, d);

        }
        else if(i%3 == 2){

            ethical_move(source, auxilary, s, a);

        }
        else{

            ethical_move(auxilary, destination, a, d);

        }

        if(disc%2 != 0){
            printf("\t\tSOURCE \t\t\tAUXILARY \t\t\tDESTINATION\n");
            printf("\t\t------ \t\t\t-------- \t\t\t-----------\n");
            print_src_stack(source);
            print_aux_stack(auxilary);
            print_dst_stack(destination);
        }
        else{
            printf("\t\tSOURCE \t\t\tAUXILARY \t\t\tDESTINATION\n");
            printf("\t\t------ \t\t\t-------- \t\t\t-----------\n");
            print_src_stack(source);
            print_aux_stack(destination);
            print_dst_stack(auxilary);
        }
    }
    printf("\nTotal number of moves = %d\n\n", moves);
}

int main(){

    printf("\n\t\t\t\t\tTOWER OF HANOI\n");
    printf("\t\t\t\t\t--------------\n\n");

    printf("Enter the number of Discs: ");

    int disc;

    scanf("%d", &disc);

    struct Stack *src = create_new_stack(disc); // SOURCE STACK
    struct Stack *dst = create_new_stack(disc); // DESTINATION STACK
    struct Stack *aux = create_new_stack(disc); // AUXILARY STACK

    function(disc, src, dst, aux);


    return 0;
}