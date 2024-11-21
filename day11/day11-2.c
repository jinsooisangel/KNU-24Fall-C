#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void integral(int a, int b, int n) {
	float f, sum = 0.0;

	//직사각형 넓이 계산
	for (int i = 0; i <= n; i++) { // i = 0부터 최대 n까지 실행
		int interval = pow(2, i); // 구간 수 = 2^i
		float h = (float)(b - a) / interval; // 간격 계산

		sum = 0.0; // 각 반복마다 sum 초기화

		// 직사각형 넓이 합산
		for (int j = 0; j < interval; j++) {
			float x = a + j * h;
			f = log10(1 / x) + sin(x); // f(x) 계산
			sum += f * h; // 넓이 누적
		}
		printf("구간:	%d		, 적분 결과: %.6f\n", interval, sum);
	}
}

int main(void) {
	int a=10, b=30, n;
	//n: 나누는 직사각형의 수

	printf("적분할 시작 값 :%d\n", a);
	printf("적분할 끝 값 : %d\n", b);
	printf("시행할 최대 구간을 입력하세요(2^n) : ");
	scanf_s("%d", &n);

	integral(a, b, n);

	return 0;
}