#include <stdio.h>

int main() {
	int Num = 4;

	printf("%d층 피라미드\n", Num);
    // i=피라미드 층, j=공백, k=별
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