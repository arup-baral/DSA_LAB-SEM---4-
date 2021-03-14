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

    if(no + 1 <= Size()){
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
}

int main(){

    //Check the list whether it is working properly or not

    addFirst(40);
    addFirst(30);
    addFirst(20);
    addFirst(100);
    addLast(50);
    addLast(75);
    addFirst(10);
    addFirst(12);

    print();

    printf("\n\n");

    deleteLast();
    deleteFirst();
    deleteFirst();
    deleteLast();

    print();

    printf("\n\n");

    insertAfter(2, 500);
    
    print();

    printf("\n\n");

    deleteAt(3);
    deleteAt(4);
    print();

    printf("\n\n%d\n", Size());

    printf("\n\n");

    addFirst(52);
    print();

    return 0;

}