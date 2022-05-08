# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
	int id;
	int korean, english, math;
};
void SelectionSortDescendingByEnglish(struct Student* arr, int n) {
	int i, j;
	Student temp;
	for (i = 0; i < n - 1; i++) {
		int max_idx = 0;

		for (j = 0; j < n - i; j++) {
			if (arr[max_idx].english > arr[j].english)
				max_idx = j;
		}

		temp = arr[max_idx];
		arr[max_idx] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
}
void SelectionSortDescendingByMath(struct Student* arr, int n) {
	int i, j;
	Student temp;
	for (i = 0; i < n - 1; i++) {
		int max_idx = 0;

		for (j = 0; j < n - i; j++) {
			if (arr[max_idx].math > arr[j].math)
				max_idx = j;
		}

		temp = arr[max_idx];
		arr[max_idx] = arr[n - i - 1];
		arr[n - i - 1] = temp;
	}
}

void bubbleSortAscendingById(struct Student* arr, int n) {
	int i, j;
	struct Student temp;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j].id > arr[j + 1].id) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int partition(struct Student* A, int p, int r) {
	int i = p - 1; int j;
	struct Student temp;

	for (j = p; j < r; j++) {
		if (A[j].korean > A[r].korean) {
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	i++;
	temp = A[i];
	A[i] = A[r];
	A[r] = temp;

	return i;
}
void quickSort(struct Student* A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}


int main(void) {
	int n, i;
	int choice = 0;
	printf("학생 수를 입력하세요 : ");
	scanf("%d", &n);

	struct Student* p;
	p = (struct Student*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		p[i].id = i + 1;
		p[i].korean = rand() % 101;
		p[i].english = rand() % 101;
		p[i].math = rand() % 101;
	}
	for (i = 0; i < n; i++)
		printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", p[i].id, p[i].english, p[i].math, p[i].korean);

	while (1) {

		printf("\n정렬 기준 선택<1:국어, 2:수학, 3:영어, 4:id<오름차순>, 0:끝내기> : ");
		scanf("%d", &choice);
		if (choice == 1)
			quickSort(p, 0, n - 1);
		else if (choice == 2)
			SelectionSortDescendingByMath(p, n);
		else if (choice == 3)
			SelectionSortDescendingByEnglish(p, n);
		else if (choice == 4)
			bubbleSortAscendingById(p, n);
		else
			break;
		for (i = 0; i < n; i++)
			printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", p[i].id, p[i].english, p[i].math, p[i].korean);
	}

	free(p);
	return 0;
}