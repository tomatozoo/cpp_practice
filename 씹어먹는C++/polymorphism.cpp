#include <iostream>
#include <string>

class Basee {
	std::string s;
public:
	Basee() : s("���") { std::cout << "��� Ŭ����" << std::endl; }
	virtual void what() { std::cout << s << std::endl; }
};
class Deriveed : public Basee {
	std::string s;
public:
	Deriveed() : s("�Ļ�"), Basee() { std::cout << "�Ļ� Ŭ����" << std::endl; }
	void what() override { std::cout << s << std::endl; }
};
int maasdin() {
	std::cout << "��� Ŭ���� ����" << std::endl;
	Basee p;

	std::cout << "�Ļ� Ŭ���� ����" << std::endl;
	Deriveed c;

	std::cout << "������ ����" << std::endl;
	Basee* p_c = &c;
	Basee* p_p = &p;

	std::cout << "���� ��ü�� Derived" << std::endl;
	p_c->what(); //�̷��� ����� ���� �� ����

	std::cout << "���� ��ü�� Base" << std::endl;
	p_p->what(); //�̷��� ����� ���� �� ����

	return 0;
}