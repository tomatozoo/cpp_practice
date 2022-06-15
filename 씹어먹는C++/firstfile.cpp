#include <iostream>
#include "header1.h"
#include "header2.h"
// 헤더 파일을 include 시킨다

namespace {
	int OnlyInThisFile() {}
	int only_in_this_file = 0;
}

// 메인 함수
int first() {
	// 표준 입출력
	std::cout << "Hi there" << std::endl;
	std::cout << "Hi there" << std::endl
		<< "my name is "
		<< "Psi" << std::endl;
	header1::foo();
	header2::foo();
	return 0;
}