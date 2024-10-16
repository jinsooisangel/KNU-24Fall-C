#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

void fillRandom(int array[SIZE][SIZE]){

	srand(time(NULL));

	for (int i = 0;i <= SIZE;i++) {
		for (int j = 0;j <= SIZE;j++){
			array[i][j] = rand() % 21;
		}
	}
}

void printArray(int array[SIZE][SIZE]) {

	printf("�迭���: \n");

	//=�� �ְ� �Ǹ� �迭�� �ʰ��� �޸𸮿� ����� �����Ⱚ�� ����ϰԵ�
	for (int i = 0;i < SIZE;i++) {
		for (int j = 0;j <= SIZE;j++){
			printf("  %d", array[i][j]);
		}
		printf("\n");
	}
}

void movePointer(void* array) {
	int (*arr)[SIZE]=*(int(*)[SIZE])array;
	int x = 0, y = 0;

	while (1) {
		//�迭�̸�[��][��]
		//value=�޸� �ּҿ� ����� ��
		int value = arr[y][x];

		//�޸� �ּҿ� ����� ���� �����
		printf("������ġ : (%d %d), �迭�� �� : %d\n",y,x,value);

		//����: value�� ������ ����(10)�� ������(�� �׻� 0~9��=> �迭�� ũ�⸦ ���� ����)
		int xMove = x + value % SIZE;
		//����: value�� ������ ����(10)�� ���� ��
		int yMove = y + value / SIZE;
		//value = 13�̸� xMove = ������ = 3�̰� yMove = �� = 1
		//����������� <- yMove
		//����������� <- xMove

		if (xMove >= SIZE || yMove >= SIZE) {
			printf("\n�� �̻� �̵��� �� �����ϴ�.\n");
			break;
		}
		x = xMove;
		y = yMove;
	}
	int finalValue = arr[y][x];
	printf("���� ��ġ : (%d, %d), �迭�� �� ; %d\n", y, x, finalValue);
}

int main() {
	int array[SIZE][SIZE];

	fillRandom(array); //�迭 ���� �ʱ�ȭ
	printArray(array); //�迭 ���
	movePointer(array);//�����͸� �̿��� �̵�

	return 0;
}