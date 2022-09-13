#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <string>

int main10610() {
	std::string n;
	std::cin >> n;
	std::vector<char> not_v(n.begin(), n.end());
	std::vector<int> v;

	int answer = 0;
	std::vector<char>::iterator iter;
	for (iter = not_v.begin(); iter != not_v.end(); iter++) {
		int tmp = *iter - '0';
		answer += tmp;
		v.push_back(tmp);
	}
	if (answer % 3 != 0) {
		std::cout << -1 << std::endl;
		return 0;
	}
	sort(v.rbegin(), v.rend());

	if (find(v.begin(), v.end(), 0) == v.end()) {
		std::cout << -1 << std::endl;
		return 0;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i];
		}
		std::cout << std::endl;

	}


	return 0;
}
