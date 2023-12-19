#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void viborSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mnindex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mnindex]) {
                mnindex = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[mnindex];
        arr[mnindex] = tmp;
    }
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void radixSort(int arr[], int n, int exp) {
    const int BASE = 10;
    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL) {
        printf("������ ��������� ������\n");
        return;
    }

    int count[BASE] = { 0 };

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % BASE]++;

    for (int i = 1; i < BASE; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
        count[(arr[i] / exp) % BASE]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    
    free(output);
}

void radixSortMain(int arr[], int n) {
    int max = findMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        radixSort(arr, n, exp);
}

void bidirectionalBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        for (int k = n - 1; k > i; k--) {
            if (arr[k] < arr[k - 1]) {
                int temp = arr[k];
                arr[k] = arr[k - 1];
                arr[k - 1] = temp;
            }
        }
    }
}
int* copyArray(int arr[],  int size) {
    int* copyArr = (int*)malloc(size * sizeof(int));
    for (int i = 0;i < size;i++) {
        copyArr[i] = arr[i];
    }
    return copyArr;
}
void cpyWithoutMem(int arr[],int cpy[], int size) {
    for (int i = 0;i < size;i++) {
        cpy[i] = arr[i];
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int* scanArray(int* size) {
    
    printf("������� ���������� �������� (n): ");
    scanf_s("%d", size);

    if (*size <= 0) {
        printf("������������ ���������� ��������\n");
        return NULL; 
    }

    
    int* arr = (int*)malloc(*size * sizeof(int));
    if (arr == NULL) {
        printf("������ ��������� ������\n");
        return NULL; 
    }

    
    printf("������� �������� ��� �������:\n");
    for (int i = 0; i < *size; i++) {
        scanf_s("%d", &arr[i]);
    }

    return arr; 
}


int* generateRandomArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("������ ��������� ������\n");
        return NULL;
    }

   
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  
    }

    return arr;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    int* arr;
    int* copyArr;
    int n;

    printf("�������� ��� ������� (1 - ��������������, 2 - ���� �������): ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1: {
        
        printf("������� ������ ��������������� �������: ");
        scanf_s("%d", &n);
        arr = generateRandomArray(n);
        copyArr=copyArray(arr, n);
        if (arr == NULL) {
            return 1;
        }
        printf("��������������� ������: ");
        printArray(arr, n);
        break;
    }
    case 2: {
        printf("������� ���������� �������� (n): ");
        scanf_s("%d", &n);
        arr = scanArray(&n);
        if (arr == NULL) {
            printf("������ ����� �������\n");
            return 1;
        }
        printf("��������� ������: ");
        printArray(arr, n);
        copyArr = copyArray(arr, n);
        break;
    }
    default:
        printf("������������ �����.\n");
        return 1;
    }
    int sortType;
    do {
        
        printf("�������� ��� ���������� (1 - ����, 2 - �����, 3 - �����������, 4 - ��������������� �����������): ");
        scanf_s("%d", &sortType);

        clock_t start, end;
        double cpu_time_used;

        switch (sortType) {
        case 1:
            cpyWithoutMem(arr, copyArr, n);
            start = clock();
            shellSort(copyArr, n);
            end = clock();
            printf("���������� �����: ");
            break;
        case 2:
            cpyWithoutMem(arr, copyArr, n);
            start = clock();
            viborSort(copyArr, n);
            end = clock();
            printf("���������� �������: ");
            break;
        case 3:
            cpyWithoutMem(arr, copyArr, n);
            start = clock();
            radixSortMain(copyArr, n);
            end = clock();
            printf("����������� ����������: ");
            break;
        case 4:
            cpyWithoutMem(arr, copyArr, n);
            start = clock();
            bidirectionalBubbleSort(copyArr, n);
            end = clock();
            printf("��������������� ����������� ����������: ");
            break;
        
        }

        printArray(copyArr, n);

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("����� ����������: %f ������.\n", cpu_time_used);
    } while ((sortType < 5) && (sortType > 0));
    free(arr);
    free(copyArr);
    return 0;
}
