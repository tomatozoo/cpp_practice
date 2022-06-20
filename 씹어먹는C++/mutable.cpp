#include <iostream>
class A
{
	mutable int data_;
public:
	A(int data) : data_(data) {}
	void DoSth(int x) const {
		data_ = x;
	}
	void PrintData() const {
		std::cout << "data : " << data_ << std::endl;
	}
};

int ma1i1n1() {
	A a(10);
	a.DoSth(3);
	a.PrintData();
	return 0;
}