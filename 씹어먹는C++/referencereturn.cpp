#include <iostream>

class A {
	int x;
public:
	A(int c) : x(c) {}
	// int 레퍼런스를 리턴
	int& access_x() { return x; }
	// int를 리턴
	int get_x() { return x; }
	void show_x() { std::cout << x << std::endl; }
};
int m1a2i3n() {
	A a(5);
	a.show_x();

	int& c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	d = 3;
	a.show_x();

	int f = a.get_x();
	f = 1;
	a.show_x();

	return 0;
}