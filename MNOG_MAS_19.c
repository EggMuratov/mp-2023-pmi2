#include <stdio.h>
#include <stdlib.h>

void count_otsenki(int** A, int n, int m, int* neyavka, int* neud, int* ud, int* xor, int* otl) {
    // �������� �������� ������
    *neyavka = 0;
    *neud = 0;
    *ud = 0;
    *xor = 0;
    *otl = 0;

    // ������� ���������� ������ ��� ������� ��������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
        {
            if (A[i][j] == 1) {
                (*neyavka)++;
            }
            else if (A[i][j] == 2) {
                (*neud)++;
            }
            else if (A[i][j] == 3) {
                (*ud)++;
            }
            else if (A[i][j] == 4) {
                (* xor)++;
            }
            else if (A[i][j] == 5) {
                (*otl)++;
            }
        }
    }
}

int main() {
    int n; // ���������� ���������
    int m = 3; // ���������� ���������

    printf("Enter the number of students: ");
    scanf_s("%d", &n);

    // �������� ������ ��� ������� ������
    int** A = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(m * sizeof(int));
    }

    // ������ ������ �� �������
    for (int i = 0; i < n; i++) {
        printf("Enter otsenku for student %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &A[i][j]);
        }
    }

    // ���������� ��� �������� ���������� ������
    int neyavka, neud, ud, xor, otl;

    // �������� ������� ��� �������� ������
    count_grades(A, n, m, &neyavka, &neud, &ud, &xor, &otl);

    // ����������� ���������� ������
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    // ������� ���������
    printf("Neyavka: %d\n", neyavka);
    printf("Neudovletvoritelno: %d\n", neud);
    printf("Udovletvoritelno: %d\n", ud);
    printf("xorosho: %d\n", xor);
    printf("Otlihno: %d\n", otl);

    return 0;
}