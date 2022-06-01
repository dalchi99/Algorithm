#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <set>


int main() {
	int n,x,y;
	std::pair <int, int> tmp;
	std::vector<std::pair<int, int>> list;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> x >> y;
		list.push_back({ x,y });
	}

	std::sort(list.begin(),list.end());
	
	for (int i = 0; i < n; i++) {
		std::cout << list[i].first << " " << list[i].second << '\n';
	}
	//auto end = std::end(list);
	//for (auto iter = std::begin(list); iter!=end ; iter++) {	//출력문
	//	std::cout << iter->first <<" " << iter->second<< std::endl;
	//}

	return 0;
}
	//정렬
	//std::sort(std::begin(list), std::end(list), [](const std::pair<int, int> a, const std::pair<int, int> b) {
	//	if (a.first < b.first || (a.first == b.first && a.second < b.second))
	//		return 1;
	//	else
	//		return 0;
	//	});

int mains() {
	int n;
	long long x, y;
	std::set<long long> list;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> x >> y;
		x = x + 100000;
		y = y + 100000;
		list.insert(x*1000000+y);
	}

	auto end = std::end(list);
	for (auto iter = std::begin(list); iter != end; iter++) {	//출력문
		std::cout << *iter/1000000-100000 << " " << *iter%1000000-100000 << std::endl;
	}
	return 0;
}