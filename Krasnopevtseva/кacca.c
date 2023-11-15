#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <stdbool.h>
#include "string.h"
//����������� ������� :
// [0] - �������
// [1] - ������ � �������
// [2] - ������� � ���������
// [3] - ���� ��������
// [4] - ������� ����������
char names[5][30];
int sh[5] = { 2371, 8552, 9673, 4564, 1375 };
int cost[5] = { 99, 49, 79, 399, 239 };
double discount[5] = { 1.0, 1.0, 1.0, 1.30, 1.10 };
int kol[5] = { 0 };
double final_cost[5] = { 0 };
int product;
void commands()
{
	printf("1 - ������� ���������� � �������\n");
	printf("2 - �������� ����� � ���\n");
	printf("3 - ������������ ���\n");
	printf("4 - ��������� ������\n");
	printf("\n");
	printf("����� ����� �������)\n");
}
void assortment()
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", names[i]);
		printf("���� - ""%d\n", cost[i]);
		printf("�����-��� - ""%d\n", sh[i]);
		printf("������ - ""%lf\n", discount[i]);
		printf("\n");
	}
	printf("\n");
	printf("����� ����� �������)\n");
}
void scan(int product, int sh[], double discount[], int kol[], double final_cost[])
{
	printf("������� �����-��� ������\n");
	scanf_s("%d", &product);
	bool s = false;
	for (int i = 0; i < 5; i++)
	{
		if (product == sh[i])
		{
			s = true;
			kol[i]++;
			final_cost[i] = cost[i] * discount[i];
			printf("�������������:" "%s\n",names[i]);
			printf("���� ��� ������:" "%d\n", cost[i]);
			printf("���� �� �������:" "%lf\n", final_cost[i]);
		}
	}
	if (!s)
	{
		printf("����� � ����� �����-����� �� � ������� :(\n");
	}
	printf("\n");
	printf("����� ����� �������)\n");
}
void paycheck(int kol[], double final_cost[], double sum)
{
	printf("�������� ���:\n");
	for (int i = 0; i < 5; i++)
	{
		if (kol[i] != 0)
		{
			for (i = 0; i < 5; i++)
			{
				final_cost[i] *= kol[i];
				printf("%s"" -" "%d" "��. - ""%lf " "���.\n",names[i], kol[i], final_cost[i]);
				sum += final_cost[i];
			}
		}
	}
	printf("�������� ����� ������� - "  "%lf"" ���.\n", sum);
	printf("\n");
	printf("����� ����� �������)\n");
}
int main()
{
	int choice;
	double sum = 0.0;
	bool run = true;
	setlocale(LC_CTYPE, "Russian");
	printf(" ����� ���������� � ���� �������! :3\n");
	printf(" ��� � ���� ��� ������?\n");
	commands();
	strcpy_s(names[0],8, "�������");
	strcpy_s(names[1], 17, "������ � �������");
	strcpy_s(names[2], 20, "������� � ���������");
	strcpy_s(names[3], 14, "���� ��������");
	strcpy_s(names[4], 19, "������� ����������");
	while (run)
	{
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
		{	assortment();
		break; }
		case 2:
		{	scan(&product, sh, discount, kol, final_cost);
		break; }
		case 3:
		{	paycheck(kol, final_cost, sum);
		break; }
		case 4:
		{	printf("����� �������, �������� � ��� ���! <3\n");
		run = false;
		break; }
		default:
		{
			printf("������, �������� �� �������������� :(\n");
			printf("�������� ������!\n");
			break;
		}
		}
	}
	return 0;
}
