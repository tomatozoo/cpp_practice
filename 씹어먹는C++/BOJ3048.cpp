#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main3048() {
	// ù��° �׷�, �ι�° �׷��� ������
	int n1, n2;
	std::string ant1_tmp, ant2_tmp;
	std::cin >> n1 >> n2;
	// ù��° �׷� ����
	std::cin >> ant1_tmp;
	std::vector<char> list1(ant1_tmp.begin(), ant1_tmp.end());
	std:reverse(ant1_tmp.begin(), ant1_tmp.end());
	// �ι�° �׷� ����
	std::cin >> ant2_tmp;
	std::vector<char> list2(ant2_tmp.begin(), ant2_tmp.end());
	
	// t�� ��
	int t;
	std::cin >> t;
	std::vector<int> beet(n1 + 1);
	beet[n1] = n2;
	
	for (int i = 0; i < t; i++) {
		// t�ʸ��� ���� ����
		for (int j = 1; j < n1 + 1; j++) {
			if (beet[j] > 0) {
				beet[j] -= 1;
				beet[j - 1] += 1;
			}
		}
	}
	// t�� �� ������ ���߾� ���
	int saveIndex = 0;
	for (int i = 0; i < beet[0]; i++) {
		std::cout << ant2_tmp[i];
	}
	saveIndex += beet[0];
	for (int i = 0; i < n1; i++) {
		std::cout << ant1_tmp[i];
		for (int j = 0; j < beet[i+1]; j++) {
			std::cout << ant2_tmp[saveIndex + j];
		}
		saveIndex += beet[i + 1];
	}
	
	return 0;
}