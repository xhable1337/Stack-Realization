#ifndef _STACK_A_H
#define _STACK_A_H

#include <stdio.h>

/*
���� � ������������ ��������� ������, ���������� �� �������� LIFO
"Last In First Out" = "����� ���������, ���� ������"
*/
typedef struct
{
    double* next;
    int count;
    int top;
} StackA;

int isStackEmpty(StackA const* stack);
void stackInit(StackA* stack, int count);
int stackPush(StackA* stack, double element);
double stackPeek(StackA const* stack);
double stackPop(StackA* stack);
void stackPrint(StackA const* stack);
void stackDestruct(StackA* stack);
void stackClear(StackA* stack);

#endif
