#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	char name[100];//�̸�
	int snum;//�й�
	int score;//����
};

int main() {
	int N; //�л� ��
	printf("�л����� �Է��ϼ���. :");
	scanf_s("%d", &N);//�л��� �ޱ�

	//malloc
	struct Student* p = (struct Student*)malloc(N * sizeof(struct Student));

	//scanf_s-> info
	for (int i = 0;i < N;i++) {
		printf("�л� %d�� �̸��� �Է��ϼ���: ", i + 1);
		scanf_s("%s", p[i].name, 100);

		printf("�л� %d�� �й��� �Է��ϼ���: ", i + 1);
		scanf_s("%d", &p[i].snum);

		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", p[i].score);
	}

	//aver
	int max = p[0].score, min = p[0].score, sum = 0;
	for (int i = 0;i < N;i++) {
		if (p[i].score > max) {
			max = p[i].score;
		}
		if (p[i].score < min) {
			min = p[i].score;
		}
		sum += p[i].score;
	}
	float aver = (float)sum / N;

	//printf
	printf("***********************\n");
	printf("�ִ�: %d\n", max);
	printf("�ּҰ�: %d\n", min);
	printf("��հ�: %.2f\n", aver);

	free(p);

	return 0;
}