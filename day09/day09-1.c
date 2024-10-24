#include <stdio.h>

struct Vector
{
	int x, y, z;
};

//합
void vectorSum(struct Vector* v1, struct Vector* v2, struct Vector* result) {
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
	result->z = v1->z + v2->z;
}
//차
void vectorSub(struct Vector* v1, struct Vector* v2, struct Vector* result) {
	result->x = v1->x - v2->x;
	result->y = v1->y - v2->y;
	result->z = v1->z - v2->z;
}
//내적
int vectorIn(struct Vector* v1, struct Vector* v2) {
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}
//외적
void vectorOut(struct Vector* v1, struct Vector* v2, struct Vector* result) {
	result->x = v1->y * v2->z - v1->z * v2->y;
	result->y = v1->z * v2->x - v1->x * v2->z;
	result->z = v1->x * v2->y - v1->y * v2->x;
}

int main() {
	struct Vector vectors[2];//입력된 두 벡터 값을 저장
	struct Vector result;//두 벡터의 연산값을 저장
	int input;

	for (int i= 0;i < 2;i++) {
		printf("%d 번째 벡터(x, y, z): ",i+1);
		scanf_s("%d %d %d", &vectors[i].x, &vectors[i].y, &vectors[i].z);
	}
	printf("\n");
	for (int i= 0;i < 2;i++) {
		printf("입력된 %d 번째 벡터: %d, %d, %d\n", i+1, vectors[i].x, vectors[i].y, vectors[i].z);
		printf("\n");
	}

	printf("---------------------------------\n");
	printf("1. 벡터의 합\n");
	printf("2. 벡터의 차\n");
	printf("3. 벡터의 내적\n");
	printf("4. 벡터의 외적\n");
	printf("5. 종료\n");
	printf("---------------------------------\n");
	printf("명령입력: ");
	scanf_s("%d", &input);
	printf("---------------------------------\n");

	switch (input)
	{
	case 1:
		vectorSum(&vectors[0], &vectors[1], &result);
		printf("벡터의 합은 (x: %d, y: %d, z: %d) 입니다.\n", result.x, result.y, result.z);
		break;
	case 2:
		vectorSub(&vectors[0], &vectors[1], &result);
		printf("벡터의 차는 (x: %d, y: %d, z: %d) 입니다.\n", result.x, result.y, result.z);
		break;
	case 3: {
		//case 뒤에 변수 선언 시 {} 괄호 필수
		int in = vectorIn(&vectors[0], &vectors[1]);
		vectorIn(&vectors[0], &vectors[1]);
		printf("벡터의 내적은 %d 입니다.\n", in);
		break;
	}
	case 4:
		vectorOut(&vectors[0], &vectors[1], &result);
		printf("벡터의 외적은 (x: %d, y: %d, z: %d) 입니다.\n", result.x, result.y, result.z);
		break;
	case 5:
		printf("프로그램을 종료합니다.\n");
		break;
	default:
		printf("잘못된 입력입니다.\n");
	}
	return 0;
}