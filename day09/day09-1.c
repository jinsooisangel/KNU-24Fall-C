#include <stdio.h>

struct Vector
{
	int x, y, z;
};

//��
void vectorSum(struct Vector* v1, struct Vector* v2, struct Vector* result) {
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
	result->z = v1->z + v2->z;
}
//��
void vectorSub(struct Vector* v1, struct Vector* v2, struct Vector* result) {
	result->x = v1->x - v2->x;
	result->y = v1->y - v2->y;
	result->z = v1->z - v2->z;
}
//����
int vectorIn(struct Vector* v1, struct Vector* v2) {
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}
//����
void vectorOut(struct Vector* v1, struct Vector* v2, struct Vector* result) {
	result->x = v1->y * v2->z - v1->z * v2->y;
	result->y = v1->z * v2->x - v1->x * v2->z;
	result->z = v1->x * v2->y - v1->y * v2->x;
}

int main() {
	struct Vector vectors[2];//�Էµ� �� ���� ���� ����
	struct Vector result;//�� ������ ���갪�� ����
	int input;

	for (int i= 0;i < 2;i++) {
		printf("%d ��° ����(x, y, z): ",i+1);
		scanf_s("%d %d %d", &vectors[i].x, &vectors[i].y, &vectors[i].z);
	}
	printf("\n");
	for (int i= 0;i < 2;i++) {
		printf("�Էµ� %d ��° ����: %d, %d, %d\n", i+1, vectors[i].x, vectors[i].y, vectors[i].z);
		printf("\n");
	}

	printf("---------------------------------\n");
	printf("1. ������ ��\n");
	printf("2. ������ ��\n");
	printf("3. ������ ����\n");
	printf("4. ������ ����\n");
	printf("5. ����\n");
	printf("---------------------------------\n");
	printf("����Է�: ");
	scanf_s("%d", &input);
	printf("---------------------------------\n");

	switch (input)
	{
	case 1:
		vectorSum(&vectors[0], &vectors[1], &result);
		printf("������ ���� (x: %d, y: %d, z: %d) �Դϴ�.\n", result.x, result.y, result.z);
		break;
	case 2:
		vectorSub(&vectors[0], &vectors[1], &result);
		printf("������ ���� (x: %d, y: %d, z: %d) �Դϴ�.\n", result.x, result.y, result.z);
		break;
	case 3: {
		//case �ڿ� ���� ���� �� {} ��ȣ �ʼ�
		int in = vectorIn(&vectors[0], &vectors[1]);
		vectorIn(&vectors[0], &vectors[1]);
		printf("������ ������ %d �Դϴ�.\n", in);
		break;
	}
	case 4:
		vectorOut(&vectors[0], &vectors[1], &result);
		printf("������ ������ (x: %d, y: %d, z: %d) �Դϴ�.\n", result.x, result.y, result.z);
		break;
	case 5:
		printf("���α׷��� �����մϴ�.\n");
		break;
	default:
		printf("�߸��� �Է��Դϴ�.\n");
	}
	return 0;
}