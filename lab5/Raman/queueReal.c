#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Node{
    int val;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue *createQueue();
int size(Queue *queue);
bool isEmpty(Queue *queue);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void display(Queue *queue);

int main(){
    Queue *qReal = createQueue();
    int enq, flag = 0;
    bool status;

    while (flag != 4){
        printf("\nChoose operation:\n");
        printf("1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
        scanf("%d", &flag);

        switch(flag){
            case 1:
                printf("Enter value: ");
                scanf("%d", &enq);
                enqueue(qReal, enq);
                break;

            case 2: {
                int value = dequeue(qReal, &status);
                if (!status)
                    printf("Queue is empty\n");
                else
                    printf("Dequeued: %d\n", value);
                break;
            }

            case 3:
                display(qReal);
                break;

            case 4:
                break;

            default:
                printf("Invalid option\n");
        }
    }

    printf("Loop exited with %d elements\n", qReal->size);
    return 0;
}

Queue *createQueue(){
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

int size(Queue *queue){
    return queue->size;
}

bool isEmpty(Queue *queue){
    return (queue->size == 0);
}

void enqueue(Queue *queue, int value){
    Node *newNode = malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;

    if (isEmpty(queue)){
        queue->head = newNode;
        queue->tail = newNode;
    }
    else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;
}

int dequeue(Queue *queue, bool *status){
    if (isEmpty(queue)){
        *status = false;
        return 0;
    }

    *status = true;

    Node *oldHead = queue->head;
    int value = oldHead->val;

    queue->head = oldHead->next;

    if (queue->head == NULL)
        queue->tail = NULL;

    free(oldHead);
    queue->size--;

    return value;
}

void display(Queue *queue){
    if (isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }

    Node *current = queue->head;
    printf("Queue: ");
    while (current != NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}