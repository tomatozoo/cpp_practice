#include <iostream>

int main2875() {
	int n, m, k, count=0;
	std::cin >> n >> m >> k;
	int limit = (n + m - k);

	while (true) {
		if ((n <= 1) ||( m <= 0 )|| (3 * count >= limit-2)) {
			break;
		}
		else {
			n -= 2;
			m -= 1;
			count += 1;
		}
	}

	std::cout << count << std::endl;
	return 0;
}