#include <string.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS //visual studio 2015 뒤부터 scanf, fopen, strcpy 문제 발생해서 이 부분 필요
#pragma warning(disable:4996)

class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;
	char* name;
public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, const char* cannon_name);
	Photon_Cannon(const Photon_Cannon& pc);
	void show_status();
	~Photon_Cannon();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) { // C++에서 &란, 참조자임 주의
	std::cout << "복사 생성자 호출 ! " << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}
Photon_Cannon::Photon_Cannon(int x, int y) {
	std::cout << "일반 생성자 호출 ! " << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	name = NULL;
}
Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
	std::cout << "이름있는 생성자 호출 ! " << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
	if (name) delete[] name;
}
void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon : " << name << std::endl;
	std::cout << "Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "HP : " << hp << std::endl;
}

int ma1in() {
	Photon_Cannon cannon1(3, 5,"ImCannon");
	Photon_Cannon cannon2(cannon1);
	// == Photon_Cannon cannon2 = cannon1;

	return 0;
}