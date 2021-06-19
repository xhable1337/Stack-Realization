#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "StackA.h"

// ���������� ���������� ���� � ������ ����� x.
int numberLength(int x) {
	int length = 0;
	if (x == 0) return 1;

	while (x != 0)
	{
		length++;
		x /= 10;
	}

	return length;
}

// ���������� �������� ���� ����� number � ���� stack.
void stackPushNumber(StackA* stack, int number) {
	// ��������������� ���������� ��� �������� �������� ������ �����.
	int numberReverse = 0;

	// �������� �������� ������ ����� ��� ���������� ������ � ����.
	do {
		numberReverse = numberReverse * 10 + number % 10;
	} while (number /= 10);

	// ���������� ����� ����� � ����.
	do {
		stackPush(stack, numberReverse % 10);
	} while (numberReverse /= 10);
}

int main() {
	// ��������� ������� ����������� �������
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");

	// �����, �������� � ����������
	int number = 0;

	// ������������ ���� �����
	double product = 1;

	// ����� ���� �����
	double sum = 0;

	// ��� "����"
	StackA stack;

	// ������� �����
	double element;

	// ������� ����������� �� �����
	printf_s("������� �����, ����� �������� ���������� �������� � ����: ");

	// ��������� ����� number
	scanf_s("%d", &number);

	// �������������� ���� ������, ������ ����� ����� (������� numberLength())
	stackInit(&stack, numberLength(number));

	// ��������� ��������� ����� ����� � ����
	stackPushNumber(&stack, number);

	// ������� ���� �� �����
	stackPrint(&stack);

	// ���� �� ���������� ����� � ������������ ���� ����� � �����
	while (stack.top >= 0)
	{
		element = stackPop(&stack);
		sum += element;
		product *= element;
	}

	// ������� ����� � ������������, ����������� ����
	printf_s(
		"����� ���� �����, ����������� � ����, ����� %.2lf.\n"
		"������������ ���� �����, ����������� � ����, ����� %.2lf.\n",
		sum, product
	);

	// ���������� ���� ��� ������������ ������, ���������� ��� ����
	stackDestruct(&stack);

	return 0;
}