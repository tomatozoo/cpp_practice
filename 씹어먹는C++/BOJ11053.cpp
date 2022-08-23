#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a;
	std::vector<int> c(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		a.push_back(tmp);
	}

	// 가장 긴 증가하는 부분 수열
	for (int i = 0; i < n; i++) {
		c[i] = 1;

		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && c[i] < c[j] + 1) {
				c[i] = c[j] + 1;
			}
		}
	}

	
	std::cout << *std::max_element(c.begin(), c.end()) << std::endl;
	return 0;
}