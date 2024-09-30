#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void) {

	double x = 0;
	double y = 0;

	int count = 0, circle = 0;

	srand(time(NULL));

	while (count < 10000) {
		x = (double)rand() / (double)RAND_MAX;
		y = (double)rand() / (double)RAND_MAX;
		count++;
	}
}