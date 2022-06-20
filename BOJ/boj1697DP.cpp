#include <iostream>
#include <queue>

int main() {	// DP
	int n, k;
	int arr[100000];
	std::queue<int> q;
	std::cin >> n >> k;

	for (int i = 0; i < 100000; i++)	//배열 초기화
		arr[i] = 999999;

	arr[n] = 0;
	q.push(n);
	while (1) {
		if (q.front() == k) {
			std::cout << arr[q.front()]<<'\n';
			return 0;
		}
		n = q.front();
		//x + 1
		if (n + 1 < 100001 && arr[n + 1] > arr[n] + 1) {
			arr[n + 1] = arr[n] + 1;
			q.push(n + 1);
		}
		//x - 1
		if (n - 1 >= 0 && arr[n - 1] > arr[n] + 1) {
			arr[n - 1] = arr[n] + 1;
			q.push(n - 1);
		}
		//x * 2
		if (n * 2 < 100001 && arr[n * 2] > arr[n] + 1) {
			arr[n * 2] = arr[n] + 1;
			q.push(n * 2);
		}
		q.pop();
	}
}