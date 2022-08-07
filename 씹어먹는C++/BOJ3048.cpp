#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main3048() {
	// 첫번째 그룹, 두번째 그룹의 사이즈
	int n1, n2;
	std::string ant1_tmp, ant2_tmp;
	std::cin >> n1 >> n2;
	// 첫번째 그룹 개미
	std::cin >> ant1_tmp;
	std::vector<char> list1(ant1_tmp.begin(), ant1_tmp.end());
	std:reverse(ant1_tmp.begin(), ant1_tmp.end());
	// 두번째 그룹 개미
	std::cin >> ant2_tmp;
	std::vector<char> list2(ant2_tmp.begin(), ant2_tmp.end());
	
	// t초 뒤
	int t;
	std::cin >> t;
	std::vector<int> beet(n1 + 1);
	beet[n1] = n2;
	
	for (int i = 0; i < t; i++) {
		// t초마다 도는 루프
		for (int j = 1; j < n1 + 1; j++) {
			if (beet[j] > 0) {
				beet[j] -= 1;
				beet[j - 1] += 1;
			}
		}
	}
	// t초 뒤 구성에 맞추어 출력
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