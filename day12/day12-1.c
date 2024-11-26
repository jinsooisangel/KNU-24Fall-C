#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// answer: 롤케이크를 공평하게 자르는 방법의 수
// toppting: 토핑의 종류, 1~10,000가지
// topping_len: 배열 topping의 길이
// topping 배열의길이: 1~1,000,000

//size_t: 배열 인덱스 값을 저장할 때 사용
int solution(int topping[], size_t topping_len) {
    int left[10001] = { 0 };
    int right[10001] = { 0 };
    int left_count = 0, right_count = 0, answer = 0;

    for (size_t i = 0; i < topping_len; i++) {
        //[topping[i]]: topping의 i번째 인덱스
        if (right[topping[i]] == 0) {
            //토핑 개수 +1
            right_count++;
        }
        //topping의 i+1번째 인덱스
        right[topping[i]]++;
    }
    // 자르는 지점을 이동하며 탐색
    for (size_t i = 0; i < topping_len; i++) {
        // 왼쪽 구간의 토핑 수 업데이트
        if (left[topping[i]] == 0) {
            //토핑 개수 +1
            left_count++;
        }
        left[topping[i]]++;

        // [topping[i]]: topping의 i번째 인덱스에서 -1
        right[topping[i]]--;
        //topping의 i번째 인덱스가 존재하지 않으면
        if (right[topping[i]] == 0) {
            //토핑 개수 -1
            right_count--;
        }
        //왼쪽 토핑 수 = 오른쪽 토핑 수
        if (left_count == right_count) {
            answer++;
        }
    }
    return answer;
}

int main() {
    int topping[] = { 1, 2, 1, 3, 1, 4, 1, 2 };
    size_t topping_len = sizeof(topping) / sizeof(topping[0]);
    printf("공평하게 자를 수 있는 경우의 수: %d\n", solution(topping, topping_len));
    return 0;
}
