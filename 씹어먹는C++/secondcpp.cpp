#include <iostream>

int secondcpp() {
	// 기본 변수
	int i=0;
	char c='c';
	double d=1.5;
	float f=1.8;
	// 포인터 변수
	int arr[10] = { 0 };
	int* parr = arr;
	int j = 0;
	int* pi = &j;
	// 반복문 - for
	for (i=0; i < 10; i++)
	{
		std::cout << i << std::endl;
		j += i;
	}
	std::cout << j << std::endl;
	// 반복문 - while
	int k = 0, sum = 0;
	while (k<=10)
	{
		sum += k;
		k++;
	}
	std::cout << sum << std::endl;
	if (sum==k)
	{
		std::cout << "is equal" << std::endl;
	}
	else
	{
		std::cout << "not equal" << std::endl;
	}
	// 반복문 - 예제
	int lucky_number = 3;
	std::cout << "내 수를 맞춰보세요" << std::endl;
	int user_input;
	while (1) {
		std::cout << "입력 : " << std::endl;
		std::cin >> user_input;
		if (lucky_number == user_input) {
			std::cout << "정답입니다" << std::endl;
			break;
		}
		else
		{
			std::cout << "땡" << std::endl;
		}
	}
	// 반복문 - switch 예제
	int user_input_switch;
	std::cout << "숫자를 입력하면, 정보를 출력합니다" << std::endl;
	std::cout << "1. 이름" << std::endl;
	std::cout << "2. 성별" << std::endl;
	std::cout << "3. 나이" << std::endl;

	std::cin >> user_input_switch;
	switch (user_input_switch)
	{
	case 1:
		std::cout << "용주" << std::endl;
		break;
	case 2:
		std::cout << "여자" << std::endl;
		break;
	case 3:
		std::cout << "22세" << std::endl;
		break;
	default:
		std::cout << "궁금한 게 없나요..?" << std::endl;
		break;
	}
	return 0;
}