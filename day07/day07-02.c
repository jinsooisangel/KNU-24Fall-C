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
        x = (double)rand() / RAND_MAX; // 0���� 1 ������ ������ x ��ǥ
        y = (double)rand() / RAND_MAX; // 0���� 1 ������ ������ Y ��ǥ
        count++;
    }

    int num_points = 1000000;  // �ùķ��̼��� ���� �� ����
    int points_in_circle = 0;  // �� �ȿ� �� ���� ����

    srand(time(NULL));  // ���� ������ ���� �õ带 ���� �ð����� ����

    for (int i = 0; i < num_points; i++) {
        // ���ο� ������ x, y ��ǥ ����
        x = (double)rand() / RAND_MAX; // ���ο� ������ x ��ǥ
        y = (double)rand() / RAND_MAX; // ���ο� ������ Y ��ǥ

        // ���� �߽ɿ����� �Ÿ� ��� (����)
        double distance = sqrt(x * x + y * y); // ��Ʈ ���� ���

        // ���� ������(1)�� ���Ͽ� �� �ȿ� �ִ��� Ȯ��
        if (distance <= 1) {
            points_in_circle++;  // �� �ȿ� �� ���
        }

        if (i % 10000 == 0) {  // �� 10000��° �ݺ����� ���
            double pi = 4.0 * points_in_circle / (i + 1);  // ��������� ������ ����
            double progress = (double)(i + 1) / num_points * 100.0;
            printf("%.0f%% ����.. ���� ������: %f ", progress, pi);
            int num_filled_boxes = (int)(progress / 5); // �ִ� 20ĭ

            //  ä���� �ڽ� ���
            for (int j = 0; j < num_filled_boxes && j < 20; j++) {
                printf("��");
            }
            // �� �ڽ� ���
            for (int j = 0; j < 20 - num_filled_boxes && j < 20; j++) {
                printf("��");
            }
            printf("\n");
        }
    }

    // ���� ������ ��� �� ���
    double pi = 4.0 * points_in_circle / num_points;  // ���� ������ ����
    double progress = 101.0; // ������� 100%
    printf("���� ������: %f ", pi);

    // ��� �ڽ��� ä���
    for (int j = 0; j < 20; j++) {
        printf("��");
    }
    printf("\n");

    return 0;
}