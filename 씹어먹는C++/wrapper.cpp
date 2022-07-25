#include <iostream>

class Int {
	int data;
public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}
	operator int() { return data; }
	// 전위 연산자
	Int& operator++() {
		data++;
		std::cout << "prefix" << std::endl;
		return *this;
	}
	Int& operator--() {
		data--;
		std::cout << "prefix" << std::endl;
		return *this;
	}
	// 후위 연산자
	Int operator++(int x) {
		Int temp(*this);
		data++;
		std::cout << "postfix" << std::endl;
		return temp; // 일단 초기에 복사해둔값을 돌려놓지만 사실 원래 data는 1 커짐
	}
	Int& operator--(int x) {
		Int temp(*this);
		data--;
		std::cout << "postfix" << std::endl;
		return temp; // 일단 초기에 복사해둔값을 돌려놓지만 사실 원래 data는 1 커짐
	}
	int get_x() const {
		return data;
	}
};

void func(const Int& i) {
	std::cout << "Int : " << i.get_x() << std::endl;
}
int wasdmain() {
	Int x = 3;
	int a = x + 4;
	std::cout << a << std::endl;

	func(++x);
	func(--x);
	std::cout << x.get_x() << std::endl;
	return 0;
}