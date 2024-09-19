#include <stdio.h>

int fac(int num);

int main() {
	int num;

	printf("계산할 팩토리얼 값 입력: ");
	scanf_s("%d", &num);
	int result = fac(num);
	printf("결과: %d\n", result);

	return 0;
}

//main의 num과 fac의 num은 상관없음
int fac(int num) {
	int result = 0;

	if (num == 0 || num == 1) {
		return 1;
	}
	return num * fac(num - 1);
}