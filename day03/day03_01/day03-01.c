#include <stdio.h>

int prime_number(int num);

int main() {
	int number;
	printf("�Ҽ����� Ȯ���� ���� �Է��Ͻÿ�. : ");
	scanf_s("%d", &number);

	if (prime_number(number)) {
		printf("�Ҽ��Դϴ�.");
	}
	else {
		printf("�Ҽ��� �ƴմϴ�.");
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