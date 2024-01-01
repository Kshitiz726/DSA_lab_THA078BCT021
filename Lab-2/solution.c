#include  <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
/// 1-2-3-4-5
//front = 0
//rear ++
//rear ma element haldai garchu
//jhikda kheri front lai increment garera  jhikdai jane ho
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

//initialize the queue
void initialize(struct Queue *queue)
{
    queue -> front  = -1;
    queue -> rear = -1;
}

//check if queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue -> front == -1 || queue -> front > queue ->rear);
}
//front < rear (always in a queue), if front > rear, then queue is invalid or is empty

//check if queue is full
int isFull (struct Queue *queue)
{
    return queue -> rear == MAX_SIZE -1;
}


//(ticket-counter)1-2-3-4
void enqueue(struct Queue *queue, int value)
{
    if(isFull(queue))
    {
        printf("Queue is full\n");
    }
    else {
        if (queue -> front == -1)
        {
            queue -> front = 0;
        }
        queue -> rear ++;
        queue ->items[queue->rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
        return 1; // Return a default value or handle the empty queue case
    } else {
        int dequeued = queue->items[queue->front];
        queue->front++;

        // if (queue->front > queue->rear) {
        //     queue->front = -1;
        //     queue->rear = -1;
        // }

        return dequeued;
    }
}
int main()
{
    struct Queue myQueue;
    initialize(&myQueue);
    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);

    // Dequeue elements
    printf("\nDequeuing elements from the queue:\n");
    printf("%d dequeued from the queue\n", dequeue(&myQueue));
    printf("%d dequeued from the queue\n", dequeue(&myQueue));

    // Enqueue more elements
    enqueue(&myQueue, 4);
    enqueue(&myQueue, 5);

    // Dequeue remaining elements
    printf("\nDequeuing remaining elements from the queue:\n");
    printf("%d dequeued from the queue\n", dequeue(&myQueue));
    printf("%d dequeued from the queue\n", dequeue(&myQueue));
    printf("%d dequeued from the queue\n", dequeue(&myQueue));

    return 0;
}