#include <iostream>
#include <algorithm>

int main() {
	int list[1000];
	int sum[1000] = { 0, };
	int listlen, result = 1;


	// DataInput
	std::cin >> listlen;
	for (int i = 0; i < listlen; i++) {
		std::cin >> list[i];
	}

	// Algorithm
	std::sort(list, list + listlen);
	sum[0] = list[0];
	if (list[0] == 1) {
		for (int i = 0; i < listlen; i++) {
			if (sum[i] + 1 < list[i + 1]) {
				result = sum[i] + 1;
				break;
			}
			else {
				if (i + 1 == listlen) {
					result = sum[i] + 1;
				}
				sum[i + 1] = sum[i] + list[i + 1];
			}
		}
	}

	std::cout << result << '\n';
	return 0;
}