#include <iostream>
#include <algorithm>
#include <vector>

bool compae(int i, int j) {
	return j < i;
}
int main() {
	int n;
	std::cin >> n;
	std::vector<int> lst(n);

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> tmp;
		lst.push_back(tmp);
	}

	std::sort(lst.begin(), lst.end(), compae);

	int howmuch = 0;

	for (int i = 0; i < n; i++) {
		if (i % 3 != 2) {
			howmuch += lst[i];
		}
	}

	std::cout << howmuch << std::endl;

	return 0;
}