#include <iostream>
#include <array>

// int 5 사이즈 array 만 받을 수 있음
void print(std::array<int, 5> arr) {
	for (auto ele : arr) {
		std::cout << ele << ", ";
	}
}

// 아무 사이즈만 받게 template 사용
template <size_t N>
void print(std::array<int, N> arr) {
	for (auto ele : arr) {
		std::cout << ele << ", ";
	}
}

int main() {
	// 배열 선언
	std::array<int, 10> ary;
	
	// 값 할당
	ary[0] = 1;

	// 출력
	std::cout << ary[0];

	// 인덱싱
	std::cout << ary.at(0);
	std::cout << ary[0];

	// 출력
	std::array<int, 5> ary2 = { 1,2,3,4,5 };
	print(ary2);

	// 원소 접근
	ary2.begin();
	ary2.end();
	ary2.front(); // 첫 원소
	ary2.back(); // 마지막 원소
	ary2.data(); // 포인터격

	// 반복문 스타일
	for (auto it = ary2.begin(); it != ary2.end(); it++) {
		auto element = (*it);
		std::cout << element << ' ';
	}
	return 0;
}