// 51페이지~61페이지
#include <iostream>

int fourth_one() {
	// C++에서도 malloc, free를 사용할 수 있다
	// C++에서는 추가적으로 new와 delete를 사용한다. 
	// new 사용법 Type* pointer_name = new Type;
	int* p = new int;
	// 포인터 변수에 할당
	*p = 10;
	std::cout << *p << std::endl;
	// 메모리 해제
	delete p;
	//new로 배열 할당하기
	int arr_size;
	std::cout << "array size: "; //endl을 안 해서 줄바꿈이 없음
	std::cin >> arr_size;
	int* list = new int[arr_size];
	for (int i = 0; i < arr_size; i++) {
		std::cin >> list[i];
	}
	for (int i = 0; i < arr_size; i++) {
		std::cout << list[i] << std::endl;
	}
	delete[] list;
	// int a
	int a = 4;
	{
		std::cout << a << std::endl;
		int a = 3;
		std::cout << a << std::endl;
	}
	std::cout << a << std::endl;
	//돌아온 마이펫

	return 0;
}