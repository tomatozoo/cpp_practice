#include <iostream>
#include "header1.h"
#include "header2.h"
// ��� ������ include ��Ų��

namespace {
	int OnlyInThisFile() {}
	int only_in_this_file = 0;
}

// ���� �Լ�
int first() {
	// ǥ�� �����
	std::cout << "Hi there" << std::endl;
	std::cout << "Hi there" << std::endl
		<< "my name is "
		<< "Psi" << std::endl;
	header1::foo();
	header2::foo();
	return 0;
}