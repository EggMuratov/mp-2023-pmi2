#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

void command()
{
	printf("�������� ������\n");
	printf("1 - �������� �������\n");
	printf("2 - ������������ ����� �����\n");
	printf("3 - ���������� � ��������� ������\n");
	printf("4 - �������� ���\n");
}

void art()
{
	printf("������� ������  8460 - ���������� �������� Snickers\n");
	printf("������� ������  7376 - ������� Oreo\n");
	printf("������� ������  2568 - ������ ������� � ������\n");
	printf("������� ������  4320 - ��������� Coca Cola\n");
	printf("������� ������  9126 - ������ Dirol\n");
	printf("\n�������� ����� ������\n");
}

void scan(int n, int* tovar , int code[], int count[], int check[], int* a, int* b)
{
	int i, k = 0, f = 0;
	printf("\n������� ������� ������������� ��� ������\n");
	scanf_s("%d", tovar);
	for (i = 0;i < n;i++)
	{
		if (code[i] == *tovar)
		{
			*b = i;
			count[i]++;
			for (i = 0;i < 100;i++)
			{
				if (check[i] == *tovar)
					f++;
			}
			if (f == 0)
			{
				check[*a] = *tovar;
				(*a)++;
			}
			k++;
			break;
		}
	}
	if (k == 0)
		printf("������ ������ �� ����������\n");
	k = 0;
	printf("\n�������� ����� ������\n");
}

void inf(int n, int* tovar ,int code[], int stoimost[], int skidka[])
{
	int i;
	for (i = 0;i < n;i++)
	{
		if (code[i] == *tovar)
		{
			printf("��������� ��� ������ - %d\n", stoimost[i]);
			printf("������ - %d\n", skidka[i]);
			printf("��������� �� ������� - %.2lf\n", (double)stoimost[i] * (1 - (double)skidka[i] / 100));
		}
	}
	printf("\n�������� ����� ������\n");
}

void chek(int n, int code[], int stoimost[], int skidka[], int count[], double sum, int check[])
{
	int i,j;
	printf("��� ������ ���������� ������ ���������\n");
	for (i = 0; check[i]!=0 ;i++)
	{
		for (j = 0;j < n;j++)
		{
			if (code[j] == check[i])
				break;
		}
		if(count[j]!=0)
		{
			printf("   %d ", code[j]);
			printf("       %d ", count[j]);
			printf("        %d ", skidka[j]);
			printf("    %.2lf \n", (double)(stoimost[j] * (1 - (double)skidka[j] / 100)) * count[j]);
			sum += ((double)stoimost[j] * (1 - (double)skidka[j] / 100)) * count[j];
		}
	}
	printf("\n");
	printf("����� %.2lf\n", sum);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int code[10] = { 8460,7376,2568,4320,9126 };
	int stoimost[10] = { 847,2366,316,3208,1617 };
	int count[10] = { 0 };
	int skidka[10];
	int i, n = 10, g, tovar = 0, k = 0;
	double sum = 0;
	int check[100] = { 0 };
	int a = 0,  b = -1;
	for (i = 0;i < n;i++)
	{
		skidka[i] = 1 + rand() % 10;
	}
	command();
	do
	{
		scanf_s("%d", &g);
		switch (g)
		{
		case 1:
		{
			art();
			break;
		}
		case 2:
		{
			scan(n, &tovar, code, count, check, &a, &b);
			break;
		}
		case 3:
		{
			inf(n, &tovar ,code, stoimost, skidka);
			break;
		}
		case 4:
		{
			chek(n, code, stoimost, skidka, count, sum, check);
			break;
		}
		default:
		{
			printf("��� ����� �������\n");
			printf("\n�������� ����� ������\n");
			break;
		}
		}
	} while (g != 4);
	return 0;
}
