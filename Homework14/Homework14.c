#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 19
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

//�������� 
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	int MoveCount = 0; //�̵�Ƚ��
	int CompareCount = 0; //��Ƚ�� 

	for (i = 0; i < n - 1; i++) {
		least = i;
		// �ּڰ� Ž��
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least]) least = j;
			CompareCount++;
		}
		SWAP(list[i], list[least], temp);
		MoveCount++;

	}

	//���� �� ���
	for (int i = n - 1; i > 0; i--) {
		printf("%2d", list[i]);
	}

	printf("MoveCount:%d\n", MoveCount);
	printf("CompareCount:%d\n", CompareCount);
}


//���� ���� 
void insertion_sort(int list[], int n)
{
	int i, j, key;
	int MoveCount = 0; //�̵�Ƚ��
	int CompareCount = 0; //��Ƚ�� 

	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
			CompareCount++;
		}
		list[j + 1] = key;
		MoveCount++;
	}

	//���� �� ���
	for (int i = n - 1; i > 0; i--) {
		printf("%2d", list[i]);
	}

	printf("MoveCount:%d\n", MoveCount);
	printf("CompareCount:%d\n", CompareCount);
}

//���� ���� 
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	int MoveCount = 0; //�̵�Ƚ��
	int CompareCount = 0; //��Ƚ�� 

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) 	// �յ��� ���ڵ带 ���� �� ��ü
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				CompareCount++;
			}
		MoveCount++;
		printf("%d ", list[i]);
	}

	//���� �� ���
	for (int i = n - 1; i > 0; i--) {
		printf("%2d", list[i]);
	}

	printf("MoveCount:%d\n", MoveCount);
	printf("CompareCount:%d\n", CompareCount);
}




int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 1; i < n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	printf("Original List\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	printf("��������\n");
	selection_sort(list, n);
	printf("\n");

	printf("��������\n");
	insertion_sort(list, n);
	printf("\n");

	printf("��������\n");
	bubble_sort(list, n);
	printf("\n");




	return 0;
}