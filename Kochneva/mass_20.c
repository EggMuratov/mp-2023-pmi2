#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Rus");
    int inputArray[6];
    int i, j;
    int closest = INT_MAX;
    int index1 = 0, index2 = 0;
    int targetValue;
    printf("������� 6 ��������� �������:\n");

    for (i = 0; i < 6; i++)
    {
        scanf_s("%d", &inputArray[i]);
    }

    printf("������� ������� ��������:\n");
    scanf_s("%d", &targetValue);

    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 6; j++)
        {
            int difference = abs((inputArray[i] + inputArray[j]) - targetValue);
            if (difference < closest)
            {
                closest = difference;
                index1 = i;
                index2 = j;
            }
        }
    }
    printf("���� � ��������� ������ � ������ ��������: %d � %d\n", inputArray[index1], inputArray[index2]);
    return 0;
}
