//복사 생성자와 소멸자
//소멸자
//복사 생성자
//디폴트 복사 생성자의 한계
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS //visual studio 2015 뒤부터 scanf, fopen, strcpy 문제 발생해서 이 부분 필요
#pragma warning(disable:4996)

class Marine {
	// private 범주 : 객체의 내부적 성질, 상태에 관한 변수
	int hp;
	int coord_x, coord_y;
	int damage;
	bool is_dead;
	char* name;
public:
	// public 범주 : 객체가 외부에 하는 행동(함수)
	Marine();
	Marine(int x, int y, const char* marine_name);
	~Marine();
	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);
	void show_status();
};
class Test {
	char c;
public:
	Test(char _c) {
		c = _c;
		std::cout << "생성자 호출" << c << std::endl;
	}
	~Test() {
		std::cout << "소멸자 호출" << c << std::endl;
	}
};
void simple_function() {
	Test b('b');
}
Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	name = new char[strlen(marine_name) + 1]; //name 배열을 생성한 뒤에, 
	strcpy(name, marine_name); // 배열에 배열을 복사해준다. 
}
int Marine::attack() {
	return damage;
}
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) {
		is_dead = true;
	}
}
void Marine::show_status() {
	std::cout << "***Marine : " << name << " ***"<< std::endl;
	std::cout << " Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << " HP : " << hp << std::endl;
}
Marine::~Marine() {
	//delete가 나중에 호출된다
	std::cout << name << " 의 소멸자 호출 ! " << std::endl;
	if (name != NULL) {
		delete[] name; //배열 delete이니까 delete[]
	}
}


int mai1n() {
	//하나하나 정의하는 방식
	Marine marine1(2, 3,"Marine 1");
	Marine marine2(3, 5,"Marine 2");
	marine1.show_status();
	marine2.show_status();
	std::cout << std::endl << "마린1이 마린2를 공격!" << std::endl;
	marine2.be_attacked(marine1.attack());
	marine1.show_status();
	marine2.show_status();

	//여러 인스턴스를 한번에 만드는 방식
	Marine* marines[100];
	marines[0] = new Marine(2, 3, "Marine 3");
	// 인스턴스를 동적으로 메모리에 생성 + 자동으로 생성자를 호출해준다. 
	marines[1] = new Marine(3, 5, "Marine 4");
	marines[0]->be_attacked(marines[1]->attack());
	marines[0]->show_status();
	marines[1]->show_status();
	delete marines[0]; //메모리에서 삭제
	delete marines[1];
	//소멸자를 이용해서 자동으로 메모리를 정리하는 기능이 있다. 

	Test a('a');
	simple_function();
	// 객체가 다른 부분에 영향을 끼치지 않도록 깔끔하게 소멸시킨다
	// 객체가 동적으로 할당받은 메모리를 해제시킨다. 
	return 0;
}