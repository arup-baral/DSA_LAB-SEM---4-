/**
 * 
 * Implement a singly connected linear linked list in C. 
 * Your program should typically implement insert and delete at all possible locations with proper check(s) as applicable. 
 * Include a display function as well and use it to show the content of your list after every operation. 
 * Include calls to insert and delete from the main
 * 
 **/




/**
 * import standard library and header file
 **/

#include <stdio.h>
#include <stdlib.h>

//Declaration of Node structure
struct node {
    int data;
    struct node *next;
};

//Declaration of the size of the linked list
int size = 0;

struct node *head = NULL; //head pointer
struct node *tail = NULL; //tail pointer

//Return the size of the Linked List
int Size(){

    return size;

}

//Method to add a node to an empty list
void addToEmptyList(int data){

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    head = tail = newnode;
    size++;

}

//Method to add a node at the first position of the list
void addFirst(int data){

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    if(head == NULL){
        addToEmptyList(data);
    }
    else{
        newnode->next = head;
        head = newnode;
        size++;
    }

}

//Method to add a node to the last position of the list
void addLast(int data){

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    if(tail == NULL){
       addToEmptyList(data);
    }
    else{
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
        size++;
    }

}

//Method to a add a node at a particular position
void insertAfter(int no, int data){

    if(head == NULL){
        printf("Invalid input\n");
        return;
    }

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;

    if(no == Size()){
        addLast(data);
        return;
    }

    if(no < Size() && (no > 0)){
        struct node *temp = head;
        while(no-- > 1){
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        size++;
    }
    else{
        printf("Invalid input\n");
    }

}

//Method to delete the first node
void deleteFirst(){

    if(Size() > 0){
        head = head->next;
        size--;
    }
    else{
        printf("Invalid Function Call\n");
    }
}

//Method to delete the last node
void deleteLast(){
    
    if(Size() > 0){
        struct node *current = head;
        struct node *pre = NULL;
        while(current->next != NULL){
            pre = current;
            current = current->next;
        }
        tail = pre;
        pre->next = NULL;
        size--;
    }
    else{
        printf("Invalid Function Call\n");
    }
}

void deleteAt(int no){

    int t = no;

    if(no == 1){
        deleteFirst();
        return;
    }
    else if(no == Size()){
        deleteLast();
        return;
    }

    struct node *current = head;
    struct node *prev = NULL;

    while(t-- > 1){
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    size--;
}

//Method to print the list
void print(){

    struct node *temp = head;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Case(){

    int n, item, no;

    printf("Add item at the beginning of the list(1)\n");
    printf("Add item at the end of the list(2)\n");
    printf("Insert item at specific position of the list(3)\n");
    printf("Delete item at the beginning of the list(4)\n");
    printf("Delete item at the end of the list(5)\n");
    printf("Delete item at specific position of the list(6)\n");
    printf("Exit(0)\n");

    scanf("%d", &n);

    switch(n){

        case 1:
            
            printf("Enter a data: ");
            scanf("%d", &item);
            addFirst(item);
            print();
            break;

        case 2:
            
            printf("Enter a data: ");
            scanf("%d", &item);
            addLast(item);
            print();
            break;

        case 3:
            
            printf("Enter a data: ");
            scanf("%d", &item);
            printf("Enter the position: ");
            scanf("%d", &no);
            insertAfter(no-1, item);
            print();
            break;

        case 4:
            
            deleteFirst();
            print();
            break;

        case 5:
            
            deleteLast();
            print();
            break;

        case 6:

            printf("Enter the position: ");
            scanf("%d", &no);
            deleteAt(no);
            print();
            break;

        case 0:
            
            exit(1);
    }
}

int main(){

    int n;

    printf("Do you want to add/delete item to the list:\n");
    printf("To add/delete item(1)/Not to do anything(0)\n");
    scanf("%d", &n);

    while(n == 1){
        Case();
    }

    return 0;

}