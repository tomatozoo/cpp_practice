#include <iostream>
#include <string>

int is_yoon(int year) {
	if ((year % 100 != 0) && (year % 4 == 0)) {
		return 1;
	}
	else if (year % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main2753() {
	int year;
	std::cin >> year;
	std::cout << is_yoon(year) << std::endl;
	return 0;
}