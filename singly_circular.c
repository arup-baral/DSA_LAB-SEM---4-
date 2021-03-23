/**
 * 
 * Implement a singly connected circular linked list in C. 
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
};

//Stores the size of the list
int size = 0;

int Size(){
    return size;
}

void addToEmptyList(struct node ***ref, int data){

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    newnode->next = newnode;
    **ref = newnode;

    size++;
}

void addFirst(struct node **ref_to_last, int data){

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    if(*ref_to_last == NULL){    /*If the last pointer points to null i.e Empty List, we insert a node to an empty list*/
        addToEmptyList(&ref_to_last, data);
        return;
    }
    else{
        newnode->next = (*ref_to_last)->next; // Store the address of first node i.e tail.next node in the newnode. Now newnode points 
                                              // the first node.

        (*ref_to_last)->next = newnode; //Now tail.next points the new node
        size++;
    }
}

void addLast(struct node **ref_to_last, int data){

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    if(*ref_to_last == NULL){
        addToEmptyList(&ref_to_last, data);
        return;
    }
    else{
        newnode->next = (*ref_to_last)->next;
        (*ref_to_last)->next = newnode;
        (*ref_to_last) = newnode; /* First 2 lines are same as addFirst() method. To add a node at the last position we have to 
                                     update the tail pointer. Tail pointer points the newnode.*/
        size++;
    }

}

void insertAfter(struct node **tail, int no, int data){

    if(size == 0){
        return;
    }

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    struct node *temp = *tail;
    int t = no;

    while(t-- > 0){
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    if(no == Size()){
        *tail = newnode;
    }

    size++;
}

void deleteFirst(struct node **tail){

    if(size == 0){
        return;
    }
    
    if(size == 1){
        *tail = NULL;
        size--;
        return;
    }

    (*tail)->next = (*tail)->next->next;
    size--;

}

void deleteLast(struct node **tail){

    if(size == 0){
        return;
    }

    if(size == 1){
        (*tail) = NULL;
        size--;
        return;
    }

    struct node *current = (*tail)->next;
    struct node *prev = NULL;

    int len = Size();

    while(len-- > 1){
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    *tail = prev;
    size--;
}

void deleteAt(struct node *tail, int no){

    if(no > Size() || no<0){

        printf("Invalid Input");
        return;
    }

    if(no == 1){
        deleteFirst(&tail);
        return;
    }

    if(no == Size()){
        deleteLast(&tail);
        return;
    }

    struct node *current = tail->next, *prev = NULL;

    while(no-- > 1){
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    size--;
}

void print(struct node *tail){

    struct node *temp = tail->next;
    int len = size;

    while(len-- > 0){
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    printf("\n");

}

int main(){

    struct node *tail = NULL;

    int n;

    printf("Do you want to add/delete item to the list:\n");
    printf("To add/delete item(1)/Not to do anything(0)\n");
    scanf("%d", &n);

    while(n == 1){
        int m, item, no;

    printf("Add item at the beginning of the list(1)\n");
    printf("Add item at the end of the list(2)\n");
    printf("Insert item at specific position of the list(3)\n");
    printf("Delete item at the beginning of the list(4)\n");
    printf("Delete item at the end of the list(5)\n");
    printf("Delete item at specific position of the list(6)\n");
    printf("Exit(0)\n");

    scanf("%d", &m);

    switch(m){

        case 1:
            
            printf("Enter a data: ");
            scanf("%d", &item);
            addFirst(&tail, item);
            print(tail);
            break;

        case 2:
            
            printf("Enter a data: ");
            scanf("%d", &item);
            addLast(&tail, item);
            print(tail);
            break;

        case 3:
            
            printf("Enter a data: ");
            scanf("%d", &item);
            printf("Enter the position: ");
            scanf("%d", &no);
            insertAfter(&tail, no-1, item);
            print(tail);
            break;

        case 4:
            
            deleteFirst(&tail);
            print(tail);
            break;

        case 5:
            
            deleteLast(&tail);
            print(tail);;
            break;

        case 6:

            printf("Enter the position: ");
            scanf("%d", &no);
            deleteAt(tail, no);
            print(tail);
            break;

        case 0:
            
            exit(1);
    }
    }

    return 0;
}