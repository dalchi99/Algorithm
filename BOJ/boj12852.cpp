#include<cstdio>
#include<cstdlib>
#include<iostream>

int min_num(int a, int b, int c);

int main() {
	int* count = (int *)malloc(sizeof(int) * 1000001);
	int a, b, c, target;

	count[1] = 0;
	count[2] = 1;
	count[3] = 1;
	count[0] = 0;

	//scanf_s("%d", &target);
	std::cin >> target;

	for (int i = 4; i <= target; i++) {
		a = 100000000, b = 100000000;
		if (i % 3 == 0)
			a = count[i / 3] + 1;
		if (i % 2 == 0)
			b = count[i / 2] + 1;
		c = count[i - 1] + 1;
		count[i] = min_num(a, b, c);
	}


	for (int i = 0; i <= target; i++) { //수정 필요
		printf("%d :%d\n", i, count[i]);	
	}

	printf("%d ", target);
	while(target!=1){					//과정출력
		a = 100000000, b = 100000000;
		if (target % 3 == 0)
			a = count[target / 3] + 1;

		if (target % 2 == 0)
			b = count[target / 2] + 1;

		c = count[target - 1] + 1;

		int tmp = min_num(a, b, c);
		if (tmp == a) {
			target = target / 3;
		}
		else if (tmp == b) {
			target = target / 2;
		}
		else {
			target = target - 1;
		}
		printf("%d ",target);
	}

	return 0;
}

int min_num(int a, int b, int c) {
	if (a < b)
		return a < c ? a : c;
	else
		return b < c ? b : c;

}