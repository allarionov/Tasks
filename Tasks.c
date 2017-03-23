#include <stdio.h>

// Прототипы функций
int PickTask (void);
int RunTask (int);
int Task1 (void);
int Task2 (void);

/* 
 * Основная функция main
 * Ее роль заключается в получении от пользователя номера задачи и ее дальнейшего выполнения
 */ 

int main (void) {
	int TaskNumber = 0;
	while (1) {
		TaskNumber = PickTask();
		if (TaskNumber == 0xABADBABE) return 1;
		else if (TaskNumber == 0xBAADF00D) continue;
		else RunTask (TaskNumber);
	}
} 		 	

/* 
 * ================================================
 * ================================================ 
 * ================================================
 */

/*
 * ----------------- Выбор задачи -----------------
 */

int PickTask (void) {
	int TaskNumber = 0;
	printf ("\nВведите номер решаемой задачи (1-50) или 0 для выхода: ");
	if (scanf ("%d", &TaskNumber) !=1) {
		printf ("Введено не целое число. Очищаем поток ввода. Попробуйте еще раз...\n");
		scanf("%*[^\n]");
		return 0xBAADF00D;
	}
	if (TaskNumber == 0) {
		printf ("Выходим из программы...\n");
		scanf("%*[^\n]");
		return 0xABADBABE;
	}	
    else if ((TaskNumber < 1) || (TaskNumber > 50)) {
		printf ("Введено число вне указанного диапазона. Попробуйте еще раз...\n");
		scanf("%*[^\n]");
		return 0xBAADF00D;
	} 	
	else {
		printf ("Вы запросили задачу № %d\n", TaskNumber); 
		return TaskNumber;
	}
}

/*
 * ----------------- Запуск задачи -----------------
 */

int RunTask (int TaskNumber) {
	printf ("Начинаем выполнение задачи № %d...\n\n", TaskNumber);
	switch (TaskNumber) {
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	default:
		printf ("Пока готовы только задачи № 1 и 2. Введите другой номер...\n");
		break;
		return 1;
	}
}

/* ----------------- Задача № 1 -----------------
 *    Вывести на экран сообщение «Hello World!
 */

int Task1 (void) {
	printf ("Задача № 1. Вывести на экран сообщение «Hello World!\"\n");
	printf ("Hello World!\n");
	return 0;
}

/* ----------------- Задача № 2 -----------------
 * Вывести на экран три целых числа в порядке, обратном вводу
 */

int Task2 (void) {
	int number3, number2, number1;
	printf ("Задача № 2. Вывести на экран три целых числа в порядке, обратном вводу\n");
	printf ("Введите 3 числа типа int через пробел: ");
	if (scanf ("%d%d%d", &number1, &number2, &number3) !=3) {
	printf ("Как минимум одно введенное значение не целое число. Очищаем поток ввода. Попробуйте еще раз...\n");
		scanf("%*[^\n]");
		return 1;
	}
	else {
		printf ("Выводим числа в обратном порядке: %d %d %d\n", number3, number2, number1);
		return 0;
	}
}