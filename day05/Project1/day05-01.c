#include <stdio.h>
#include <stdlib.h>

int main() {
	int N; //�л� ��
	char** name;//�̸�
	int* snum;//�й�
	int* score;//����

	printf("�л����� �Է��ϼ���. :");
	scanf_s("%d",&N);//�л��� �ޱ�

	//malloc
	name = (char**)malloc(N * sizeof(char*));
	for (int i = 0;i < 2;i++) {
		name[i] = (char**)malloc(100 * sizeof(char));
	}

	snum = (int*)malloc(N * sizeof(int));
	score = (int*)malloc(N * sizeof(int));


	//scanf_s-> info
	for (int i = 0;i < N;i++) {
		printf("�л� %d�� �̸��� �Է��ϼ���: ",i+1);
		scanf_s("%s", name[i],100);

		printf("�л� %d�� �й��� �Է��ϼ���: ", i + 1);
		scanf_s("%d", &snum[i]);

		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", &score[i]);

	}
	
	//aver
	int max = score[0], min = score[0], sum = 0;
	for (int i = 0;i < N;i++) {
		if (score[i] > max) {
			max = score[i];
		}
		if (score[i] < min) {
			min = score[i];
		}
		sum += score[i];
	}
	float aver = (float)sum / N;
	//printf
	printf("***********************\n");
	printf("�ִ�: %d\n", max);
	printf("�ּҰ�: %d\n", min);
	printf("��հ�: %f\n", aver);

	free(name);
	free(snum);
	free(score);
	for (int i = 0;i < N;i++) {
		free(name[i]);
	}

	return 0;
}