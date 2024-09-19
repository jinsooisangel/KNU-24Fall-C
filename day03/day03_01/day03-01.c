#include <stdio.h>

int prime_number(int num);

int main() {
	int number;
	printf("소수인지 확인할 수를 입력하시오. : ");
	scanf_s("%d", &number);

	if (prime_number(number)) {
		printf("소수입니다.");
	}
	else {
		printf("소수가 아닙니다.");
	}
	return 0;
}

int prime_number(int num) 
{
	if (num < 2) 
	{
		return 0;
	}

	for (int i = 2; i <= num / 2; i++) 
	{ 
		return 0; 
	}

	return 1;
}