# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int* A, int p, int r) {
	int i = p-1; int j, temp;

	for (j = p; j < r; j++) {
		if (A[j] < A[r]) {
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
void quickSort(int *A, int p, int r) {
	if (p  < r) {
		int q = partition(A, p, r); 
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int main(void) {

	int* A;
	int n, i;

	scanf("%d", &n);
	A = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	quickSort(A, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
	return 0;

}