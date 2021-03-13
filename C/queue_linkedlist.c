#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct Queue {
    int numElements;
    struct LinkedList* list;
};

struct Queue* createQueue(struct Queue* queue) {
    queue -> numElements = 0;
    queue -> list -> head = malloc(sizeof(struct Node));
    return queue;
}

_Bool isEmpty(struct Queue* queue) {
    return queue -> numElements == 0;
}

void enqueue(struct Queue* queue, int item) {

    if (isEmpty(queue)) {
        queue -> list -> head = malloc(sizeof(struct Node));
        queue -> list -> head -> data = item;
        queue -> list -> head -> next = NULL;
        queue -> numElements++;
        return;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode = queue -> list -> head;

    while (newNode -> next != NULL)
        newNode = newNode -> next;

    newNode -> next = malloc(sizeof(struct Node));
    newNode -> next -> data = item;
    newNode -> next -> next = NULL;
    queue -> numElements++;
    return;
}

int dequeue(struct Queue* queue) {

    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    int item = queue -> list -> head -> data;
    queue -> list -> head = queue -> list -> head -> next;
    queue -> numElements--;
    return item;
}

int peek_back(struct Queue* queue) {


    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode = queue -> list -> head;

    while (newNode -> next != NULL)
        newNode = newNode -> next;

    return newNode -> data;
}

int peek_front(struct Queue* queue) {

    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

    return queue -> list -> head -> data;
}

void showQueue(struct Queue* queue) {

    if (isEmpty(queue)) {
        printf("No elements to show\n");
        return;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode = queue -> list -> head;
    while (newNode != NULL) {
        printf("%d\t", newNode -> data);
        newNode = newNode -> next;
    }

    printf("\n");
    return;
}

int main(int argc, char* argv[]) {

    _Bool exploring = true;
    int choice, item;
    struct Queue* queue = createQueue(queue);

    while (exploring) {
        
        printf("Enter your choice:\n");
        printf("1. Enqueue\t2. Dequeue\t3. Show Queue\t4. Peek Back\t7. Peek Front\t6. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            
            case 1:
                printf("Enter the item you want to enqueue in the queue.\n");
                scanf("%d", &item);
                enqueue(queue, item);
                break;

            case 2:
                item = dequeue(queue);
                if (item != -1)
                    printf("Dequeued %d out of the queue.\n", item);
                break;

            case 3:
                showQueue(queue);
                break;

            case 4:
                item = peek_back(queue);
                if (item != -1)
                    printf("The back of the queue has %d.\n", item);
                break;

            case 5:
                item = peek_front(queue);
                if (item != -1)
                    printf("The front of the queue has %d.\n", item);
                break;

            case 6:
                exploring = false;
                break;

            default: 
                printf("Sorry Wrong Choice. Try Again.\n");
        }
    }

    return 0;
}
