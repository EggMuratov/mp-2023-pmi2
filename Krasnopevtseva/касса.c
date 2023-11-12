#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
#include <stdbool.h>
//����������� ������� :
// [0] - �������
// [1] - ������ � �������
// [2] - ������� � ���������
// [3] - ���� ��������
// [4] - ������� ����������

int sh[5] = { 2371, 8552, 9673, 4564, 1375 };
int cost[5] = {99, 49, 79, 399, 239};
double discount[5] = { 1.0, 1.0, 1.0, 1.30, 1.10 };
int kol[5] = { 0 };
double final_cost[5] = {0};
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
	printf("[1] - �������\n");
	printf("���� - ""%d\n", cost[0]);
	printf("�����-��� - ""%d\n", sh[0]);
	printf("������ - ""%lf\n", discount[0]);
	printf("\n");
	printf("[2] - ������ � �������\n");
	printf("���� - ""%d\n", cost[1]);
	printf("�����-��� - ""%d\n", sh[1]);
	printf("������ - ""%lf\n", discount[1]);
	printf("\n");
	printf("[3] - ������� � ���������\n");
	printf("���� - ""%d\n", cost[2]);
	printf("�����-��� - ""%d\n", sh[2]);
	printf("������ - ""%lf\n", discount[2]);
	printf("\n");
	printf("[4] - ���� ��������\n");
	printf("���� - ""%d\n", cost[3]);
	printf("�����-��� - ""%d\n", sh[3]);
	printf("������ - ""%lf\n", discount[3]);
	printf("\n");
	printf("[5] - ������� ����������\n");
	printf("���� - ""%d\n", cost[4]);
	printf("�����-��� - ""%d\n", sh[4]);
	printf("������ - ""%lf\n", discount[4]);
	printf("\n");
	printf("����� ����� �������)\n");
}
void scan(int product, int sh[], double discount[], int kol[], double final_cost[])
{
	printf("������� �����-��� ������\n");
	scanf_s("%d", &product);
	for (int i = 0; i < 5; i++)
	{
		if (product == sh[i])
		{
			kol[i]++;
			final_cost[i] = cost[i] * discount[i];

			if (i == 0)
			{
				printf("�������������: �������\n");
				printf("���� ��� ������:" "%d\n", cost[0]);
				printf("���� �� �������:" "%lf\n", final_cost[0]);
			}
			if ((product == sh[i]) && (i == 1))
			{
				printf("�������������: ������ � �������\n");
				printf("���� ��� ������:" "%d\n", cost[1]);
				printf("���� �� �������:" "%lf\n", final_cost[1]);
			}
			if ((product == sh[i]) && (i == 2))
			{
				printf("�������������: ������� � ���������\n");
				printf("���� ��� ������:" "%d\n", cost[2]);
				printf("���� �� �������:" "%lf\n", final_cost[2]);
			}
			if ((product == sh[i]) && (i == 3))
			{
				printf("�������������: ���� ��������\n");
				printf("���� ��� ������:" "%d\n", cost[3]);
				printf("���� �� �������:" "%lf\n", final_cost[3]);
			}
			if ((product == sh[i]) && (i == 4))
			{
				printf("�������������: ������� ����������\n");
				printf("���� ��� ������:" "%d\n", cost[4]);
				printf("���� �� �������:" "%lf\n", final_cost[4]);
			}
		}
		else
		{
			printf("����� � ����� �����-����� �� � ������� :(\n");
		}
	}
	printf("\n");
	printf("����� ����� �������)\n");
}
void paycheck(int kol[], double final_cost[],double sum)
{
	printf("�������� ���:\n");
	for (int i = 0; i < 5; i++)
	{
		if (kol[i]!=0)
		{
			if (i == 0)
			{
				final_cost[i] *= kol[i];
				printf(" ������� - ""%d" "��. - ""%lf " "���.\n",kol[i],final_cost[i]);
				
			}
			if (i == 1)
			{
				final_cost[i] *= kol[i];
				printf(" ������ � ������� - ""%d" "��. - ""%lf ""���.\n", kol[i], final_cost[i]);
			}
			if (i == 2)
			{
				final_cost[i] *= kol[i];
				printf(" ������� � ��������� - ""%d" "��. - ""%lf ""���.\n", kol[i], final_cost[i]);
			}
			if (i == 3)
			{
				final_cost[i] *= kol[i];
				printf(" ���� �������� - ""%d" "��. - ""%lf ""���.\n", kol[i], final_cost[i]);
			}
			if (i == 4)
			{
				final_cost[i] *= kol[i]; 
				printf(" ������� ���������� - ""%d" "��. - ""%lf ""���.\n", kol[i], final_cost[i]);
			}
			sum += final_cost[i];
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
