#include <iostream>
#include <string>

int wastdingmain() {
	std::string s = "abc";
	std::string t = "def";
	std::string s2 = s;

	std::cout << s << "의 길이 : " << s.length() << std::endl;
	std::cout << s << " 뒤에 " << t << " 를 붙이면 : " << s + t << std::endl;

	if (s == s2) {
		std::cout << "같다" << std::endl;
	}
	if (s != t) {
		std::cout << "다르다" << std::endl;
	}
	std::cout << s << std::endl;
	return 0;
}