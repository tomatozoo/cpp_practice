#include <iostream>
#include <array>

// int 5 ������ array �� ���� �� ����
void print(std::array<int, 5> arr) {
	for (auto ele : arr) {
		std::cout << ele << ", ";
	}
}

// �ƹ� ����� �ް� template ���
template <size_t N>
void print(std::array<int, N> arr) {
	for (auto ele : arr) {
		std::cout << ele << ", ";
	}
}

int main() {
	// �迭 ����
	std::array<int, 10> ary;
	
	// �� �Ҵ�
	ary[0] = 1;

	// ���
	std::cout << ary[0];

	// �ε���
	std::cout << ary.at(0);
	std::cout << ary[0];

	// ���
	std::array<int, 5> ary2 = { 1,2,3,4,5 };
	print(ary2);

	// ���� ����
	ary2.begin();
	ary2.end();
	ary2.front(); // ù ����
	ary2.back(); // ������ ����
	ary2.data(); // �����Ͱ�

	// �ݺ��� ��Ÿ��
	for (auto it = ary2.begin(); it != ary2.end(); it++) {
		auto element = (*it);
		std::cout << element << ' ';
	}
	return 0;
}