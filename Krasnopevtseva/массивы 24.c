#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h> 
int main()
{
	setlocale(LC_CTYPE, "Russian");
	const int size = 10;
	int array[10], kol=0;
	printf("������� ������ �� 10 ���������\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &array[i]);
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d " , array[i]);
	}
	for (int i = 0; i < size; i++)
		for (int m = 0; m < size; m++)
			if (array[m] == array[i] && m != i)
				kol++;
	if (kol == 0)
		printf("���������� ��������� ��� \n");
	else
	{
		printf("���������� ���� � ���������� " "%d " "����", kol);
	}
	return 0;
}