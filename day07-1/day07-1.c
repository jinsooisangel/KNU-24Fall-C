#include <stdio.h>

int main() {
	int Num = 4;

	printf("%d�� �Ƕ�̵�\n", Num);
    // i=�Ƕ�̵� ��, j=����, k=��
    for (int i = 0; i < Num; i++)
    {
        for (int k = i; k < (Num - 1); k++)
        {
            printf(" ");
        }
        for (int k = 0; k <= (i * 2); k++)
        {
            printf("*");
        }
        printf("\n");
    }
	return 0;
}