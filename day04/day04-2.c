#include <stdio.h>

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("swap : %d %d\n", *a, *b);
}

int main() {
	int a = 1;
	int b = 2;

	printf("before swap : %d %d\n", a, b);
	swap(&a, &b);
	printf("after swap : %d %d\n", a, b);
	return 0;
}

