#include <iostream>

// 기반 클래스
class Base {
	std::string s;
public:
	Base() : s("기반") {
		std::cout << "기반 클래스" << std::endl;
	}

	void what() {
		std::cout << s << std::endl;
	}
};

class Derived : public Base {
	std::string s;
public:
	Derived() : Base(), s("파생") {
		std::cout << "파생 클래스" << std::endl;
		// Base 클래스의 함수를 호출하는 것이 가능함
		// derived 객체를 하나 만들면서 what 함수를 호출함. 
		// 이때 Base 클래스의 생성자는 s를 "기반"으로 초기화해준다.
		what();
		std::cout << "Derived의 s 값은 " << s << std::endl;
	}
};
int main() {
	std::cout << "기반 클래스 생성" << std::endl;
	Base p;
	std::cout << "파생 클래스 생성" << std::endl;
	Derived c;

	return 0;
}