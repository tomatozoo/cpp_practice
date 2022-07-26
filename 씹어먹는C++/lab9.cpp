#include <iostream>
#define PI 3.14159
#define AREA(r) r*r*PI

void three_swap(int* a, int* b, int* c) {
	// pointer swap
	int temp = *a;
	*a = *b;
	*b = *c;
	*c = temp;
}
void three_swap(int& a, int& b, int& c) {
	// reference swap
	int tmp = a;
	a = b;
	b = c;
	c = tmp;
}


int mwasdain() {
	// problem 1
	double r;
	std::cin >> r;
	std::cout << AREA(r) << std::endl;

	// problem 2
	int a = 3, b = 4, c = 1;
	std::cout << a << b << c << std::endl;

	three_swap(&a, &b, &c);
	std::cout << a << b << c << std::endl;
	three_swap(a, b, c);
	std::cout << a << b << c << std::endl;

	return 0;
}