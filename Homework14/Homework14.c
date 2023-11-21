#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 19
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

//선택정렬 
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	int MoveCount = 0; //이동횟수
	int CompareCount = 0; //비교횟수 

	for (i = 0; i < n - 1; i++) {
		least = i;
		// 최솟값 탐색
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least]) least = j;
			CompareCount++;
		}
		SWAP(list[i], list[least], temp);
		MoveCount++;

	}

	//정렬 후 출력
	for (int i = n - 1; i > 0; i--) {
		printf("%2d", list[i]);
	}

	printf("MoveCount:%d\n", MoveCount);
	printf("CompareCount:%d\n", CompareCount);
}


//삽입 정렬 
void insertion_sort(int list[], int n)
{
	int i, j, key;
	int MoveCount = 0; //이동횟수
	int CompareCount = 0; //비교횟수 

	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
			CompareCount++;
		}
		list[j + 1] = key;
		MoveCount++;
	}

	//정렬 후 출력
	for (int i = n - 1; i > 0; i--) {
		printf("%2d", list[i]);
	}

	printf("MoveCount:%d\n", MoveCount);
	printf("CompareCount:%d\n", CompareCount);
}

//버블 정렬 
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	int MoveCount = 0; //이동횟수
	int CompareCount = 0; //비교횟수 

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) 	// 앞뒤의 레코드를 비교한 후 교체
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				CompareCount++;
			}
		MoveCount++;
		printf("%d ", list[i]);
	}

	//정렬 후 출력
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
	for (i = 1; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99
	printf("Original List\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	printf("선택정렬\n");
	selection_sort(list, n);
	printf("\n");

	printf("삽입정렬\n");
	insertion_sort(list, n);
	printf("\n");

	printf("버블정렬\n");
	bubble_sort(list, n);
	printf("\n");




	return 0;
}