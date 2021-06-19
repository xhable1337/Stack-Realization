#include "StackA.h"

// �������������� ���� stack �� count ���������.
void stackInit(StackA* stack, int count)
{
    if (stack->next = (double*)malloc(sizeof(double) * count))
    {
        stack->count = count;
    }
    else stack->count = -1;
    stack->top = -1;
}

// ������� �������� ����� stack �� �����.
void stackPrint(StackA const* stack)
{
    int i;
    for (i = 0; i <= stack->top; i++)
        printf("%-7.3lf ", (stack->next)[i]);
    printf("\n");
}

// ���������� ���� stack.
void stackDestruct(StackA* stack)
{
    if (stack->next) free(stack->next);
    stack->count = -1;
    stack->top = -1;
}

// ��������� ������� element � ���� stack.
int stackPush(StackA* stack, double element)
{
    if (stack->top >= stack->count - 1) return 0;
    stack->top++;
    stack->next[stack->top] = element;
    return 1;
}

// ������� ������� �� ����� stack � ���������� ���.
double stackPop(StackA* stack)
{
    if (stack->top >= 0)
        return stack->next[stack->top--];

    else return 1e300;
}

// ���������� ������� �� ����� stack ��� ��� ��������.
double stackPeek(StackA const* stack)
{
    if (stack->top >= 0)
        return stack->next[stack->top];
    else return 1e300;
}

// ������� ���� stack.
void stackClear(StackA* stack) //������� �����
{
    stack->top = -1;
}

// ��������� ���� �� ������� ���������.
int isStackEmpty(StackA const* stack)
{
    if (stack->top < 0) return 1;
    else return 0;
}
