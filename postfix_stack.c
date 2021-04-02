/**
 * 
 * Evaluate postfix expressions using a Stack. You can use ',' as a delimiter between two tokens in an expression. 
 * You can use '$' as the end of input.
 * Always show the intermediate steps including the content of the stack. 
 * Take some example postfix expressions. 
 * Here is one example:
 * 6, 2, 3, +, -, 3, 8, 2, /, +, *, 2, ^, 3, +, $
 * (Use '^' for exponentiation)
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

/* defining the max size of postfix expression 
including all characters */
#define size 1024

/* structure of node
for implementing stack */
struct node{

    double data;
    struct node* next;

};

/* Check whether the stack is empty or not */
bool isEmpty(struct node *top){

    return top == NULL;

}

/* Method to push an element to the stack */
void push(struct node **top_ref, double data){

    /* Allocate memory for new node */
    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    /* Set the data for node */
    newnode->data = data;

    /* store the address of top most element in the newly created node,
    so that new node now points the top node */ 
    newnode->next = *top_ref;

    /* store the address of newnode in top pointer */
    *top_ref = newnode;

}

/*Method to remove the top most element from the stack */
double pop(struct node **top_ref){

    /* if the stack is empty exit */
    if(isEmpty(*top_ref)){
        printf("The list is empty\n");
        exit(1);
    }

    /* store the top node temporarily in a variable */
    struct node *popped = *top_ref;
    
    /* store the address of second top most element in the top pointer */
    /* So that top element would be removed */
    *top_ref = (*top_ref)->next;

    return popped->data;

}

/* Returns the top element */
double peek(struct node *top){

    /* if the stack is empty exit */
    if(isEmpty(top)){
        printf("The list is empty\n");
        exit(1);
    }

    return top->data;

}

/* Method to print the stack */
void print(struct node *top){

    struct node *temp = top;

    while(temp != NULL){
        printf("%5.2f\n", temp->data);
        temp = temp->next;
    }
}

/* Check whether the character is a digit or not */
bool isDigit(char c){

    if(c >= '0' && c <= '9'){
        return true;
    }

    return false;
}

/* driver function */
int main(){

    struct node *top = NULL;

    printf("\n\t\t\t\t\t---EVALUATE POSTFIX EXPRESSION---\n");
    printf("\t\t\t\t\t---------------------------------\n\n");

    printf("Enter the POSTFIX expression (Maximum length can be 1024) :\n");
    printf("(You can use ',' as a delimiter between two tokens.\n For the 'end of expression' you can use '$' symbol)\n");
    printf("(Your token can contain multiple digit)\n");

    char exp[size];

    gets(exp);

    int length = 0;

    int k = 0;

    while(exp[k++] != '\0'){
        length++;
    }

    int i = 0;

    while(exp[i] != '$' && i<length){

        char c = exp[i];

        if(c == '+' || c == '-' || c == '*' || c == '/' ||  c == '^'){

            /* operand 2 */
            double operand2 = pop(&top);

            /* operand 1 */
            double operand1 = pop(&top);

            switch(c){

                case '+':  /* when the operator is plus */
                    
                    printf("Scanned operator is +\n");
                    printf("%.2f + %.2f = %.2f\n", operand1, operand2, operand1+operand2);
                    push(&top, operand1+operand2);
                    break;

                case '-':  /* when the operator is minus */
                    
                    printf("Scanned operator is -\n");
                    printf("%.2f - %.2f = %.2f\n", operand1, operand2, operand1-operand2);
                    push(&top, operand1-operand2);
                    break;

                case '*':  /* when the operator is multiplier */
                    
                    printf("Scanned operator is *\n");
                    printf("%.2f * %.2f = %.2f\n", operand1, operand2, operand1*operand2);
                    push(&top, operand1*operand2);
                    break;

                case '/':  /* when the operator is divider */
                    
                    printf("Scanned operator is /\n");
                    printf("%.2f / %.2f = %.2f\n", operand1, operand2, operand1/operand2);
                    push(&top, operand1/operand2);
                    break;

                case '^':  /* when the operator is exponent */
                    
                    printf("Scanned operator is ^\n");
                    printf("%.2f to the power %.2f = %.2f\n", operand1, operand2, pow(operand1, operand2));
                    push(&top, pow(operand1, operand2));
                    break;

            }

            printf("Stack is :\n");
            print(top);
        }
        else if(c == ',' || c == ' '){
            //TODO nothing
        }
        else{

            int j = i;

            double n = 0.0;

            while(isDigit(exp[j])){
                char a = exp[j++];
                double d = (double) a;
                d -= 48;
                n = (10.0*n) + d;
            }

            push(&top, n);
            printf("%.2f is pushed into the stack\n", n);
            i = j-1;

            printf("Stack is :\n");

            print(top);
        }
        printf("\n");

        i++;

    }

    printf("The expression is ");
    puts(exp);

    printf("\nAnswer of the postfix expression is %5.2f\n\n", peek(top));

    return 0;

}