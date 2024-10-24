#include <stdio.h>

struct Product{
	int id, price; //id�� ���� ����
	char name[15];// �̸� ����
};

void printProduct(struct Product p) {//����ü ���� p�� �޾� ����ϴ� �Լ�
	printf("��ǰ ID : %d\n",p.id);
	printf("��ǰ�� : %s\n", p.name);
	printf("��ǰ ���� : %d\n", p.price);
	printf("\n");
}

int main() {
	struct Product products[5];//�ִ� 5���� ���� ����
	int inputProduct = 0;//�Էµ� ��ǰ���� ����

	printf("��ǰ ������ �Է��ϼ��� (�Է� �ߴ��� ID�� 0 �Է�)\n");

	for (int i = 0;i < 5;i++) {//�ִ� 5������ �ݺ�
		printf("��ǰ ID : ");
		scanf_s("%d", &products[i].id);//��ǰ 1~5��° �Էµ� id�� id ����ü�� ����

		if (products[i].id == 0) {//id�� 0 �Է� �� �Է� ����
			break;
		}

		printf("��ǰ��: ");
		scanf_s("%s", products[i].name, sizeof(products[i].name));//��ǰ 1~5��° �Էµ� �̸��� �̸� ����ü�� ����

		printf("����:");
		scanf_s("%d", &products[i].price);//��ǰ 1~5��° �Էµ� ������ ���� ����ü�� ����

		printf("\n");
		inputProduct++;//�Է�Ƚ�� +1
	}
	printf("---------------------------------------\n");
	printf("<<<<< �Էµ� ��ǰ ��� >>>>>\n"); //�ݺ��� ���� �� �Էµ� ��ǰ��� ���
	for (int i = 0;i < inputProduct;i++) {//�Էµ� ��ǰ ����� ����ŭ �ݺ������� ���
		printProduct(products[i]);
	}
	return 0;
}