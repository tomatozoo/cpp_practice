#include <iostream>
#include <string>

int main1436() {
	int n;
	std::cin >> n;

	int tmp=666;
	while (true) {
		// tmp�� �ѹ��̶� 666�� �����Ѵٸ�
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