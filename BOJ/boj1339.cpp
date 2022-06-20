#include <iostream>
#include <string>

int main() {
	int n;
	std::string word[10];
	int arr[300] = { 0, };
	int result = 0;

	std::cin >> n;	// Input
	for (int i = 0; i < n; i++) {
		std::cin >> word[i];
	}

	//	Algorithm
	for (int i = 0; i < n; i++) {
		int mul = 1;
		for (int j = 0; j < word[i].length(); j++) {
			
			arr[word[i][word[i].length() - j-1]] += 1 * mul;
			mul *= 10;
		}
	}

	std::cout << "알파벳별 숫자" << '\n';
	for (int i = 0; i < 300; i++) {
		if (arr[i] != 0) {
			std::cout << (char)i << " : " << arr[i] << '\n';
		}
	}

	for (int i = 1; i < 10; i++) {
		int num=0;
		int saveidx=0;
		for (int j = 0; j < 300; j++) {
			if (arr[j] > num) {
				num = arr[j];
				saveidx = j;
			}
		}
		result = result + (num * (10 - i));
		arr[saveidx] = 0;
	}

	//	결과출력
	std::cout << result;
}