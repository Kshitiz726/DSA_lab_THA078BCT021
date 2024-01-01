#include <stdio.h>
#include <stdlib.h>
//define maximum size of stack
#define MAX_SIZE 10

//build stack
struct  Stack{
    int items[MAX_SIZE];
    int top;
};


//initialize the stack

void initializeStack(struct Stack *stack)
{
    stack -> top = -1;
}
//check if stack is full
int isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1; //compares and returns 0 or 1
}


//check if stack is empty
int isEmpty(struct Stack *stack){
    return stack -> top == -1;
}
//push the element into the stack
int push(struct Stack *stack , int element)
{
    if(isFull(stack))
    {
        printf("Stack is Full");
        return -1;
    }
    else{
        stack -> top++;
        stack -> items [stack-> top] = element;
        printf("%d is pushed into the stack\n", element);
        return 1;
    }
}


//pop the element from the stack
int pop(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty");
        return -1;
    }
    else{
        int popped = stack->items[stack->top];
        stack->top --;
        return popped;
    }
}

//peek
int peek(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty");
        return -1;
    }
    else{
        return stack->items[stack -> top];
    }
}
int main()
{
    struct Stack stack;
    initializeStack(&stack);

    push (&stack, 1);
    push (&stack , 2);
     push (&stack , 3);
    printf("Top element: %d\n", peek(&stack));
    printf("Popped element:%d\n", pop(&stack));
    printf("Element at top after pop:%d\n" , peek(&stack));
}