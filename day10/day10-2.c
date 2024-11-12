#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 문자열 비교

// Customer 구조체 정의
struct Customer {
    char customerName[50];           // 고객 이름
    int rank;                        // 고객 등급
    int order_amount;                // 고객 주문량
    int point;                       // 고객 포인트
    struct Customer* prev;           // 이전 노드를 가리키는 포인터
    struct Customer* next;           // 다음 노드를 가리키는 포인터
};

// 리스트의 시작과 끝을 가리키는 전역 포인터
struct Customer* head = NULL;
struct Customer* tail = NULL;

// 새로운 고객 노드를 생성하는 함수
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

// 새로운 노드를 리스트에 등급, 주문량, 포인트 순으로 정렬된 위치에 삽입하는 함수
void insert_node_sorted(struct Customer* new_node) {
    // 리스트가 비어있거나 새로운 노드가 head보다 높은 우선순위를 가질 경우
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
        // 삽입할 위치를 찾기 위해 이동 (우선순위가 낮은 위치를 찾음)
        while (cur->next != NULL &&
            (cur->next->rank < new_node->rank ||
                (cur->next->rank == new_node->rank && cur->next->order_amount > new_node->order_amount) ||
                (cur->next->rank == new_node->rank && cur->next->order_amount == new_node->order_amount && cur->next->point >= new_node->point))) {
            cur = cur->next;
        }
        // 새로운 노드를 현재 위치 다음에 삽입
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

// 리스트의 모든 노드를 출력하는 함수
void print_list() {
    struct Customer* cur = head;
    while (cur != NULL) {
        printf("고객 이름: %s  , 고객 등급: %d  , 고객 주문량: %d  , 고객 포인트: %d  \n", cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->next;
    }
    printf("\n");
}

// 1. 고객 정보 입력 함수
void input_customer() {
    char customerName[50];
    int rank;
    int order_amount;
    int point;
    printf("고객 이름: ");
    scanf_s("%49s", customerName, (unsigned)_countof(customerName));  // 버퍼 오버플로우 방지를 위해 최대 길이 지정
    printf("등급: ");
    scanf_s("%d", &rank);
    printf("주문량: ");
    scanf_s("%d", &order_amount);
    printf("포인트: ");
    scanf_s("%d", &point);
    insert_node_sorted(customer(customerName, rank, order_amount, point));
    printf("고객이 추가되었습니다.\n");
}


// 2. 삭제
void delete_node(char* customerName) {
    struct Customer* cur = head;

    // 삭제할 노드를 찾기 위해 순회
    while (cur != NULL && strcmp(cur->customerName, customerName) != 0) {
        cur = cur->next;
    }

    // 노드를 찾지 못한 경우
    if (cur == NULL) {
        printf("고객 %s을(를) 찾을 수 없습니다.\n", customerName);
        return;
    }

    // 노드를 삭제하고 연결을 수정
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

// 3. 정보 수정
void modify_node(char* customerName) {
    struct Customer* cur = head;

    // 수정할 노드를 찾기 위해 순회
    while (cur != NULL && strcmp(cur->customerName, customerName) != 0) {
        cur = cur->next;
    }

    // 노드를 찾지 못한 경우
    if (cur == NULL) {
        printf("고객 %s을(를) 찾을 수 없습니다.\n", customerName);
        return;
    }

    // 노드 정보를 수정
    printf("수정할 고객 정보 입력:\n");
    printf("등급: ");
    scanf_s("%d", &cur->rank);
    printf("주문량: ");
    scanf_s("%d", &cur->order_amount);
    printf("포인트: ");
    scanf_s("%d", &cur->point);
    printf("고객 정보가 수정되었습니다.\n");
}

// 메인 함수
int main() {
    int input_num;

    while (1) {
        printf("---------------------------------\n");
        printf("1. 고객 정보 입력\n");
        printf("2. 고객 정보 제거\n");
        printf("3. 프로그램 종료\n");
        printf("번호 입력: ");
        scanf_s("%d", &input_num);

        switch (input_num) {
        case 1:
            input_customer();
            break;
        case 2: {
            char customerName[50];
            printf("삭제할 고객 이름: ");
            scanf_s("%49s", customerName, (unsigned)_countof(customerName));  // 버퍼 오버플로우 방지를 위해 최대 길이 지정
            delete_node(customerName);
            break;
        }
        case 3: {
            char customerName[50];
            printf("수정할 고객 이름: ");
            scanf_s("%49s", customerName, (unsigned)_countof(customerName));  // 버퍼 오버플로우 방지를 위해 최대 길이 지정
            modify_node(customerName);
        }
        break;
        case 4:
            exit(0);
        default:
            printf("올바른 값을 입력하세요.\n");
            break;
        }
        printf("---------------------------------\n");
        print_list();
    }
    return 0;
}

