#include <stdio.h>
#include <stdlib.h> // malloc을 사용하기 위해 추가
#include <string.h> // 문자열 비교를 위해 추가

// NODE 구조체 정의
struct NODE {
    char name[50];           // 학생의 이름
    int score;               // 학생의 성적
    struct NODE* link;       // 다음 노드를 가리키는 포인터
};

// 리스트의 시작을 가리키는 전역 포인터
struct NODE* head = NULL;

// 새로운 학생 노드를 생성하는 함수
struct NODE* student(char* name, int score) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy_s(new_node->name, sizeof(new_node->name), name);
    new_node->score = score;
    new_node->link = NULL;
    return new_node;
}

// 새로운 노드를 리스트에 성적 순으로 정렬된 위치에 삽입하는 함수
void insert_node_sorted(struct NODE* new_node) {
    // 리스트가 비어있거나 새로운 노드가 head보다 높은 성적일 경우
    if (head == NULL || head->score < new_node->score) {
        new_node->link = head;
        head = new_node;
    }
    else {
        struct NODE* cur = head;
        // 삽입할 위치를 찾기 위해 이동 (성적이 더 낮은 위치를 찾음)
        while (cur->link != NULL && cur->link->score >= new_node->score) {
            cur = cur->link;
        }
        // 새로운 노드를 현재 위치 다음에 삽입
        new_node->link = cur->link;
        cur->link = new_node;
    }
}

// 리스트의 모든 노드를 출력하는 함수
void print_list() {
    struct NODE* cur = head;
    while (cur != NULL) {
        printf("%s      :       %d\n", cur->name, cur->score); // 화살표 제거 및 줄바꿈 추가
        cur = cur->link;
    }
    printf("\n");
}

// 1. 학생 성적 입력 함수
void input_student() {
    char name[50];
    int score;
    printf("학생 이름: ");
    scanf_s("%49s", name, (unsigned)_countof(name));  // 버퍼 오버플로우 방지를 위해 최대 길이 지정
    printf("%s의 성적: ", name);
    scanf_s("%d", &score);
    insert_node_sorted(student(name, score));
    printf("학생이 추가되었습니다.\n");
}

// 특정 학생 노드를 삭제하는 함수
void delete_node(char* name) {
    struct NODE* cur = head;
    struct NODE* prev = NULL;

    // 삭제할 노드가 head인 경우
    if (cur != NULL && strcmp(cur->name, name) == 0) {
        head = cur->link;
        free(cur);
        return;
    }

    // 삭제할 노드를 찾기 위해 순회
    while (cur != NULL && strcmp(cur->name, name) != 0) {
        prev = cur;
        cur = cur->link;
    }

    // 노드를 찾지 못한 경우
    if (cur == NULL) {
        printf("학생 %s을(를) 찾을 수 없습니다.\n", name);
        return;
    }

    // 노드를 삭제하고 연결을 수정
    prev->link = cur->link;
    free(cur);
}

// 메인 함수
int main() {
    int input_num;

    while (1) {
        printf("---------------------------------\n");
        printf("1. 학생의 성적을 입력\n");
        printf("2. 학생 정보 제거\n");
        printf("3. 프로그램 종료\n");
        printf("번호 입력: ");
        scanf_s("%d", &input_num);

        switch (input_num) {
        case 1:
            input_student();
            break;
        case 2: {
            char name[50];
            printf("삭제할 학생 이름: ");
            scanf_s("%49s", name, (unsigned)_countof(name));  // 버퍼 오버플로우 방지를 위해 최대 길이 지정
            delete_node(name);
            break;
        }
        case 3:
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