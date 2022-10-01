#include <iostream>
 


void print(int x) {
	std::cout << "int: " << x << std::endl;
	return;
}
void print(double x) {
	std::cout << "double: " << x << std::endl;
	return;
}

int cppmain() {
	int a=1;
	char b='c';
	double c=1.5;
	print(a);
	print(b);
	print(c);
	return 0;
}
