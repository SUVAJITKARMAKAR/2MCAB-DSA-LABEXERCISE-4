// LAB EXERCISE 4 
// TOPIC - Implementation of queue operations using linked list on the basis of notificatoin push over domain SOCIAL MEDIA APPLICATION
// AUTHOR - SUVAJIT KARMAKAR
// REGISTRATION - 2347261

#include <stdio.h>
#include <stdlib.h>

struct Notification {
    int notificationId;
    char message[100];
};

struct Node {
    struct Notification data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(struct Notification newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("MEMORY ALLOCATION ERROR !\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, struct Notification newData) {
    struct Node* newNode = createNode(newData);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

struct Notification dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("NOTIFICATION QUEUE IS EMPTY !\n");
        exit(EXIT_FAILURE);
    }

    struct Node* temp = queue->front;
    struct Notification data = temp->data;

    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("NOTIFICATION QUEUE IS EMPTY !\n");
        return;
    }

    struct Node* current = queue->front;
    printf("QUEUE CONTENTS -> \n");
    while (current != NULL) {
        printf("NOTIFICATION ID -> %d, MESSAGE ->  %s\n", current->data.notificationId, current->data.message);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue notificationQueue;
    initializeQueue(&notificationQueue);

    int choice;
    struct Notification newNotification;

    do {
        printf("1. ENQUEUE A NOTIFICATION.\n");
        printf("2. DEQUEUE A NOTIFICATION\n");
        printf("3. DISPLAY NOTIFICATIONS\n");
        printf("4. QUIT\n");
        printf("-----------------------------\n");
        printf("ENTER YOUR CHOICE ->  ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ENTER THE NOTIFICATION ID -> ");
                scanf("%d", &newNotification.notificationId);
                printf("ENTER YOUR NOTIFICATION MESSAGE -> ");
                scanf(" %[^\n]", newNotification.message);
                enqueue(&notificationQueue, newNotification);
                break;
            case 2:
                if (!isEmpty(&notificationQueue)) {
                    struct Notification dequeuedNotification = dequeue(&notificationQueue);
                    printf("DEQUEUED NOTIFICATION ID -> %d, MESSAGE -> %s\n\n", dequeuedNotification.notificationId, dequeuedNotification.message);
                } else {
                    printf("NOTIFICATION QUEUE IS EMPTY ! NO NOTIFICATION TO DELETE !\n\n");
                }
                break;
            case 3:
                displayQueue(&notificationQueue);
                break;
            case 4:
                printf("EXITING THE PROGRAM \n");
                break;
            default:
                printf("PLEASE PROVIDE A VALID OPTION TO PROCEED.\n");
        }
    } while (choice != 4);

    return 0;
}
