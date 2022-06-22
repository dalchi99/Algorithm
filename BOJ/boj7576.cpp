#include <iostream>
#include <queue>
#include <utility>

int main() {
	int m;	//가로 / 넓이
	int n;	//세로 / 높이
	int time = 0;
	int** map;
	int** visit;
	int isfinish = 1;
	std::queue<std::pair<int, int>> q;



	// Data Input
	std::cin >> m >> n;

	map = new int* [n];
	for (int i = 0; i < n; i++)
		map[i] = new int[m];

	visit = new int* [n];
	for (int i = 0; i < n; i++)
		visit[i] = new int[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}

	//Algorithm

	while (!q.empty()) {
		// up
		if (q.front().first - 1 >= 0 && visit[q.front().first - 1][q.front().second] == 0 
				&& map[q.front().first - 1][q.front().second] != -1) {
			map[q.front().first - 1][q.front().second] = map[q.front().first][q.front().second] + 1;
			visit[q.front().first - 1][q.front().second] = 1;
			q.push({ q.front().first - 1,q.front().second });
		}
		// down
		if (q.front().first + 1 < n && visit[q.front().first + 1][q.front().second] == 0 
				&& map[q.front().first + 1][q.front().second] != -1) {
			map[q.front().first + 1][q.front().second] = map[q.front().first][q.front().second] + 1;
			visit[q.front().first + 1][q.front().second] = 1;
			q.push({ q.front().first + 1,q.front().second });
		}
		// left
		if (q.front().second - 1 >= 0 && visit[q.front().first][q.front().second - 1] == 0 
				&& map[q.front().first][q.front().second - 1] != -1) {
			map[q.front().first][q.front().second - 1] = map[q.front().first][q.front().second] + 1;
			visit[q.front().first][q.front().second - 1] = 1;
			q.push({ q.front().first,q.front().second - 1 });
		}
		// right
		if (q.front().second + 1 < m && visit[q.front().first][q.front().second + 1] == 0 
				&& map[q.front().first][q.front().second + 1] != -1) {
			map[q.front().first][q.front().second + 1] = map[q.front().first][q.front().second] + 1;
			visit[q.front().first][q.front().second + 1] = 1;
			q.push({ q.front().first ,q.front().second + 1 });
		}
		
		/// //////////////////////////////////
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		std::cout << map[i][j] << '[' << visit[i][j] << ']' << ' ';
		//		
		//	}
		//	std::cout << '\n';
		//}
		//std::cout << '\n';
		/// //////////////////////////////

		q.pop();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (time < map[i][j]) {
				time = map[i][j];
			}
			if (map[i][j] == 0) {
				isfinish = 0;
			}
		}
	}
	//Output Result
	if (isfinish == 0) {
		std::cout << -1;
	}
	else {
		std::cout << time-1;
	}

	return 0;
}