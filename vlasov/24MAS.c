#include <stdio.h>

#define MAX_SIZE 100

int hasDuplicates(int a[], int size) {
    // ��� �������� ���������� � ����������� ��������� ���������� ������ ���������
    int mass[MAX_SIZE] = { 0 };

    // ���������� ��� �������� ������� � ����������� ye;ysq �������
    for (int i = 0; i < size; i++) {
        mass[a[i]]++;
    }

    // ���������, ���� �����-���� ������� ������ 1, �� ������� ������������� ��������
    for (int i = 0; i < MAX_SIZE; i++) {
        if (mass[i] > 1) {
            return 1; // ���� ������������� ��������
        }
    }

    return 0; // ��� ������������� ���������
}

int main() {
    int size;
    printf("vvedite razmer massiva: ");
    scanf_s("%d", &size);

    int a[MAX_SIZE];
    printf("vvedite elementi massiva: ");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &a[i]);
    }

    if (hasDuplicates(a, size)) {
        printf("V massive ect' povtoryauhiecya elementi.\n");
    }
    else {
        printf("V massive net povtoryauhixcya elementov.\n");
    }

    return 0;
}