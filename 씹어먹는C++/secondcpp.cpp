#include <iostream>

int secondcpp() {
	// �⺻ ����
	int i=0;
	char c='c';
	double d=1.5;
	float f=1.8;
	// ������ ����
	int arr[10] = { 0 };
	int* parr = arr;
	int j = 0;
	int* pi = &j;
	// �ݺ��� - for
	for (i=0; i < 10; i++)
	{
		std::cout << i << std::endl;
		j += i;
	}
	std::cout << j << std::endl;
	// �ݺ��� - while
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
	// �ݺ��� - ����
	int lucky_number = 3;
	std::cout << "�� ���� ���纸����" << std::endl;
	int user_input;
	while (1) {
		std::cout << "�Է� : " << std::endl;
		std::cin >> user_input;
		if (lucky_number == user_input) {
			std::cout << "�����Դϴ�" << std::endl;
			break;
		}
		else
		{
			std::cout << "��" << std::endl;
		}
	}
	// �ݺ��� - switch ����
	int user_input_switch;
	std::cout << "���ڸ� �Է��ϸ�, ������ ����մϴ�" << std::endl;
	std::cout << "1. �̸�" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. ����" << std::endl;

	std::cin >> user_input_switch;
	switch (user_input_switch)
	{
	case 1:
		std::cout << "����" << std::endl;
		break;
	case 2:
		std::cout << "����" << std::endl;
		break;
	case 3:
		std::cout << "22��" << std::endl;
		break;
	default:
		std::cout << "�ñ��� �� ������..?" << std::endl;
		break;
	}
	return 0;
}