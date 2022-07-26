#include <iostream>

class Base {
protected:
	std::string parent_string;
public:
	Base() : parent_string("Base") {
		std::cout << "Base Class" << std::endl;
	}
	void what() {
		std::cout << "parent_string : " << parent_string << std::endl;
	}
};

class Derived : public Base {
	std::string child_string;
public:
	Derived() : Base(), child_string("파생") {
		std::cout << "파생 클래스" << std::endl;
		parent_string = "바꾸기";
	}
	void what() {
		std::cout << child_string << std::endl;
	}
};

int mai1sdfn() {
	Derived dr;
	dr.what();
	return 0;
}