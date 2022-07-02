#include <iostream>
#include <list>
#include <vector>
#include <string>

//	https://www.acmicpc.net/board/view/76494
//	50 % 에서 틀리는데 아무리 봐도 모르겠어서 열심히 반례를 찾다가, 해도 해도 안 돼서 다시 코드 보고 예제 보고 있었는데
//	알고보니까 이 문제 n이 0이어도 빈 배열인[]을 입력받습니다.
//	저같은 경우에는 n이 1 이상일때만 cin으로 배열을 입력받았는데 이게 문제가 되어서 n이 0일때 입력받지 않게 되지만 실제 입력은[]을 콘솔로 입력받게 되고,
//	이[]이 버퍼에서 비워지지 않으면 다음 입력에 영향을 끼쳐 잘못된 입력이 들어가는 것으로 판단됩니다.


int main() {
	int testcaseNum;
	std::vector<int> result[100];

	std::cin >> testcaseNum;
	for (int t = 0; t < testcaseNum; t++) {
		std::vector<char> funcArr;
		std::list<int> arr;
		int arrLength;
		int isReverse = 1;	// 1 : 정방향 , -1 : 역방향
		// Data Input
		getc(stdin);	// delete'\n' 
		for (char c;;) {
			c = getc(stdin);
			funcArr.push_back(c);
			if (funcArr.at(funcArr.size() - 1)=='\n') {
				break;
			}
		}
		char a;
		std::cin >> arrLength >> a;
		std::string num = "";
		if (arrLength == 0) {
			std::cin >> a;
		}
		for (int i = 0; i < arrLength; i++) {
			while (true) {
				std::cin >> a;
				if (a == ',' || a == ']') {
					arr.push_back(stoi(num));
					num = "";
					break;
				}
				num = num + a;
			}
		}
		// Algorithm
		for (int i = 0; i < funcArr.size(); i++) {
			if (funcArr.at(i) == 'R') {
				isReverse = isReverse * -1;
			}
			else if (funcArr.at(i) == 'D') {
				if (arr.empty()) {
					result[t].push_back(-1);
					break;
				}
				else {
					if (isReverse == 1) {
						arr.pop_front();
					}
					else if (isReverse == -1) {
						arr.pop_back();
					}
				}
			}
		}

		if (isReverse == -1) {
			arr.reverse();
		}
		if (result[t].empty()) {
			for (std::list<int>::iterator iter = arr.begin(); iter != arr.end(); iter++) {
				result[t].push_back(*iter);
			}
		}


	}
	// Output
	for (int t = 0; t < testcaseNum; t++) {
		if (result[t].empty()) {
			std::cout << '['<<']' << '\n';
		}
		else if (result[t].at(0) == -1) {
			std::cout << "error" << '\n';
		}
		else {
			std::cout << '[';
			for (int i = 0; i < result[t].size() - 1; i++) {
				std::cout << result[t].at(i) << ',';
			}
			std::cout << result[t].at(result[t].size() - 1);
			std::cout << ']' << '\n';
		}
	}
	return 0;
}