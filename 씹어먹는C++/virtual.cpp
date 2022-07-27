#include <iostream>
/*
class Parent {
public:
	Parent() { std::cout << "Parent ������ ȣ��" << std::endl; }
	virtual ~Parent() { std::cout << "Parent �Ҹ��� ȣ��" << std::endl; }
};
class Child : public Parent {
public:
	Child() : Parent() { std::cout << "Child ������ ȣ��" << std::endl; }
	~Child() { std::cout << "Child �Ҹ��� ȣ��" << std::endl; }
};

int mn() {
	std::cout << "����� Child ����" << std::endl;
	{
		Child c;
	}

	std::cout << "Parent �����ͷ� Child�� ����ų ��" << std::endl;
	{
		Parent* p = new Child();
		delete p;
		// �̶��� Child �Ҹ��ڰ� ȣ����� �ʾ� memory leak �߻�
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
	void speak() override { std::cout << "�п�" << std::endl; }
};
class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { std::cout << "�Ŀ�" << std::endl; }
};
int m0ain() {
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	dog->speak();
	cat->speak();
	return 0;
}
