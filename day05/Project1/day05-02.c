#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	char name[100];//이름
	int snum;//학번
	int score;//점수
};

int main() {
	int N; //학생 수
	printf("학생수를 입력하세요. :");
	scanf_s("%d", &N);//학생수 받기

	//malloc
	struct Student* p = (struct Student*)malloc(N * sizeof(struct Student));

	//scanf_s-> info
	for (int i = 0;i < N;i++) {
		printf("학생 %d의 이름을 입력하세요: ", i + 1);
		scanf_s("%s", p[i].name, 100);

		printf("학생 %d의 학번을 입력하세요: ", i + 1);
		scanf_s("%d", &p[i].snum);

		printf("학생 %d의 점수를 입력하세요: ", i + 1);
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
	printf("최댓값: %d\n", max);
	printf("최소값: %d\n", min);
	printf("평균값: %.2f\n", aver);

	free(p);

	return 0;
}