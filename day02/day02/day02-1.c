#include <stdio.h>

int main() {

	printf("���ϴ� ����� �Է��ϼ���.\n");
	printf("1. ���ϱ� 2. ���� 3. ���ϱ� 4. ������\n");
	printf("���: ");

	int oper;
	scanf_s("%d",&oper);

	double num1, num2;
	printf("���� 1: ");
	scanf_s("%lf",&num1);

	printf("���� 2: ");
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
	printf("���= %lf\n",result);

	return 0;
}