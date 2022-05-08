# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student {
	int id;
	int korean, english, math;
};
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

	struct Student* A;
	int n, i;

	scanf("%d", &n);
	A = (struct Student*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++) {
		A[i].id = i + 1;
		A[i].english = rand() % 101;
		A[i].math = rand() % 101;
		A[i].korean = rand() % 101;
	}

	for (i = 0; i < n; i++)
		printf("학생의 학번 %2d 영어 %2d 수학 %2d 국어 %2d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	printf("\n");

	quickSort(A, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("학생의 학번 %2d 영어 %2d 수학 %2d 국어 %2d\n", A[i].id, A[i].english, A[i].math, A[i].korean);

	free(A);
	return 0;

}