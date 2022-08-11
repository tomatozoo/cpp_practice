#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;

	int tmp=666;
	while (true) {
		// tmp에 한번이라도 666이 등장한다면
		if (std::to_string(tmp).find("666") != std::string::npos) {
			n--;
			if (n == 0) {
				break;
			}
		}
		tmp++;
	}
	std::cout << tmp << std::endl;
	return 0;
}