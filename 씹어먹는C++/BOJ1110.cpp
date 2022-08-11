#include <iostream>

int mai_() {
	// 첫째 줄에 N이 주어진다
	int n;
	std::cin >> n;

	// 처음에 주어진 수의 가장 오른쪽 자리 수와
	// 구한 합의 가장 오른쪽 자리 수를 이어 붙여 새로운 수를 만들 수 있다. 

	// 몇 번만에 원래 수로 돌아올 수 있을까? 

	int tmp = n;
	int next = -1, trial = 0;
	while (next != n) {
		// 각 자리 숫자를 더한다
		int sumn = tmp % 10 + tmp / 10;

		// 처음에 주어진 수의 가장 오른쪽 자리 수와
		// 구한 합의 가장 오른쪽 자리 수를 이어 붙여 새로운 수를 만들 수 있다. 
		next = 10 * (tmp % 10 )+ sumn % 10;
		tmp = next;
		trial++;
	}

	std::cout << trial << std::endl;

	return 0;
}