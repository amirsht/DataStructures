#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>


struct Stack { 
    int top; 
    unsigned capacity; 
    int* arr; 
} typedef Stack; 

struct Stack* createStack(unsigned capacity) 
{ 
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = 0;
    s->top = -1;
    s->capacity = capacity;
    s->arr = (int *) malloc (capacity * sizeof(int));
    return s;
}


bool isFull(Stack* stack) 
{
    return (stack->top == (stack->capacity - 1)) ? true : false;    
}

bool  isEmpty(Stack* stack) 
{
    return stack->top == -1 ? true : false;
}

bool push(Stack* stack, int item)
{
    if (isFull(stack)) 
        return false;
        
    stack->arr[++stack->top] = item;

    return true;
}

int pop(Stack* stack)
{
    if(isEmpty(stack))
        return  -2147483648;

    return stack->arr[stack->top--]; 
}
    


// program to check above functions 
int main() 
{ 
    struct Stack* stack = createStack(10); 
  
    push(stack, 1); 
    push(stack, 2); 
    push(stack, 3);

    for(int i = 0 ; i<10 ; i++)
        push(stack,i); 
  
    printf("%d popped from stack\n", pop(stack)); 
  
    return 0; 
} 