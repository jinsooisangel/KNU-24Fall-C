#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// answer: ������ũ�� �����ϰ� �ڸ��� ����� ��
// toppting: ������ ����, 1~10,000����
// topping_len: �迭 topping�� ����
// topping �迭�Ǳ���: 1~1,000,000

//size_t: �迭 �ε��� ���� ������ �� ���
int solution(int topping[], size_t topping_len) {
    int left[10001] = { 0 };
    int right[10001] = { 0 };
    int left_count = 0, right_count = 0, answer = 0;

    for (size_t i = 0; i < topping_len; i++) {
        //[topping[i]]: topping�� i��° �ε���
        if (right[topping[i]] == 0) {
            //���� ���� +1
            right_count++;
        }
        //topping�� i+1��° �ε���
        right[topping[i]]++;
    }
    // �ڸ��� ������ �̵��ϸ� Ž��
    for (size_t i = 0; i < topping_len; i++) {
        // ���� ������ ���� �� ������Ʈ
        if (left[topping[i]] == 0) {
            //���� ���� +1
            left_count++;
        }
        left[topping[i]]++;

        // [topping[i]]: topping�� i��° �ε������� -1
        right[topping[i]]--;
        //topping�� i��° �ε����� �������� ������
        if (right[topping[i]] == 0) {
            //���� ���� -1
            right_count--;
        }
        //���� ���� �� = ������ ���� ��
        if (left_count == right_count) {
            answer++;
        }
    }
    return answer;
}

int main() {
    int topping[] = { 1, 2, 1, 3, 1, 4, 1, 2 };
    size_t topping_len = sizeof(topping) / sizeof(topping[0]);
    printf("�����ϰ� �ڸ� �� �ִ� ����� ��: %d\n", solution(topping, topping_len));
    return 0;
}
