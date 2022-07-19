#include <iostream>

int cheak(int target, int* button);

int main() {
	int target,b_count, now = 100;
	int left = 0, right = 0;
	int lcount = 999999, rcount = 999999;
	int dcount;
	int button[10];
	int tmp;
	for (int i = 0; i < 10; i++) {
		button[i] = 1;
	}
	//	 Datainput
	std::cin >> target;
	std::cin >> b_count;
	for (int i = 0; i < b_count; i++) {
		int num;
		std::cin >> num;
		button[num] = 0;
	}

	//	 Algorithm
	if (target == 100) {
		std::cout << 0 << '\n';
		return 0;
	}
	else if (target == 99 || target == 101) {
		std::cout << 1 << '\n';
		return 0;
	}
	else if (target == 102) {
		std::cout << 2 << '\n';
		return 0;
	}
	else if (cheak(target, button)) {
		std::cout << cheak(target, button) << '\n';
		return 0;
	}
	
	//left (Down)
	left = target;
	tmp = 0;
	while (left>0) {
		left--;
		tmp++;
		if (left == 100) {
			lcount = tmp;
			break;
		}
		if (cheak(left, button)) {
			tmp = tmp + cheak(left, button);
			lcount = tmp;
			break;
		}
	}
	//right (Up)
	right = target;
	tmp = 0;
	while (right<1000001) {
		right++;
		tmp++;
		if (right == 100) {
			rcount = tmp;
			break;
		}
		if (cheak(right, button)) {
			tmp = tmp + cheak(right, button);
			rcount = tmp;
			break;
		}
	}
	//dcount
	if (target > 100) {
		dcount =  target - 100;
	}
	else {
		dcount = 100 - target;
	}

	if (lcount > rcount) {
		if (rcount < dcount) {
			std::cout << rcount << '\n';
		}
		else {
			std::cout << dcount << '\n';
		}
	}
	else {
		if (lcount < dcount) {
			std::cout << lcount << '\n';
		}
		else {
			std::cout << dcount << '\n';
		}
	}
}

int cheak(int target, int* button) {
	int count = 0;
	while (target / 10 > 0) {
		if (button[target % 10] == 0) {
			return 0;
		}
		else {
			target = target / 10;
			count++;
		}
	}
	if (button[target] == 0)
		return 0;
	else
		return count+1;
}
