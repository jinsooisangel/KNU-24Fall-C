#include <stdio.h>
#include <string.h>

int main() {

	char input[100];
	int len = 0;

	printf("���ڿ��� �Է��ϼ���(����/Ư������ ����, ��� �Է�): ");
	scanf_s("%s", input,100);
	
	len = strlen(input);

	printf("�������� ���ڿ�: ");
	for (int i = len - 1;i >= 0;i--) { //i--�� --i�� ������
		printf("%c", input[i]);
	}
	printf("\n");

	return 0;
}