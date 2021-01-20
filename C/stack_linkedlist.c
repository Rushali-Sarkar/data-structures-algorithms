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

struct Stack {
    int top;
    struct LinkedList* list;
};

struct Stack* createStack(struct Stack* stack) {
    stack -> top = 0;
    stack -> list -> head = malloc(sizeof(struct Node));
    return stack;
}

_Bool isEmpty(struct Stack* stack) {
    return stack -> top == 0;
}

void push(struct Stack* stack, int item) {

    if (isEmpty(stack)) {
        stack -> list -> head = malloc(sizeof(struct Node));
        stack -> list -> head -> data = item;
        stack -> list -> head -> next = NULL;
        stack -> top++;
        return;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode = stack -> list -> head;

    while (newNode -> next != NULL)
        newNode = newNode -> next;

    newNode -> next = malloc(sizeof(struct Node));
    newNode -> next -> data = item;
    newNode -> next -> next = NULL;
    stack -> top++;
    return;
}

int pop(struct Stack* stack) {

    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    if (stack -> top == 1) {
        int item = stack -> list -> head -> data;
        stack -> list -> head = NULL;
        stack -> top--;
        return item;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode = stack -> list -> head;

    while (newNode -> next -> next != NULL)
        newNode = newNode -> next;

    int item = newNode -> next -> data;
    newNode -> next = NULL;
    stack -> top--;
    return item;
}

int peek(struct Stack* stack) {


    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode = stack -> list -> head;

    while (newNode -> next != NULL)
        newNode = newNode -> next;

    return newNode -> data;
}

void showStack(struct Stack* stack) {

    if (isEmpty(stack)) {
        printf("No elements to show\n");
        return;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode = stack -> list -> head;
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
    struct Stack* stack = createStack(stack);

    while (exploring) {
        
        printf("Enter your choice:\n");
        printf("1. Push\t2. Pop\t3. Show Stack\t4. Peek\t5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            
            case 1:
                printf("Enter the item you want to push.\n");
                scanf("%d", &item);
                push(stack, item);
                break;

            case 2:
                item = pop(stack);
                if (item != -1)
                    printf("Poped %d out of the stack.\n", item);
                break;

            case 3:
                showStack(stack);
                break;

            case 4:
                item = peek(stack);
                if (item != -1)
                    printf("The top of the stack has %d.\n", item);
                break;

            case 5:
                exploring = false;
                break;

            default: 
                printf("Sorry Wrong Choice. Try Again.\n");
        }
    }

    return 0;
}
