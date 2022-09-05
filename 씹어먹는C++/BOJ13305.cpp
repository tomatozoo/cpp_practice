#include <iostream>

int main13305() {
	//// 입력 
	// 도시의 개수
	int n;
	std::cin >> n;
	// 인접한 두 도시를 연결하는 도로의 길이
	int* road = new int[n - 1];
	for (int i = 0; i < n - 1; i++) {
		int tmp;
		std::cin >> tmp;
		road[i] = tmp;
	}
	// 주유소의 리터당 가격
	int* oil = new int[n];
	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		oil[i] = tmp;
	}

	std::cout << "제일 왼쪽 도시에서 제일 오른쪽 도시로 가는 최소 비용" << std::endl;
	return 0;
}