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

}

int main(){

    struct node *tail = NULL;

    addFirst(&tail, 20);
    print(tail);
    printf("\n\n");
    addFirst(&tail, 10);
    print(tail);
    printf("\n\n");
    addFirst(&tail, 5);
    print(tail);
    printf("\n\n");
    addLast(&tail, 60);
    print(tail);
    printf("\n\n");
    insertAfter(&tail, 2, 40);
    print(tail);
    printf("\n\n");
    insertAfter(&tail, 5, 30);
    print(tail);
    printf("\n\n");
    addLast(&tail, 35);
    addLast(&tail, 55);
    print(tail);
    printf("\n\n");
    deleteAt(tail, 6);
    print(tail);
    printf("\n\n");
    deleteFirst(&tail);
    print(tail);
    printf("\n\n");
    deleteLast(&tail);
    print(tail);
    printf("\n\n");
    deleteAt(tail, 5);
    print(tail);
    printf("\n\n");
    deleteAt(tail, 1);
    print(tail);
    printf("\n\n");

    return 0;
}