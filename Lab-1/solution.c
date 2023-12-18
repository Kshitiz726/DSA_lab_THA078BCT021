#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
struct Stack{
    int top;
    int items[MAX_SIZE];
};

void initializeStack(struct Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

bool isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }
    stack->items[++(stack->top)] = value;
    printf("%d pushed into the stack.\n", value);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack.\n");
        return -1; // Or any other value indicating underflow
    }
    int popped = stack->items[(stack->top)--];
    printf("%d popped from the stack.\n", popped);
    return popped;
}


int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // Or any other value indicating empty stack
    }
    return stack->items[stack->top];
}


int main()
{
    struct Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 5);
    push(&myStack, 10);
    push(&myStack, 15);

    printf("Top element: %d\n", peek(&myStack));

    pop(&myStack);
    pop(&myStack);
    pop(&myStack);
    pop(&myStack); // Trying to pop from an empty stack

    return 0;
}