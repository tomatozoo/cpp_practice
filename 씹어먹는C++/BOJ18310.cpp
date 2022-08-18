#include <iostream>
#include <vector>
#include <algorithm>

int main18310() {
	int n;
	std::cin >> n;
	std::vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		v.push_back(tmp);
	}
	std::sort(v.begin(), v.end());

	if (v.size() % 2 == 0) {
		std::cout << v[v.size() / 2 -1]<< std::endl;
	}
	else {
		std::cout << v[(v.size() -1)/ 2] << std::endl;
	}
	return 0;
}