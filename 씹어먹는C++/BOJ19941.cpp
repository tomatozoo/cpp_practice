#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> position(n);
	char tmp;
	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		position.push_back(tmp);
	}


	return 0;
}