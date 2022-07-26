#include <iostream>
// 1. class declaration
class Point {
	int x, y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) : x(x), y(y) {}

	void print_point() {
		std::cout << "( " << x << ", " << y << " )" << std::endl;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

};
