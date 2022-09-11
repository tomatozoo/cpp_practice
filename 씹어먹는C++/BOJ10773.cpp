#include <iostream>
#include <vector>
#include <numeric>
 
int notmainanymore() {
	int k;
	std::cin >> k;
	int sum = 0;

	std::vector<int> vec(k);

	int tmp;
	for (int i = 0; i < k; i++) {
		std::cin >> tmp;

		if (tmp == 0) {
			vec.pop_back();
		}
		else {
			vec.push_back(tmp);
		}
	}

	sum = std::accumulate(vec.begin(), vec.end(), 0);
	std::cout << sum << std::endl;
	return 0;
}
