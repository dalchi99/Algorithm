#include <iostream>
#include <algorithm>

int main() {
	int len,result;
	int r, g, b;
	int rgbcost[1000][3];
	int mincost[1000][3];

	std::cin >> len;		//입력 부분
	for (int i = 0; i < len; i++) {
		std::cin >> rgbcost[i][0] >> rgbcost[i][1] >> rgbcost[i][2];
	}

	//알고리즘 부분
	mincost[0][0] = rgbcost[0][0];
	mincost[0][1] = rgbcost[0][1];
	mincost[0][2] = rgbcost[0][2];

	for (int i = 1; i < len; i++) {
		mincost[i][0] = rgbcost[i][0] + std::min(mincost[i - 1][1], mincost[i - 1][2]);
		mincost[i][1] = rgbcost[i][1] + std::min(mincost[i - 1][0], mincost[i - 1][2]);
		mincost[i][2] = rgbcost[i][2] + std::min(mincost[i - 1][1], mincost[i - 1][0]);
	}

	//출력
	result = std::min(std::min(mincost[len - 1][0], mincost[len - 1][1]), mincost[len - 1][2]);
	std::cout << result << '\n';
	//std::cout << std::endl;	//입력 확인용 전체 출력	*디버깅용*
	//for (int i = 0; i < len; i++) {
	//	std::cout << rgbcost[i][0] << rgbcost[i][1] << rgbcost[i][2]<<std::endl;
	//}
	std::cout << std::endl;	//입력 확인용 전체 출력	*디버깅용*
	for (int i = 0; i < len; i++) {
		std::cout << mincost[i][0] <<' ' << mincost[i][1] << ' ' << mincost[i][2] << std::endl;
	}


	return 0;
}