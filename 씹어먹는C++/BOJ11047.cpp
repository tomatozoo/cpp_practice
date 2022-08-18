#include <iostream>
#include <vector>
#include <algorithm>

int main11047() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> v;

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		v.push_back(tmp);
	}
	std::reverse(v.begin(), v.end());

	int count = 0;
	for (int i = 0; i < n; i++) {
		count += k / v[i];
		k = k % v[i];
	}

	std::cout << count << std::endl;

	return 0;
}