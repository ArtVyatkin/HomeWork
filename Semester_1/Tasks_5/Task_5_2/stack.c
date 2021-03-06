#include <stdlib.h>
#include "stack.h"

typedef struct StackElement StackElement;
struct StackElement
{
    double value;
    StackElement* next;
};

struct Stack
{
    StackElement* top;
    int size;
};

Stack* createStack()
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

StackElement* createStackElement(double value, StackElement* nextElement)
{
    StackElement* stackElement = (StackElement*) malloc(sizeof(StackElement));
    stackElement->value = value;
    stackElement->next = nextElement;
    return stackElement;
}

bool pushToStack(Stack* stack, double value)
{
    if (stack == NULL)
    {
        return false;
    }

    StackElement* newElement = createStackElement(value, stack->top);
    stack->top = newElement;
    stack->size++;

    return true;
}

double popFromStack(Stack* stack)
{
    if (isStackEmpty(stack))
    {
        return 0.0;
    }

    StackElement* poppedElement = stack->top;
    double returnValue = poppedElement->value;
    stack->top = poppedElement->next;
    free(poppedElement);
    stack->size--;

    return returnValue;
}

double peekIntoStack(Stack* stack)
{
    if (isStackEmpty(stack))
    {
        return 0.0;
    }

    return stack->top->value;
}

bool isStackEmpty(Stack* stack)
{
    return stack == NULL || stack->top == NULL;
}

void deleteStack(Stack* stack)
{
    while (!isStackEmpty(stack))
    {
        popFromStack(stack);
    }

    free(stack);
}

int getStackSize(Stack* stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    return stack->size;
}