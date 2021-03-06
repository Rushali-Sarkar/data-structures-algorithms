#include<stdio.h>
#include<malloc.h>

struct Queue {

    int front;
    int back;
    unsigned capacity;
    int numElements;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {

    struct Queue* queue = malloc(sizeof(struct Queue));
    queue -> front = -1;
    queue -> back  = 0;
    queue -> numElements = 0;
    queue -> capacity = capacity;
    queue -> array = malloc(capacity * sizeof(int));
    return queue;
}

_Bool isEmpty(struct Queue* queue) {
    return queue -> numElements == 0;
}

_Bool isFull(struct Queue* queue) {
    return queue -> numElements == queue -> capacity;
}

void push(struct Queue* queue, int item) {

    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }

    if (queue -> numElements == 0)
        queue -> front = -1;

    queue -> array[++queue -> front] = item;
    queue -> numElements++;
    return;
}

int pop(struct Queue* queue) {

    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }

   queue -> numElements--;
   int element = queue -> array[queue -> back++];

   if (queue -> back == queue -> capacity)
       queue -> back = 0;

   return element;
}

int getSize(struct Queue* queue) {
    return queue -> numElements;
}


void show(struct Queue* queue) {

    int counter = 1;
    int index = queue -> back;

    while (counter <= queue -> numElements) {
        printf("%d\t", queue -> array[index]);
        counter++;
        index++;
    }

    printf("\n");
    return;
}



int main(int argc, char* argv[]) {

    struct Queue* queue = createQueue(3);
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    show(queue);
    printf("%d\n", pop(queue));
    push(queue, 4);
    show(queue);
    printf("%d\n", pop(queue));
    printf("%d\n", pop(queue));
    printf("%d\n", pop(queue));
    return 0;

}
