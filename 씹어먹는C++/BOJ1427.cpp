#include <iostream>
#include <algorithm>
#include <vector>


bool compare(int i, int j) {
	return j < i;
}
int ma_sn() {
	std::vector<int> num(9);
	int n;
	std::cin >> n;

	int size = 0;
	while (n > 0) {
		num.push_back(n % 10);
		n /= 10;
		size++;
	}

	std::sort(num.begin(), num.end(), compare);

	for (int i = 0; i < size;i++) {
		std::cout << num[i];
	}

	return 0;
}
