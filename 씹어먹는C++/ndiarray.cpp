#include <iostream>
#include <string>

int wastdingmain() {
	std::string s = "abc";
	std::string t = "def";
	std::string s2 = s;

	std::cout << s << "�� ���� : " << s.length() << std::endl;
	std::cout << s << " �ڿ� " << t << " �� ���̸� : " << s + t << std::endl;

	if (s == s2) {
		std::cout << "����" << std::endl;
	}
	if (s != t) {
		std::cout << "�ٸ���" << std::endl;
	}
	std::cout << s << std::endl;
	return 0;
}