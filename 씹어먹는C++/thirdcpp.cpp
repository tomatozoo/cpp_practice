#include <iostream>
int change_cal(int* p) {
	*p = 3;
	return 0;
}
//�Լ� ���ڷ� ���۷��� �ޱ� ����
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
	// c ����� ���
	int number = 5;
	std::cout << number << std::endl;
	change_cal(&number);
	std::cout << number << std::endl;
	// c++ reference�� �̿��ϴ� ���
	int a = 3;
	int& another_a = a;
	std::cout << another_a << std::endl;
	another_a = 5;
	std::cout << another_a << std::endl;
	//�Լ� ���ڷ� ���۷��� �ޱ� ����
	int number_fct = 3;
	std::cout << number_fct << std::endl;
	change_ref(number_fct);
	std::cout << number_fct << std::endl;
	//������ ����
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
	//����� ���� ������
	//��� �� ��ü���� �����ڸ� ���� �� ����. 
	//int& ref = 4;
	const int& ref = 4;
	int k = ref;
	std::cout << k << std::endl;
	//���۷����� �迭 : �Ұ�����
	int ii, jj;
	//int& arry[2] = { ii, jj };
	// �迭�� ���۷��� : ������
	int arr1[1] = { 0 };
	int arr2[2] = { 0 };
	int arr3[3] = { 0 };
	int(& ref1)[1] = arr1;
	int(& ref2)[2] = arr2;
	int(& ref3)[3] = arr3;
	std::cout << arr1 << std::endl;
	std::cout << arr2 << std::endl;
	//���۷����� �����ϴ� �Լ�
	int b = function(); // ���ϵ� a ���� b�� ����ȴ�. function�� ����Ǹ� a�� �޸𸮿��� �������. 
	//���۷����� �޾� ���۷����� �����ϴ� �Լ�
	int d = 2;
	int& e = d;
	int w = function(e);
	std::cout << w << std::endl;
	//�����ڰ� �ƴ� ���� �����ϴ� �Լ��� �����ڷ� �ޱ�
	// ��� ���۷����� ������ �� �����ϰ�� �Ұ���
	const int& l = function2();
	return 0;
}

