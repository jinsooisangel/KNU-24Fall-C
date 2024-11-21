#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
 //���������� �� ���
  
//���� ���� (-b+-��Ʈ(b^2-4ac))/2a ���
void Calculate_root(float a, float b, float c, float* root_a, float* root_b, float* D) {
	*D = pow(b ,2) - 4 * a * c;
	if (*D >= 0) {
		*root_a = (-b + sqrt(*D)) / (2 * a);
		*root_b = (-b - sqrt(*D)) / (2 * a);
	}
}

//�߱�, ��� �Ǻ�
void decide_root(float root_a, float root_b, float D) {
	if (D < 0) {
		printf("�� �� ��� ��� �Դϴ�. ");
	}
	else if (root_a == root_b) {
		printf("���� %.2f �Դϴ�. ", root_a);
	}
	else {
		printf("���� %.2f, %.2f �Դϴ�.", root_a, root_b);
	}
}

int main() {
	float a, b, c;
	float root_a = 0, root_b = 0, D = 0;

	printf("���������� ax^2 + bx + c ���� a, b, c �� �Է��ϼ���(�������� ����): ");
	scanf_s("%f %f %f", &a, &b,&c);
	printf("--------------------------------------------------\n");

	//�������� �����ϱ� ���� ������ ���
	Calculate_root(a, b, c, &root_a, &root_b, &D);
	decide_root(root_a, root_b, D);

	return 0;
}