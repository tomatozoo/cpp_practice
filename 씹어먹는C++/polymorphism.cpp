#include <iostream>
#include <string>

class Basee {
	std::string s;
public:
	Basee() : s("���") { std::cout << "��� Ŭ����" << std::endl; }
	void what() { std::cout << s << std::endl; }
};
class Deriveed : public Basee {
	std::string s;
public:
	Deriveed() : s("�Ļ�"), Basee() { std::cout << "�Ļ� Ŭ����" << std::endl; }
	void what() { std::cout << s << std::endl; }
};
int main() {
	std::cout << "��� Ŭ���� ����" << std::endl;
	Basee p;

	std::cout << "�Ļ� Ŭ���� ����" << std::endl;
	Deriveed c;

	std::cout << "������ ����" << std::endl;
	Basee* p_c = &c;
	p_c->what(); //�̷��� ����� ���� �� ����

	

	return 0;
}