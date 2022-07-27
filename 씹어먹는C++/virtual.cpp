#include <iostream>
/*
class Parent {
public:
	Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
	virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};
class Child : public Parent {
public:
	Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
	~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};

int mn() {
	std::cout << "평범한 Child 생성" << std::endl;
	{
		Child c;
	}

	std::cout << "Parent 포인터로 Child를 가리킬 때" << std::endl;
	{
		Parent* p = new Child();
		delete p;
		// 이때는 Child 소멸자가 호출되지 않아 memory leak 발생
	}

	{
		Child ch;
		Parent& par = ch;
	}
}*/

class Animal {
public:
	Animal() {}
	virtual ~Animal() {}
	virtual void speak() = 0;
};
class Dog : public Animal {
public:
	Dog() : Animal() {}
	void speak() override { std::cout << "왈왈" << std::endl; }
};
class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { std::cout << "냐옹" << std::endl; }
};
int m0ain() {
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	dog->speak();
	cat->speak();
	return 0;
}
