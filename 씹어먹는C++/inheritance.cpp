#include <iostream>

// ��� Ŭ����
class Base {
	std::string s;
public:
	Base() : s("���") {
		std::cout << "��� Ŭ����" << std::endl;
	}

	void what() {
		std::cout << s << std::endl;
	}
};

class Derived : public Base {
	std::string s;
public:
	Derived() : Base(), s("�Ļ�") {
		std::cout << "�Ļ� Ŭ����" << std::endl;
		// Base Ŭ������ �Լ��� ȣ���ϴ� ���� ������
		// derived ��ü�� �ϳ� ����鼭 what �Լ��� ȣ����. 
		// �̶� Base Ŭ������ �����ڴ� s�� "���"���� �ʱ�ȭ���ش�.
		what();
		std::cout << "Derived�� s ���� " << s << std::endl;
	}
};
int main() {
	std::cout << "��� Ŭ���� ����" << std::endl;
	Base p;
	std::cout << "�Ļ� Ŭ���� ����" << std::endl;
	Derived c;

	return 0;
}