/**
 * 
 * Implement a doubly connected linear linked list in C. 
 * Your program should typically implement insert and delete at all possible locations with proper check(s) as applicable. 
 * Include a display function as well and use it to show the content of your list after every operation. 
 * Include calls to insert and delete from the main
 * 
 **/

#include <stdio.h>
#include <stdlib.h>


//Declaration of Node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

//Size of the list
int size = 0;

int Size(){
    return size;
}


void addFirst(struct node **head, int data){

    //Allocate memory for a node
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    /* Store the address of head (first) node in the next pointer of the newly created node */
    newnode->next =(*head);

    /* Since newNode will be the first node, prev pointer of the newnode points to NULL */
    newnode->prev = NULL;

    /* Check whether the head is null or not;
     * if not null then store the address of newnode in the prev pointer of the head node
     * else //TODO Nothing */
     if(*head != NULL){
         (*head)->prev = newnode;
     }

     /* Update the head pointer */
     *head = newnode;

     /* Update the Size of the list */
     size++;

}

void addLast(struct node **head, int data){

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    /* if head is NULL i.e the DLL is empty add the newnode as head */
    if(*head == NULL){
        newnode->next = newnode->prev = NULL;
        *head = newnode;
        size++;
        return;
    }
    
    //Declare a temporary pointer pointing to head
    struct node *temp = *head;

    /* make the temp pointing to last node */
    while(temp->next != NULL){
        temp = temp->next;
    }

    /* next pointer of the newnode points to null, since it's the last node */
    newnode->next = NULL;

    /* Store the address of newnode in the temp node */
    temp->next = newnode;

    /* prev pointer of the newnode points to the earlier last node (temp) */
    newnode->prev = temp;

    /* Update the size */
    size++;

}

/* Method to print the DLL */
void print(struct node *head){

    struct node *temp = head;
    
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}