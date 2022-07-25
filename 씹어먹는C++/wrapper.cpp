#include <iostream>

class Int {
	int data;
public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}
	operator int() { return data; }
	// ���� ������
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
	// ���� ������
	Int operator++(int x) {
		Int temp(*this);
		data++;
		std::cout << "postfix" << std::endl;
		return temp; // �ϴ� �ʱ⿡ �����صа��� ���������� ��� ���� data�� 1 Ŀ��
	}
	Int& operator--(int x) {
		Int temp(*this);
		data--;
		std::cout << "postfix" << std::endl;
		return temp; // �ϴ� �ʱ⿡ �����صа��� ���������� ��� ���� data�� 1 Ŀ��
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