#include <stdio.h>

int if_prime_number(int num);

int main() {
	int number;
	printf("�Ҽ����� Ȯ���� ���� �Է��Ͻÿ�. : ");
	scanf_s("%d", &number);

	if (if_prime_number(number)) {
		printf("result = 1");
	}
	else {
		printf("result = 0");
	}
	return 0;
}

int if_prime_number(int num) 
{
	if (num < 2){
		return 0;
	}

	for (int i = 2; i <= num / 2; i++) { 
		return 0; 
	}

	return 1;
}