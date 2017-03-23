#include <stdio.h>

// ��������� �������
int PickTask (void);
int RunTask (int);
int Task1 (void);
int Task2 (void);

/* 
 * �������� ������� main
 * �� ���� ����������� � ��������� �� ������������ ������ ������ � �� ����������� ����������
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
 * ----------------- ����� ������ -----------------
 */

int PickTask (void) {
	int TaskNumber = 0;
	printf ("\n������� ����� �������� ������ (1-50) ��� 0 ��� ������: ");
	if (scanf ("%d", &TaskNumber) !=1) {
		printf ("������� �� ����� �����. ������� ����� �����. ���������� ��� ���...\n");
		scanf("%*[^\n]");
		return 0xBAADF00D;
	}
	if (TaskNumber == 0) {
		printf ("������� �� ���������...\n");
		scanf("%*[^\n]");
		return 0xABADBABE;
	}	
    else if ((TaskNumber < 1) || (TaskNumber > 50)) {
		printf ("������� ����� ��� ���������� ���������. ���������� ��� ���...\n");
		scanf("%*[^\n]");
		return 0xBAADF00D;
	} 	
	else {
		printf ("�� ��������� ������ � %d\n", TaskNumber); 
		return TaskNumber;
	}
}

/*
 * ----------------- ������ ������ -----------------
 */

int RunTask (int TaskNumber) {
	printf ("�������� ���������� ������ � %d...\n\n", TaskNumber);
	switch (TaskNumber) {
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	default:
		printf ("���� ������ ������ ������ � 1 � 2. ������� ������ �����...\n");
		break;
		return 1;
	}
}

/* ----------------- ������ � 1 -----------------
 *    ������� �� ����� ��������� �Hello World!
 */

int Task1 (void) {
	printf ("������ � 1. ������� �� ����� ��������� �Hello World!\"\n");
	printf ("Hello World!\n");
	return 0;
}

/* ----------------- ������ � 2 -----------------
 * ������� �� ����� ��� ����� ����� � �������, �������� �����
 */

int Task2 (void) {
	int number3, number2, number1;
	printf ("������ � 2. ������� �� ����� ��� ����� ����� � �������, �������� �����\n");
	printf ("������� 3 ����� ���� int ����� ������: ");
	if (scanf ("%d%d%d", &number1, &number2, &number3) !=3) {
	printf ("��� ������� ���� ��������� �������� �� ����� �����. ������� ����� �����. ���������� ��� ���...\n");
		scanf("%*[^\n]");
		return 1;
	}
	else {
		printf ("������� ����� � �������� �������: %d %d %d\n", number3, number2, number1);
		return 0;
	}
}