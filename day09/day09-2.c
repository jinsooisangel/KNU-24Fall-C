#include <stdio.h>

struct Product{
	int id, price; //id와 가격 저장
	char name[15];// 이름 저장
};

void printProduct(struct Product p) {//구조체 변수 p를 받아 출력하는 함수
	printf("상품 ID : %d\n",p.id);
	printf("상품명 : %s\n", p.name);
	printf("상품 가격 : %d\n", p.price);
	printf("\n");
}

int main() {
	struct Product products[5];//최대 5개의 정보 저장
	int inputProduct = 0;//입력된 상품개수 저장

	printf("상품 정보를 입력하세요 (입력 중단은 ID에 0 입력)\n");

	for (int i = 0;i < 5;i++) {//최대 5번까지 반복
		printf("상품 ID : ");
		scanf_s("%d", &products[i].id);//상품 1~5번째 입력된 id를 id 구조체에 저장

		if (products[i].id == 0) {//id에 0 입력 시 입력 종료
			break;
		}

		printf("상품명: ");
		scanf_s("%s", products[i].name, sizeof(products[i].name));//상품 1~5번째 입력된 이름을 이름 구조체에 저장

		printf("가격:");
		scanf_s("%d", &products[i].price);//상품 1~5번째 입력된 가격을 가격 구조체에 저장

		printf("\n");
		inputProduct++;//입력횟수 +1
	}
	printf("---------------------------------------\n");
	printf("<<<<< 입력된 상품 목록 >>>>>\n"); //반복문 종료 후 입력된 상품목록 출력
	for (int i = 0;i < inputProduct;i++) {//입력된 상품 목록의 수만큼 반복문을로 출력
		printProduct(products[i]);
	}
	return 0;
}