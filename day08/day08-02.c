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

	printf("배열출력: \n");

	//=를 넣게 되면 배열을 초과한 메모리에 저장된 쓰레기값을 출력하게됨
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
		//배열이름[행][열]
		//value=메모리 주소에 저장된 값
		int value = arr[y][x];

		//메모리 주소에 저장된 값을 출력함
		printf("현재위치 : (%d %d), 배열의 값 : %d\n",y,x,value);

		//가로: value를 가로의 길이(10)로 나머지(는 항상 0~9임=> 배열의 크기를 넘지 않음)
		int xMove = x + value % SIZE;
		//세로: value를 가로의 길이(10)로 나눈 몫
		int yMove = y + value / SIZE;
		//value = 13이면 xMove = 나머지 = 3이고 yMove = 몫 = 1
		//■■■■■■■■■■ <- yMove
		//■■■□□□□□□□ <- xMove

		if (xMove >= SIZE || yMove >= SIZE) {
			printf("\n더 이상 이동할 수 없습니다.\n");
			break;
		}
		x = xMove;
		y = yMove;
	}
	int finalValue = arr[y][x];
	printf("종료 위치 : (%d, %d), 배열의 값 ; %d\n", y, x, finalValue);
}

int main() {
	int array[SIZE][SIZE];

	fillRandom(array); //배열 랜덤 초기화
	printArray(array); //배열 출력
	movePointer(array);//포인터를 이용한 이동

	return 0;
}