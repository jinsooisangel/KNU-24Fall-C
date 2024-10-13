#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    double x = 0;
    double y = 0;

    int count = 0, circle = 0;

    srand(time(NULL));

    while (count < 10000) {
        x = (double)rand() / RAND_MAX; // 0에서 1 사이의 랜덤한 x 좌표
        y = (double)rand() / RAND_MAX; // 0에서 1 사이의 랜덤한 Y 좌표
        count++;
    }

    int num_points = 1000000;  // 시뮬레이션할 점의 총 개수
    int points_in_circle = 0;  // 원 안에 들어간 점의 개수

    srand(time(NULL));  // 난수 생성을 위한 시드를 현재 시간으로 설정

    for (int i = 0; i < num_points; i++) {
        // 새로운 랜덤한 x, y 좌표 생성
        x = (double)rand() / RAND_MAX; // 새로운 랜덤한 x 좌표
        y = (double)rand() / RAND_MAX; // 새로운 랜덤한 Y 좌표

        // 원의 중심에서의 거리 계산 (제곱)
        double distance = sqrt(x * x + y * y); // 루트 연산 사용

        // 원의 반지름(1)과 비교하여 원 안에 있는지 확인
        if (distance <= 1) {
            points_in_circle++;  // 원 안에 들어간 경우
        }

        if (i % 10000 == 0) {  // 매 10000번째 반복마다 출력
            double pi = 4.0 * points_in_circle / (i + 1);  // 현재까지의 원주율 추정
            double progress = (double)(i + 1) / num_points * 100.0;
            printf("%.0f%% 진행.. 현재 원주율: %f ", progress, pi);
            int num_filled_boxes = (int)(progress / 5); // 최대 20칸

            //  채워진 박스 출력
            for (int j = 0; j < num_filled_boxes && j < 20; j++) {
                printf("■");
            }
            // 빈 박스 출력
            for (int j = 0; j < 20 - num_filled_boxes && j < 20; j++) {
                printf("□");
            }
            printf("\n");
        }
    }

    // 최종 원주율 계산 및 출력
    double pi = 4.0 * points_in_circle / num_points;  // 최종 원주율 추정
    double progress = 101.0; // 진행률은 100%
    printf("최종 원주율: %f ", pi);

    // 모든 박스를 채우기
    for (int j = 0; j < 20; j++) {
        printf("■");
    }
    printf("\n");

    return 0;
}