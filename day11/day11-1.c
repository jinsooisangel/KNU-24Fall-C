#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
 //이차방정식 근 계산
  
//근의 공식 (-b+-루트(b^2-4ac))/2a 계산
void Calculate_root(float a, float b, float c, float* root_a, float* root_b, float* D) {
	*D = pow(b ,2) - 4 * a * c;
	if (*D >= 0) {
		*root_a = (-b + sqrt(*D)) / (2 * a);
		*root_b = (-b - sqrt(*D)) / (2 * a);
	}
}

//중근, 허근 판별
void decide_root(float root_a, float root_b, float D) {
	if (D < 0) {
		printf("두 근 모두 허근 입니다. ");
	}
	else if (root_a == root_b) {
		printf("근은 %.2f 입니다. ", root_a);
	}
	else {
		printf("근은 %.2f, %.2f 입니다.", root_a, root_b);
	}
}

int main() {
	float a, b, c;
	float root_a = 0, root_b = 0, D = 0;

	printf("이차방정식 ax^2 + bx + c 에서 a, b, c 를 입력하세요(공백으로 구분): ");
	scanf_s("%f %f %f", &a, &b,&c);
	printf("--------------------------------------------------\n");

	//원래값에 접근하기 위해 포인터 사용
	Calculate_root(a, b, c, &root_a, &root_b, &D);
	decide_root(root_a, root_b, D);

	return 0;
}