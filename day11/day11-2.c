#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void integral(int a, int b, int n) {
	float f, sum = 0.0;

	//���簢�� ���� ���
	for (int i = 0; i <= n; i++) { // i = 0���� �ִ� n���� ����
		int interval = pow(2, i); // ���� �� = 2^i
		float h = (float)(b - a) / interval; // ���� ���

		sum = 0.0; // �� �ݺ����� sum �ʱ�ȭ

		// ���簢�� ���� �ջ�
		for (int j = 0; j < interval; j++) {
			float x = a + j * h;
			f = log10(1 / x) + sin(x); // f(x) ���
			sum += f * h; // ���� ����
		}
		printf("����:	%d		, ���� ���: %.6f\n", interval, sum);
	}
}

int main(void) {
	int a=10, b=30, n;
	//n: ������ ���簢���� ��

	printf("������ ���� �� :%d\n", a);
	printf("������ �� �� : %d\n", b);
	printf("������ �ִ� ������ �Է��ϼ���(2^n) : ");
	scanf_s("%d", &n);

	integral(a, b, n);

	return 0;
}