#include <stdio.h>

int main() {

	printf("원하는 기능을 입력하세요.\n");
	printf("1. 더하기 2. 빼기 3. 곱하기 4. 나누기\n");
	printf("기능: ");

	int oper;
	scanf_s("%d",&oper);

	double num1, num2;
	printf("숫자 1: ");
	scanf_s("%lf",&num1);

	printf("숫자 2: ");
	scanf_s("%lf",&num2);

	double result;
	if (oper == 1) {
		result = num1 + num2;
	}
	else if (oper == 2) {
		result = num1 - num2;
	}
	else if (oper == 3) {
		result = num1 * num2;
	}
	else
	{
		result = num1 / num2;
	}
	printf("결과= %lf\n",result);

	return 0;
}