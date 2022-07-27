#include <iostream>

int ma1231sin() {
	int current, picked, need;
	std::cin >> current >> picked >> need;

	int soda = 0, tmp = (current+picked), tmp_soda = 0;

	while (tmp >= need) {
		tmp_soda = tmp / need;
		tmp -= tmp_soda * need;
		tmp += tmp_soda;
		soda += tmp_soda;
		tmp_soda = 0;
	}

	std::cout << soda << std::endl;
	return 0;
}