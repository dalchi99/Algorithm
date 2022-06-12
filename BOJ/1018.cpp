#include <iostream>
#include <string>
#include <vector>

int find(char* board);

int main() {
	int h, w;	//높이 , 넓이
	std::string input;
	char board[50][50] = { 0, };
	char chessboard[] = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";
	int r = 65;	//가장 적게 걸리는 경우를 기록

	std::cin >> h >> w;	//데이터 입력
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			std::cin >> board[i][j];
		}
	}

	//알고리즘부분
	for (int i = 0; i < h-7; i++) {
		for (int j = 0; j < w-7; j++) {

			//std::cout << i*(w-7)+j << std::endl;	
			int count=0,c=0;
			for (int n = i; n < i+8; n++) {				//board[i][j]를 가장 왼쪽 위로 하는 체스판을 만든다.
				for (int m = j; m < j + 8; m++) {
					if (board[n][m] != chessboard[c])
						count++;
					c++;
				}
			}
			if (count > 32)
				count = 64 - count;
			if (count < r)
				r = count;
		}
		/*std::cout << std::endl;*/
	}


	std::cout << r << std::endl;		//결과 출력

	//std::cout << std::endl;		//디버깅용 출력문
	//for (int i = 0; i < h; i++) {
	//	for (int j = 0; j < w; j++) {
	//		std::cout<< board[i][j]<<' ';
	//	}
	//	std::cout << std::endl;
	//}
	return 0;
}
