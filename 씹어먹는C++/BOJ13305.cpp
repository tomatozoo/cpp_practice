#include <iostream>

int main13305() {
	//// �Է� 
	// ������ ����
	int n;
	std::cin >> n;
	// ������ �� ���ø� �����ϴ� ������ ����
	int* road = new int[n - 1];
	for (int i = 0; i < n - 1; i++) {
		int tmp;
		std::cin >> tmp;
		road[i] = tmp;
	}
	// �������� ���ʹ� ����
	int* oil = new int[n];
	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		oil[i] = tmp;
	}

	std::cout << "���� ���� ���ÿ��� ���� ������ ���÷� ���� �ּ� ���" << std::endl;
	return 0;
}