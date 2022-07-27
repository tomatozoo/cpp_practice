#include <iostream>
#include <iostream>

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
}