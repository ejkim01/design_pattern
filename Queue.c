#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

typedef enum {
    false = 0,
    true = 1
} bool;

typedef struct node {
    int value;
    struct node* next;
} node;

typedef struct {
    node* head;
    node* tail;
} queue;

void init_queue(queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) return false;
    newNode->value = value;
    newNode->next = NULL;

    if (q->tail == NULL)
        q->tail = newNode;
    else {
        q->tail->next = newNode;
        q->tail = q->tail->next;
    }
    //if (q->tail != NULL) {
    //    q->tail->next = newNode;
    //}
    //q->tail = newNode;

    if (q->head == NULL) {
        q->head = newNode;
    }
    return true;
}

int dequeue(queue* q) {
    if (q->head == NULL) return QUEUE_EMPTY;
    node *tmp = q->head;
    int result = tmp->value;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
    return result;
}

int main() {

    queue q1;

    init_queue(&q1);

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);

    int t;
    while ((t = dequeue(&q1)) != QUEUE_EMPTY) {
        printf("t = %d\n", t);
    }

    return 0;
}