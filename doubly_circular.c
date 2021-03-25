/**
 * 
 * Implement a doubly connected circular linked list in C. 
 * Your program should typically implement insert and delete at all possible locations with proper check(s) as applicable. 
 * Include a display function as well and use it to show the content of your list after every operation. 
 * Include calls to insert and delete from the main
 * 
 **/



#include <stdio.h>
#include <stdlib.h>


struct node {

    int data;
    struct node *next;
    struct node *prev;

};

int size = 0;

int Size(){

    return size;

}

void append(struct node **tail_ref, int data){

    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    newnode->data = data;

    if(*tail_ref == NULL){

        newnode->next = newnode;
        newnode->prev = newnode;
        *tail_ref = newnode;
        
        size++;
        
        return;
    }

    newnode->next = (*tail_ref)->next;
    (*tail_ref)->next = newnode;
    newnode->prev = *tail_ref;
    newnode->next->prev = newnode;
    *tail_ref = newnode;

    size++;
}

void insertAt(struct node **tail_ref, int data, int no){

    if(no > Size() || no <= 0){
        printf("Invalid input\n");
        return;
    }

    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    newnode->data = data;

    if(*tail_ref == NULL){

        newnode->next = newnode;
        newnode->prev = newnode;
        *tail_ref = newnode;
        
        size++;
        
        return;
    }

    struct node *temp = *tail_ref;

    while(no-- > 1){

        temp = temp->next;

    }

    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next->prev = newnode;

    size++;

}

void deleteLast(struct node **tail_ref){

    if(*tail_ref == NULL){
        printf("The list is already empty\n");
        return;
    }

    if(Size() == 1){
        *tail_ref = NULL;
        size--;
        printf("The list becomes empty\n");
        return;
    }

    struct node *flag = (*tail_ref)->prev;

    flag->next = (*tail_ref)->next;
    (*tail_ref)->next->prev = flag;
    *tail_ref = flag;

    size--;

}

void deleteAt(struct node **tail_ref, int no){

    if(no > Size() || no <= 0){
        printf("Invalid input\n");
        return;
    }

    if(no == Size()){
        deleteLast(tail_ref);
        return;
    }
    
    struct node *temp = *tail_ref;

    while(no-- > 1){
        temp = temp->next;
    }

    temp->next = temp->next->next;
    temp->next->prev = temp;

    size--;

}

void print(struct node *tail){

    struct node *temp = tail->next;

    int n = Size();

    while(n-->0){
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");

}

int main(){

    struct node *tail = NULL;

    while(1){
        
        int m, item, no;

    printf("Add item at the end of the list(1)\n");
    printf("Insert item at specific position of the list(2)\n");
    printf("Delete item at the end of the list(3)\n");
    printf("Delete item at specific position of the list(4)\n");
    printf("Exit(0)\n");

    scanf("%d", &m);

    switch(m){

        case 1:
            
            printf("Enter a data: ");
            scanf("%d", &item);
            append(&tail, item);
            print(tail);
            break;

        case 2:
            
            printf("Enter a data: ");
            scanf("%d", &item);
            printf("Enter the position: ");
            scanf("%d", &no);
            insertAt(&tail, item, no);
            print(tail);
            break;

        case 3:
            
            deleteLast(&tail);
            print(tail);
            break;

        case 4:

            printf("Enter the position: ");
            scanf("%d", &no);
            deleteAt(&tail, no);
            print(tail);
            break;

        case 0:
            
            exit(1);
    }
    }

    return 0;
}