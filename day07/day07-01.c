#include <stdio.h>

int main() {
    int Num;
    printf("���� �Է��ϼ���.: ");
    scanf_s("%d", &Num);

    if (Num <= 0) {
        printf("1�� �̻��� �Է��ϼ���.");
    }
    else if (Num >= 1) {
        printf("%d�� �Ƕ�̵� \n", Num);

        for (int i = 0; i < Num; i++)
        {
            for (int j = 0; j < (Num - i); j++)
            {
                printf(" ");
            }
            for (int k = 0; k < (i * 2) + 1; k++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else {
        printf("�ùٸ� ���� �Է��ϼ���.");
    }
    return 0;
}