#include <stdio.h>
#include <stdlib.h>

int main() {
	int N; //학생 수
	char** name;//이름
	int* snum;//학번
	int* score;//점수

	printf("학생수를 입력하세요. :");
	scanf_s("%d",&N);//학생수 받기

	//malloc
	name = (char**)malloc(N * sizeof(char*));
	for (int i = 0;i < 2;i++) {
		name[i] = (char**)malloc(100 * sizeof(char));
	}

	snum = (int*)malloc(N * sizeof(int));
	score = (int*)malloc(N * sizeof(int));


	//scanf_s-> info
	for (int i = 0;i < N;i++) {
		printf("학생 %d의 이름을 입력하세요: ",i+1);
		scanf_s("%s", name[i],100);

		printf("학생 %d의 학번을 입력하세요: ", i + 1);
		scanf_s("%d", &snum[i]);

		printf("학생 %d의 점수를 입력하세요: ", i + 1);
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
	printf("최댓값: %d\n", max);
	printf("최소값: %d\n", min);
	printf("평균값: %f\n", aver);

	free(name);
	free(snum);
	free(score);
	for (int i = 0;i < N;i++) {
		free(name[i]);
	}

	return 0;
}