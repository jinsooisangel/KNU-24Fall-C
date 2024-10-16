#include <stdio.h>
#include <string.h>

int main() {

	char input[100];
	int len = 0;

	printf("문자열을 입력하세요(공백/특수문자 제외, 영어만 입력): ");
	scanf_s("%s", input,100);
	
	len = strlen(input);

	printf("뒤집어진 문자열: ");
	for (int i = len - 1;i >= 0;i--) { //i--랑 --i의 차이점
		printf("%c", input[i]);
	}
	printf("\n");

	return 0;
}