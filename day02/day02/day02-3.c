#include <stdio.h>

int main() {
	for (int i = 0;i <= 99;i++) {
		int gongbaesoo34 = (i % 12 == 0);
		int baesoo7 = (i % 7 == 0);

		if (gongbaesoo34 || baesoo7) {
			printf("%d\n", i);
		}
	}
	return 0;
}