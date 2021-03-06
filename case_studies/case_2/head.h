#include<stdio.h>
#include<stdlib.h>

int size,*data;

void swap(int*, int*);
int partition(int, int);
void insertData();
void sort(int, int);
int getMin();
int getMax();
int getMed();
int getQ1();
int getQ2();

void insertData() {
	int i;
	printf("\nEnter size: ");
	scanf("%d", &size);
	data = (int *)calloc(sizeof(int), size);
	for(i = 0; i < size; i++) {
		printf("Enter Data: ");
		scanf("%d", &data[i]);
	}
	sort(0, size - 1);
}

void sort(int lb, int ub) {
	int j;
	if(lb < ub) {
		j = partition(lb, ub);
		sort(lb, j-1);
		sort(j+1, ub);
	}
}

int partition(int lb, int ub) {
	int pivot, left, right;
	pivot = data[lb];
	left  = lb;
	right  = ub;
	while(left < right) {
		while(data[left] <= pivot && left < ub)
			left++;
		while(data[right] > pivot)
			right--;
		if(left < right)
			swap(&data[left], &data[right]);
	}
	swap(&data[lb], &data[right]);
	return right;
}

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int getMin() {
	return data[0];
}

int getMax() {
	return data[size - 1];
}

int getMed() {
	return data[(size / 2) - 1];
}

int getQ1() {
	return data[(size / 4) - 1];
}

int getQ2() {
	return data[((size * 3) / 4) - 1];
}
