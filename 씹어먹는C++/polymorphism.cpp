#include <iostream>
#include <string>

class Basee {
	std::string s;
public:
	Basee() : s("기반") { std::cout << "기반 클래스" << std::endl; }
	virtual void what() { std::cout << s << std::endl; }
};
class Deriveed : public Basee {
	std::string s;
public:
	Deriveed() : s("파생"), Basee() { std::cout << "파생 클래스" << std::endl; }
	void what() override { std::cout << s << std::endl; }
};
int maasdin() {
	std::cout << "기반 클래스 생성" << std::endl;
	Basee p;

	std::cout << "파생 클래스 생성" << std::endl;
	Deriveed c;

	std::cout << "포인터 버전" << std::endl;
	Basee* p_c = &c;
	Basee* p_p = &p;

	std::cout << "실제 객체는 Derived" << std::endl;
	p_c->what(); //이러면 기반이 나올 것 같다

	std::cout << "실제 객체는 Base" << std::endl;
	p_p->what(); //이러면 기반이 나올 것 같다

	return 0;
}