#include <stdio.h>
#include <stdlib.h>
#include <string.h> // ���ڿ� ��

// Customer ����ü ����
struct Customer {
    char customerName[50];           // �� �̸�
    int rank;                        // �� ���
    int order_amount;                // �� �ֹ���
    int point;                       // �� ����Ʈ
    struct Customer* prev;           // ���� ��带 ����Ű�� ������
    struct Customer* next;           // ���� ��带 ����Ű�� ������
};

// ����Ʈ�� ���۰� ���� ����Ű�� ���� ������
struct Customer* head = NULL;
struct Customer* tail = NULL;

// ���ο� �� ��带 �����ϴ� �Լ�
struct Customer* customer(char* customerName, int rank, int order_amount, int point) {
    struct Customer* new_node = (struct Customer*)malloc(sizeof(struct Customer));
    strcpy_s(new_node->customerName, sizeof(new_node->customerName), customerName);
    new_node->rank = rank;
    new_node->order_amount = order_amount;
    new_node->point = point;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// ���ο� ��带 ����Ʈ�� ���, �ֹ���, ����Ʈ ������ ���ĵ� ��ġ�� �����ϴ� �Լ�
void insert_node_sorted(struct Customer* new_node) {
    // ����Ʈ�� ����ְų� ���ο� ��尡 head���� ���� �켱������ ���� ���
    if (head == NULL || (head->rank > new_node->rank) ||
        (head->rank == new_node->rank && head->order_amount < new_node->order_amount) ||
        (head->rank == new_node->rank && head->order_amount == new_node->order_amount && head->point < new_node->point)) {
        new_node->next = head;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
        if (tail == NULL) {
            tail = new_node;
        }
    }
    else {
        struct Customer* cur = head;
        // ������ ��ġ�� ã�� ���� �̵� (�켱������ ���� ��ġ�� ã��)
        while (cur->next != NULL &&
            (cur->next->rank < new_node->rank ||
                (cur->next->rank == new_node->rank && cur->next->order_amount > new_node->order_amount) ||
                (cur->next->rank == new_node->rank && cur->next->order_amount == new_node->order_amount && cur->next->point >= new_node->point))) {
            cur = cur->next;
        }
        // ���ο� ��带 ���� ��ġ ������ ����
        new_node->next = cur->next;
        if (cur->next != NULL) {
            cur->next->prev = new_node;
        }
        else {
            tail = new_node;
        }
        cur->next = new_node;
        new_node->prev = cur;
    }
}

// ����Ʈ�� ��� ��带 ����ϴ� �Լ�
void print_list() {
    struct Customer* cur = head;
    while (cur != NULL) {
        printf("�� �̸�: %s  , �� ���: %d  , �� �ֹ���: %d  , �� ����Ʈ: %d  \n", cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->next;
    }
    printf("\n");
}

// 1. �� ���� �Է� �Լ�
void input_customer() {
    char customerName[50];
    int rank;
    int order_amount;
    int point;
    printf("�� �̸�: ");
    scanf_s("%49s", customerName, (unsigned)_countof(customerName));  // ���� �����÷ο� ������ ���� �ִ� ���� ����
    printf("���: ");
    scanf_s("%d", &rank);
    printf("�ֹ���: ");
    scanf_s("%d", &order_amount);
    printf("����Ʈ: ");
    scanf_s("%d", &point);
    insert_node_sorted(customer(customerName, rank, order_amount, point));
    printf("���� �߰��Ǿ����ϴ�.\n");
}


// 2. ����
void delete_node(char* customerName) {
    struct Customer* cur = head;

    // ������ ��带 ã�� ���� ��ȸ
    while (cur != NULL && strcmp(cur->customerName, customerName) != 0) {
        cur = cur->next;
    }

    // ��带 ã�� ���� ���
    if (cur == NULL) {
        printf("�� %s��(��) ã�� �� �����ϴ�.\n", customerName);
        return;
    }

    // ��带 �����ϰ� ������ ����
    if (cur->prev != NULL) {
        cur->prev->next = cur->next;
    }
    else {
        head = cur->next;
    }
    if (cur->next != NULL) {
        cur->next->prev = cur->prev;
    }
    else {
        tail = cur->prev;
    }
    free(cur);
}

// 3. ���� ����
void modify_node(char* customerName) {
    struct Customer* cur = head;

    // ������ ��带 ã�� ���� ��ȸ
    while (cur != NULL && strcmp(cur->customerName, customerName) != 0) {
        cur = cur->next;
    }

    // ��带 ã�� ���� ���
    if (cur == NULL) {
        printf("�� %s��(��) ã�� �� �����ϴ�.\n", customerName);
        return;
    }

    // ��� ������ ����
    printf("������ �� ���� �Է�:\n");
    printf("���: ");
    scanf_s("%d", &cur->rank);
    printf("�ֹ���: ");
    scanf_s("%d", &cur->order_amount);
    printf("����Ʈ: ");
    scanf_s("%d", &cur->point);
    printf("�� ������ �����Ǿ����ϴ�.\n");
}

// ���� �Լ�
int main() {
    int input_num;

    while (1) {
        printf("---------------------------------\n");
        printf("1. �� ���� �Է�\n");
        printf("2. �� ���� ����\n");
        printf("3. ���α׷� ����\n");
        printf("��ȣ �Է�: ");
        scanf_s("%d", &input_num);

        switch (input_num) {
        case 1:
            input_customer();
            break;
        case 2: {
            char customerName[50];
            printf("������ �� �̸�: ");
            scanf_s("%49s", customerName, (unsigned)_countof(customerName));  // ���� �����÷ο� ������ ���� �ִ� ���� ����
            delete_node(customerName);
            break;
        }
        case 3: {
            char customerName[50];
            printf("������ �� �̸�: ");
            scanf_s("%49s", customerName, (unsigned)_countof(customerName));  // ���� �����÷ο� ������ ���� �ִ� ���� ����
            modify_node(customerName);
        }
        break;
        case 4:
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

