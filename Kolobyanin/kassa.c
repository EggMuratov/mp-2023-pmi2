#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

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
	for (i = 0;i < n;i++)
	{
		skidka[i] = 1 + rand() % 10;
	}
	printf("�������� ������\n");
	printf("1 - �������� �������\n");
	printf("2 - ������������ ����� �����\n");
	printf("3 - ���������� � ��������� ������\n");
	printf("4 - �������� ���\n");
	do
	{
		scanf_s("%d", &g);
		switch (g)
		{
		case 1:
		{
			printf("������� ������  8460 - ���������� �������� Snickers\n");
			printf("������� ������  7376 - ������� Oreo\n");
			printf("������� ������  2568 - ������ ������� � ������\n");
			printf("������� ������  4320 - ��������� Coca Cola\n");
			printf("������� ������  9126 - ������ Dirol\n");
			printf("\n�������� ����� ������\n");
			break;
		}
		case 2:
		{
			printf("\n������� ������� ������������� ��� ������\n");
			scanf_s("%d", &tovar);
			for (i = 0;i < n;i++)
			{
				if (code[i] == tovar)
				{
					count[i]++;
					k++;
				}
			}
			if (k == 0)
				printf("������ ������ �� ����������\n");
			k = 0;
			printf("\n�������� ����� ������\n");
			break;
		}
		case 3:
		{
			for (i = 0;i < n;i++)
			{
				if (code[i] == tovar)
				{
					printf("��������� ��� ������ - %d\n", stoimost[i]);
					printf("������ - %d\n", skidka[i]);
					printf("��������� �� ������� - %.2lf\n", (double)stoimost[i] * (1 - (double)skidka[i] / 100));
				}
			}
			printf("\n�������� ����� ������\n");
			break;
		}
		case 4:
		{
			printf("��� ������ ���������� ������ ���������\n");
			for (i = 0;i < n;i++)
			{
				if (count[i] != 0)
				{
					printf("   %d ", code[i]);
					printf("       %d ", count[i]);
					printf("        %d ", skidka[i]);
					printf("    %.2lf \n", (double)(stoimost[i] * (1 - (double)skidka[i] / 100)) * count[i]);
					sum += ((double)stoimost[i] * (1 - (double)skidka[i] / 100)) * count[i];
				}
			}
			printf("\n");
			printf("����� %.2lf\n", sum);
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
