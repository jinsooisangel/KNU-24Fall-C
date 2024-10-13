#include <stdio.h>

int main() {
    int Num;
    printf("층을 입력하세요.: ");
    scanf_s("%d", &Num);

    if (Num <= 0) {
        printf("1층 이상을 입력하세요.");
    }
    else if (Num >= 1) {
        printf("%d층 피라미드 \n", Num);

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
        printf("올바른 값을 입력하세요.");
    }
    return 0;
}