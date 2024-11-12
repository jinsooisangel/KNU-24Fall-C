#include <stdio.h>
#include <stdlib.h> // malloc�� ����ϱ� ���� �߰�
#include <string.h> // ���ڿ� �񱳸� ���� �߰�

// NODE ����ü ����
struct NODE {
    char name[50];           // �л��� �̸�
    int score;               // �л��� ����
    struct NODE* link;       // ���� ��带 ����Ű�� ������
};

// ����Ʈ�� ������ ����Ű�� ���� ������
struct NODE* head = NULL;

// ���ο� �л� ��带 �����ϴ� �Լ�
struct NODE* student(char* name, int score) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy_s(new_node->name, sizeof(new_node->name), name);
    new_node->score = score;
    new_node->link = NULL;
    return new_node;
}

// ���ο� ��带 ����Ʈ�� ���� ������ ���ĵ� ��ġ�� �����ϴ� �Լ�
void insert_node_sorted(struct NODE* new_node) {
    // ����Ʈ�� ����ְų� ���ο� ��尡 head���� ���� ������ ���
    if (head == NULL || head->score < new_node->score) {
        new_node->link = head;
        head = new_node;
    }
    else {
        struct NODE* cur = head;
        // ������ ��ġ�� ã�� ���� �̵� (������ �� ���� ��ġ�� ã��)
        while (cur->link != NULL && cur->link->score >= new_node->score) {
            cur = cur->link;
        }
        // ���ο� ��带 ���� ��ġ ������ ����
        new_node->link = cur->link;
        cur->link = new_node;
    }
}

// ����Ʈ�� ��� ��带 ����ϴ� �Լ�
void print_list() {
    struct NODE* cur = head;
    while (cur != NULL) {
        printf("%s      :       %d\n", cur->name, cur->score); // ȭ��ǥ ���� �� �ٹٲ� �߰�
        cur = cur->link;
    }
    printf("\n");
}

// 1. �л� ���� �Է� �Լ�
void input_student() {
    char name[50];
    int score;
    printf("�л� �̸�: ");
    scanf_s("%49s", name, (unsigned)_countof(name));  // ���� �����÷ο� ������ ���� �ִ� ���� ����
    printf("%s�� ����: ", name);
    scanf_s("%d", &score);
    insert_node_sorted(student(name, score));
    printf("�л��� �߰��Ǿ����ϴ�.\n");
}

// Ư�� �л� ��带 �����ϴ� �Լ�
void delete_node(char* name) {
    struct NODE* cur = head;
    struct NODE* prev = NULL;

    // ������ ��尡 head�� ���
    if (cur != NULL && strcmp(cur->name, name) == 0) {
        head = cur->link;
        free(cur);
        return;
    }

    // ������ ��带 ã�� ���� ��ȸ
    while (cur != NULL && strcmp(cur->name, name) != 0) {
        prev = cur;
        cur = cur->link;
    }

    // ��带 ã�� ���� ���
    if (cur == NULL) {
        printf("�л� %s��(��) ã�� �� �����ϴ�.\n", name);
        return;
    }

    // ��带 �����ϰ� ������ ����
    prev->link = cur->link;
    free(cur);
}

// ���� �Լ�
int main() {
    int input_num;

    while (1) {
        printf("---------------------------------\n");
        printf("1. �л��� ������ �Է�\n");
        printf("2. �л� ���� ����\n");
        printf("3. ���α׷� ����\n");
        printf("��ȣ �Է�: ");
        scanf_s("%d", &input_num);

        switch (input_num) {
        case 1:
            input_student();
            break;
        case 2: {
            char name[50];
            printf("������ �л� �̸�: ");
            scanf_s("%49s", name, (unsigned)_countof(name));  // ���� �����÷ο� ������ ���� �ִ� ���� ����
            delete_node(name);
            break;
        }
        case 3:
            exit(0);
        default:
            printf("�ùٸ� ���� �Է��ϼ���.\n");
            break;
        }
        printf("---------------------------------\n");
        print_list();
    }
    return 0;
}