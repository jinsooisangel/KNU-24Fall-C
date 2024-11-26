#include <stdio.h>

int solution(int N) {
    int battery = 0;

    // N이 0이 될 때까지 반복
    while (N > 0) {
        if (N % 2 == 0) {
            // 짝수: 순간이동 가능 (배터리 소모 없음)
            N /= 2;
        }
        else {
            // 홀수: 점프 (배터리 소모 1)
            N -= 1;
            battery++;
        }
    }
    return battery;
}

int main() {
    int N;
    printf("전체 거리 N 값을 입력하세요: ");
    scanf_s("%d", &N);

    if (N <= 0 || N> 1000000000) {
        printf("잘못된 입력입니다. 1 이상, 10억 이하의 자연수를 입력하세요. \n");
        return 0;
    }
    printf("이동거리: %d, 건전지 소비 최솟값: %d\n", N, solution(N));
    return 0;
}