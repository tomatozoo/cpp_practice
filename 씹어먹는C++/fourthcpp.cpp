// 51������~61������
#include <iostream>

int fourth_one() {
	// C++������ malloc, free�� ����� �� �ִ�
	// C++������ �߰������� new�� delete�� ����Ѵ�. 
	// new ���� Type* pointer_name = new Type;
	int* p = new int;
	// ������ ������ �Ҵ�
	*p = 10;
	std::cout << *p << std::endl;
	// �޸� ����
	delete p;
	//new�� �迭 �Ҵ��ϱ�
	int arr_size;
	std::cout << "array size: "; //endl�� �� �ؼ� �ٹٲ��� ����
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
	//���ƿ� ������

	return 0;
}