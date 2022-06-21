#include <iostream>
#include <utility>
#include <queue>
#include <string>

int main() {
	int n, m;
	int map[100][100];
	int visit[100][100] = { 0, };
	std::string tmp;
	std::queue<std::pair<int, int>> q;

	// input data
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		for (int j = 0; j < m; j++) {
			map[i][m - j - 1] = tmp[m - j - 1] - '0';
		}
	}
	//algorithm
	q.push({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty()) {
		// up
		if (q.front().first - 1 >= 0 && visit[q.front().first - 1][q.front().second] == 0 && map[q.front().first - 1][q.front().second] != 0) {
			map[q.front().first - 1][q.front().second] = map[q.front().first][q.front().second] + 1;
			visit[q.front().first - 1][q.front().second] = 1;
			q.push({ q.front().first - 1,q.front().second });
		}
		// down
		if (q.front().first + 1 < n && visit[q.front().first + 1][q.front().second] == 0 && map[q.front().first + 1][q.front().second] != 0) {
			map[q.front().first + 1][q.front().second] = map[q.front().first][q.front().second] + 1;
			visit[q.front().first + 1][q.front().second] = 1;
			q.push({ q.front().first + 1,q.front().second });
		}
		// left
		if (q.front().second - 1 >= 0 && visit[q.front().first][q.front().second - 1] == 0 && map[q.front().first ][q.front().second-1] != 0) {
			map[q.front().first][q.front().second - 1] = map[q.front().first][q.front().second] + 1;
			visit[q.front().first][q.front().second-1] = 1;
			q.push({ q.front().first,q.front().second - 1 });
		}
		// right
		if (q.front().second + 1 < m && visit[q.front().first][q.front().second + 1] == 0 && map[q.front().first ][q.front().second+1] != 0) {
			map[q.front().first][q.front().second + 1] = map[q.front().first][q.front().second] + 1;
			visit[q.front().first][q.front().second + 1] = 1;
			q.push({ q.front().first ,q.front().second + 1 });
		}
		//is finish
		if (q.front() == std::make_pair(n-1, m-1)) {
			std::cout << map[n-1][m-1];
			return 0;
		}
		q.pop();
	}
}