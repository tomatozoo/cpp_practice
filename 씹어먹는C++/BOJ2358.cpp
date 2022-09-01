#include <iostream>
#include <map>
#include <utility>

int main2358() {
	// n °³ÀÇ ÁÂÇ¥
	int n;
	std::cin >> n;

	std::map<int, int> x_value;
	std::map<int, int> y_value;


	for (int i = 0; i < n; i++) {
		int x, y; 
		std::cin >> x >> y;
		x_value[x] += 1;
		y_value[y] += 1;
	}

	int answer = 0;
	for (std::map<int, int>::iterator it = x_value.begin(); it != x_value.end(); it++) {
		if (it->second >= 2) {
			answer++;
		}
	}
	for (std::map<int, int>::iterator it = y_value.begin(); it != y_value.end(); it++) {
		if (it->second >= 2) {
			answer++;
		}
	}

	std::cout << answer << std::endl;
	return 0;
}