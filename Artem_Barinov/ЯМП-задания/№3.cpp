//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//
//unsigned int num1(int a) { // ��������� ����� ����� �
//	srand(time(NULL));
//
//	int* N;
//	unsigned int H = 0;
//	N = (int*)malloc(a * sizeof(int));
//	for (int i = 0; i < a; i++) {
//		N[i] = rand() % 9 + 1;
//		H += N[i] * (int)pow(10, i);
//	}
//	printf("number: %u\n", H);
//	return H;
//}
//void game(unsigned int H, int a) {// ����
//	printf("The game started!\nYou have to guess the number.\n");
//	int arr[5];
//	int N[5];
//	int HC = H;
//	for (int j = 0; j < a; j++){ N[j] = HC % 10;HC /= 10;}
//
//	int bull = 0;
//	int P = 0; // ���������� �������
//	unsigned int dig = 0;
//	do { //���� ����
//		printf("Enter a number: ");
//		scanf_s("%u", &dig);
//		
//		int digC = dig;
//		for (int j = 0; j < a; j++) {
//			arr[j] = digC % 10;
//			digC /= 10;
//		}
//
//		for (int i = 0; i < a; i++) { // ��������� ���������� ����
//			if (arr[i] == N[i]) {
//				printf("Bull! You guessed a digital of number: %d;\n", N[i]);
//				bull++;
//				continue;
//			}
//			else
//				bull = 0;
//			for (int k = 0; k < a; k++) {
//				if (arr[k] == N[i]) {
//					printf("Cow! You guessed a digital of number: %d;\n", N[i]);
//					break;
//				}
//			}
//		}
//		++P;
//	} while (bull != a);
//	printf("You win!!!\n");
//	printf("Number of attemps: %d\n", P);
//}
//int main() {
//	int a;
//	printf("Game 'Bulls and cows' begins!\n");
//	do {
//		printf("Enter a length of number with length from 2 to five: \n");
//		if (scanf_s("%d", &a) != 1) {
//			printf("Wrong simbols! Try again!\n");
//			rewind(stdin);
//			continue;
//		}
//		if (a > 1 && a < 6)
//			break;
//		else
//			printf("Wrong length! Try again!\n");
//	} while (1);
//
//	game(num1(a), a);
//	return 0;
//}