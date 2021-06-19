#include "StackA.h"

// Инициализирует стек stack из count элементов.
void stackInit(StackA* stack, int count)
{
    if (stack->next = (double*)malloc(sizeof(double) * count))
    {
        stack->count = count;
    }
    else stack->count = -1;
    stack->top = -1;
}

// Выводит элементы стека stack на экран.
void stackPrint(StackA const* stack)
{
    int i;
    for (i = 0; i <= stack->top; i++)
        printf("%-7.3lf ", (stack->next)[i]);
    printf("\n");
}

// Уничтожает стек stack.
void stackDestruct(StackA* stack)
{
    if (stack->next) free(stack->next);
    stack->count = -1;
    stack->top = -1;
}

// Добавляет элемент element в стек stack.
int stackPush(StackA* stack, double element)
{
    if (stack->top >= stack->count - 1) return 0;
    stack->top++;
    stack->next[stack->top] = element;
    return 1;
}

// Удаляет элемент из стека stack и возвращает его.
double stackPop(StackA* stack)
{
    if (stack->top >= 0)
        return stack->next[stack->top--];

    else return 1e300;
}

// Возвращает элемент из стека stack без его удаления.
double stackPeek(StackA const* stack)
{
    if (stack->top >= 0)
        return stack->next[stack->top];
    else return 1e300;
}

// Очищает стек stack.
void stackClear(StackA* stack) //очистка стека
{
    stack->top = -1;
}

// Проверяет стек на наличие элементов.
int isStackEmpty(StackA const* stack)
{
    if (stack->top < 0) return 1;
    else return 0;
}
