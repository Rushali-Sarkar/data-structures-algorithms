#include<stdio.h>
#include<malloc.h>

struct Stack {

    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {

    struct Stack* stack = malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = malloc(stack -> capacity * sizeof(int));
    return stack;
}

_Bool isFull(struct Stack* stack) {
    return stack -> top == stack -> capacity - 1;
}

_Bool isEmpty(struct Stack* stack) {
    return stack -> top == -1;
}

void push(struct Stack* stack, int item) {

    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }

    stack -> array[++(stack -> top)] = item;
    return;
}

int pop(struct Stack* stack) {

    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack -> array[(stack -> top)--];
}

int top(struct Stack* stack) {

    if (isEmpty(stack)) {
        printf("Sorry the Stack is empty, there is nothing to show\n");
        return -1;
    }

    return stack -> array[stack -> top];
}

void showStack(struct Stack* stack) {
        
    int i;
    for (i = 0; i <= stack -> top; i++)
        printf("%d\t", stack -> array[i]);
    printf("\n");
    return;
}

int main(int argc, char* argv) {

    struct Stack* stack = createStack(10);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    showStack(stack);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    showStack(stack);
    printf("Poped %d out of the stack.\n", pop(stack));
    printf("Poped %d out of the stack.\n", pop(stack)); 
    showStack(stack);

    return 0;
}
