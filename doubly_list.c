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

    /* since last node so next pointer points to null */
    newnode->next = NULL;

    /* if head is NULL i.e the DLL is empty add the newnode as head */
    if(*head == NULL){
        newnode->prev = NULL;
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

    /* Store the address of newnode in the temp node */
    temp->next = newnode;

    /* prev pointer of the newnode points to the earlier last node (temp) */
    newnode->prev = temp;

    /* Update the size */
    size++;

}

void insertAfter(struct node *head, int no, int data){

    if(head == NULL){
        printf("\nInvalid Input\n");
        return;
    }

    if(no > Size()){
        printf("\nInvalid input\n");
        return;
    }

    if(no == Size()){
        addLast(&head, data);
        return;
    }

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    struct node *current = head;

    while(no-- > 1){
        current = current->next;
    }

    newnode->next = current->next;
    current->next = newnode;
    newnode->prev = current;
    newnode->next->prev = newnode;
    
    size++;
}

void deleteFirst(struct node **head){
    
    /* check whether the head is null or not. 
     * if head is null return
     * else proceed deletion */
    if(*head == NULL){
        printf("\nList is Empty\n");
        return;
    }
    
    /* if head.next is not null 
     * then update the previous pointer of head.next node to null
     * since head.next will be the first node for now */
    if((*head)->next != NULL){
        (*head)->next->prev = NULL;
    }
    
    /* Update the head pointer */
    *head = (*head)->next;

    /* Update the size */
    size--;

}

void deleteLast(struct node **head){
    
    /* check whether the head is null or not. 
     * if head is null return
     * else proceed deletion */
    if(*head == NULL){
        printf("\nList is Empty\n");
        return;
    }
    else if((*head)->next == NULL){
        *head = NULL;
        size--;
        return;
    }
    
    struct node *temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;

    /* Update the size */
    size--;

}

void deleteAt(struct node *head, int no){

    if(head == NULL){
        return;
    }

    if(no == 1){
        deleteFirst(&head);
        return;
    }

    if(no == Size()){
        deleteLast(&head);
        return;
    }

    if(no > size){
        printf("Invalid function call\n");
        return;
    }

    struct node *temp = head;

    while(no-- > 1){
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    size--;
    free(temp);
}

/* Method to print the DLL */
void print(struct node *head){

    struct node *temp = head, *last = head;
    
    printf("List in forward direction:\n");
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    while(last->next != NULL){
        last = last->next;
    }

    printf("\n");
    
    printf("List in backward direction:\n");
    while(last != NULL){
        printf("%d\t", last->data);
        last = last->prev;
    }
}

int main(){

    /* Declare the head pointer */
    struct node *head = NULL;

    addLast(&head, 10);
    print(head);
    printf("\n\n");
    addFirst(&head, 5);
    print(head);
    printf("\n\n");
    addFirst(&head, 25);
    print(head);
    printf("\n\n");
    addLast(&head, 63);
    print(head);
    printf("\n\n");
    insertAfter(head, 1, 20);
    print(head);
    printf("\n\n");
    insertAfter(head, Size(), 30);
    print(head);
    printf("\n\n");
    deleteAt(head, 2);
    print(head);
    printf("\n\n");
    addLast(&head, 37);
    print(head);
    printf("\n\n");
    deleteFirst(&head);
    print(head);
    printf("\n\n");
    deleteLast(&head);
    print(head);
    printf("\n\n");
    deleteLast(&head);
    print(head);
    printf("\n\n");
    deleteLast(&head);
    print(head);
    printf("\n\n");
    deleteAt(head, 2);
    print(head);
    printf("\n\n");

    return 0;
}