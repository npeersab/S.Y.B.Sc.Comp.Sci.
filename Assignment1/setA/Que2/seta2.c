#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(int *, int);
void display(int *, int);
void sort(int *, int);
void swap(int *, int *);

int main() {
	int n, array[50];

	printf("Enter array size [max 50]: ");
	scanf("%d", &n);
	generate(array, n);

	printf("Unsorted array: ");
	display(array, n);

	sort(array, n);
	printf("Sorted array: ");
	display(array, n);

	return 0;
}

void generate(int *array, int size) {
	int i;

	srand(time(NULL));
	for (i = 0; i < size; i++)
		array[i] = rand() % 100; 
}

void display(int *array, int size) {
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n"); 
}

void sort(int *array, int size) {
	int i, j, temp;

	for (i = 1; i < size; i++) {
		temp = array[i];
		for (j = i - 1; j > 0 && array[j] > temp; j--)
			array[j + 1] = array[j];

		array[j + 1] = temp;
	}
}
