#include <stdio.h>

int fac(int num);

int main() {
	int num;

	printf("����� ���丮�� �� �Է�: ");
	scanf_s("%d", &num);
	int result = fac(num);
	printf("���: %d\n", result);

	return 0;
}

//main�� num�� fac�� num�� �������
int fac(int num) {
	int result = 0;

	if (num == 0 || num == 1) {
		return 1;
	}
	return num * fac(num - 1);
}