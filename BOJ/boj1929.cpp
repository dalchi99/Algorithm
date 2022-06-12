#include <iostream>

int main() {
	bool* num = new bool[1000000]{ true, };
	num[1] = true;
	num[2] = false;
	int s, e;

	std::cin >> s >> e;
	
	//std::cout << "start" << std::endl;
	for (int i = 2; i < 10000; i++) {
		if (num[i] == true)
			continue;

		//std::cout << i << std::endl;
		for (int j = 2*i; j < 1000000; j = j + i) {
			num[j] = true;
		}
	}

	for (int i = s; i <= e; i++) {
		if (num[i] == false)
			std::cout << i << std::endl;
	}

	//std::cout << "end of program" << std::endl;

	return 0;
}