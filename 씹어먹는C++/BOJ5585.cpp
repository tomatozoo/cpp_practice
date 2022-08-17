#include <iostream>

int main5585() {
	int left;
	std::cin >> left;
	left = 1000 - left;

	int count = 0, tmp=0;
	tmp = left / 500;
	count += tmp;
	left -= 500 * tmp;

	tmp = left / 100;
	count += tmp;
	left -= 100 * tmp;

	tmp = left / 50;
	count += tmp;
	left -= 50 * tmp;

	tmp = left / 10;
	count += tmp;
	left -= 10 * tmp;

	tmp = left / 5;
	count += tmp;
	left -= 5 * tmp;

	tmp = left;
	count += tmp;
	left -=tmp;

	std::cout << count << std::endl;

	return 0;
}