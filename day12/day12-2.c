#include <stdio.h>

int solution(int N) {
    int battery = 0;

    // N�� 0�� �� ������ �ݺ�
    while (N > 0) {
        if (N % 2 == 0) {
            // ¦��: �����̵� ���� (���͸� �Ҹ� ����)
            N /= 2;
        }
        else {
            // Ȧ��: ���� (���͸� �Ҹ� 1)
            N -= 1;
            battery++;
        }
    }
    return battery;
}

int main() {
    int N;
    printf("��ü �Ÿ� N ���� �Է��ϼ���: ");
    scanf_s("%d", &N);

    if (N <= 0 || N> 1000000000) {
        printf("�߸��� �Է��Դϴ�. 1 �̻�, 10�� ������ �ڿ����� �Է��ϼ���. \n");
        return 0;
    }
    printf("�̵��Ÿ�: %d, ������ �Һ� �ּڰ�: %d\n", N, solution(N));
    return 0;
}