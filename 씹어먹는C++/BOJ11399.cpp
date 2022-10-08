#include <iostream>
#include <algorithm>
#include <vector>

int ma28in() {
	// Á¤·ÄÇØ¼­ ÇÕÇÏ±â
	int size;
	std::cin >> size;

	std::vector<int> money(size);

	int tmp;
	for (int i = 0; i < size; i++) {
		std::cin >> tmp;
		money.push_back(tmp);
	}
	std::sort(money.begin(), money.end());

	int sum = money[0];
	for (int i = 1; i < size; i++) {
		money[i] = money[i - 1] + money[i];
		sum += money[i];
	}
	std::cout << sum << std::endl;
	return 0;
}
