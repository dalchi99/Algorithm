#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#include <functional>

int main() {
	int n, k;
	std::multiset<int> bag;
	std::pair<int, int> *product = new std::pair<int ,int>[300000];	// f: 가격 , s:무게
	int bagInput;
	long long totalvalue = 0;

	//Data Input
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> product[i].second >> product[i].first;
	}
	for (int i = 0; i < k; i++) {
		std::cin >> bagInput;
		bag.insert(bagInput);
	}
	
	//Algorithm
	std::sort(product, product + n, std::greater<>());

	for (int i = 0; i < n; i++) {
		if (bag.lower_bound(product[i].second) == bag.end()) {
			continue;
		}
		else {
			bag.erase(bag.lower_bound(product[i].second));
			totalvalue += product[i].first;
		}
	}
	std::cout << totalvalue << '\n';

}