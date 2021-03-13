#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node {

    int data;
    struct Node* nextElement;
};

struct Node* headNode;

void insertAtHead(int value) {

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> nextElement = headNode;
    headNode = newNode;
    return;
}

void insertAtTail(int value) {

    if (headNode == NULL) {
        insertAtHead(value);
        return;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> nextElement = NULL;
    
    struct Node* currentNode = headNode;
    while (currentNode -> nextElement != NULL) 
       currentNode = currentNode -> nextElement;

   currentNode -> nextElement =  newNode;
   return;
}

void printList() {

    struct Node* currentNode = headNode;

    while (currentNode != NULL) {
        printf("%d\t", currentNode -> data);
        currentNode = currentNode -> nextElement;
    }

    printf("\n");
    return;
}

int main(int argc, char* argv[]) {

    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    insertAtTail(4);
    insertAtTail(5);
    insertAtTail(6);

    printList();
    return 0;
}


