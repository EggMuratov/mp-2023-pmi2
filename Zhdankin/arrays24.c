#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	int array[100], n = 0, r1 = 2 + rand() % 25;



	for (int i = 0; i < r1; i++)
	{
		array[i] = rand() % 10;
		printf("%i ", array[i]);
	}

	for (int i = 0; i < r1; i++)
	{
		for (int j = i+1; j < r1; j++)
		{
			if (array[i] == array[j])
			{
				n++;
				break;
			}
		}
	}
	
	if (n > 0)
	{
		printf("\n");
		printf("� ������ ������� ���� ������������� ��������.");
	}
	else
	{
		printf("\n");
		printf("������������� ��������� ���");
	}

	return(0);
}