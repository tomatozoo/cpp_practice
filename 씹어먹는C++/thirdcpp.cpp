#include <iostream>
int change_cal(int* p) {
	*p = 3;
	return 0;
}
//함수 인자로 레퍼런스 받기 예제
int change_ref(int& p) {
	p = 5;
	return 0;
}
int function() {
	int a = 2;
	return a;
}
int& function1() {
	int a = 2;
	return a;
}
int& function(int& a) {
	a = 5;
	return a;
}
int function2() {
	int a = 5;
	return a;
}
int third() {
	// c 언어의 방식
	int number = 5;
	std::cout << number << std::endl;
	change_cal(&number);
	std::cout << number << std::endl;
	// c++ reference를 이용하는 방식
	int a = 3;
	int& another_a = a;
	std::cout << another_a << std::endl;
	another_a = 5;
	std::cout << another_a << std::endl;
	//함수 인자로 레퍼런스 받기 예제
	int number_fct = 3;
	std::cout << number_fct << std::endl;
	change_ref(number_fct);
	std::cout << number_fct << std::endl;
	//참조자 예제
	int x = 0;
	int& y = x;
	int& z = x;
	x = 1;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
	x = 3;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
	x = 5;
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
	//상수에 대한 참조자
	//상수 그 자체에는 참조자를 붙일 수 없다. 
	//int& ref = 4;
	const int& ref = 4;
	int k = ref;
	std::cout << k << std::endl;
	//래퍼런스의 배열 : 불가능함
	int ii, jj;
	//int& arry[2] = { ii, jj };
	// 배열의 래퍼런스 : 가능함
	int arr1[1] = { 0 };
	int arr2[2] = { 0 };
	int arr3[3] = { 0 };
	int(& ref1)[1] = arr1;
	int(& ref2)[2] = arr2;
	int(& ref3)[3] = arr3;
	std::cout << arr1 << std::endl;
	std::cout << arr2 << std::endl;
	//레퍼런스를 리턴하는 함수
	int b = function(); // 리턴된 a 값이 b에 복사된다. function이 종료되면 a는 메모리에서 사라진다. 
	//레퍼런스를 받아 레퍼런스를 리턴하는 함수
	int d = 2;
	int& e = d;
	int w = function(e);
	std::cout << w << std::endl;
	//참조자가 아닌 값을 리턴하는 함수를 참조자로 받기
	// 상수 레퍼런스를 돌려줄 때 제외하고는 불가능
	const int& l = function2();
	return 0;
}

