#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "StackA.h"

// Возвращает количество цифр в записи числа x.
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

// Поочерёдное внесение цифр числа number в стек stack.
void stackPushNumber(StackA* stack, int number) {
	// Вспомогательная переменная для хранения обратной записи числа.
	int numberReverse = 0;

	// Получаем обратную запись числа для корректной записи в стек.
	do {
		numberReverse = numberReverse * 10 + number % 10;
	} while (number /= 10);

	// Записываем цифры числа в стек.
	do {
		stackPush(stack, numberReverse % 10);
	} while (numberReverse /= 10);
}

int main() {
	// Установка русской локализации консоли
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");

	// Число, вводимое с клавиатуры
	int number = 0;

	// Произведение цифр числа
	double product = 1;

	// Сумма цифр числа
	double sum = 0;

	// ДСД "Стек"
	StackA stack;

	// Элемент стека
	double element;

	// Выводим приглашение ко вводу
	printf_s("Введите число, цифры которого необходимо добавить в стек: ");

	// Считываем число number
	scanf_s("%d", &number);

	// Инициализируем стек длиной, равной длине числа (функция numberLength())
	stackInit(&stack, numberLength(number));

	// Поочерёдно добавляем цифры числа в стек
	stackPushNumber(&stack, number);

	// Выводим стек на экран
	stackPrint(&stack);

	// Цикл по вычислению суммы и произведения цифр числа в стеке
	while (stack.top >= 0)
	{
		element = stackPop(&stack);
		sum += element;
		product *= element;
	}

	// Выводим сумму и произведение, вычисленные выше
	printf_s(
		"Сумма цифр числа, записанного в стек, равна %.2lf.\n"
		"Произведение цифр числа, записанного в стек, равно %.2lf.\n",
		sum, product
	);

	// Уничтожаем стек для освобождения памяти, выделенной под него
	stackDestruct(&stack);

	return 0;
}