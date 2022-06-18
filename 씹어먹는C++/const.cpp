//const, const, const!

#include <iostream>
class NewMarine {
	static int total_marine_num; // static variable 
	const static int i = 0; // static variable
	int hp;
	int coord_x, coord_y;
	const int default_damage;
	bool is_dead;

public:
	NewMarine();
	NewMarine(int x, int y);
	NewMarine(int x, int y, int default_damege);
	int attack();
	NewMarine& be_attacked(int damage_earn);
	void move(int x, int y);
	void show_status();
	static void show_total_marine();
	~NewMarine() { total_marine_num--; }
};
int NewMarine::total_marine_num = 0;
NewMarine::NewMarine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}
NewMarine::NewMarine(int x, int y) 
	: hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {
	total_marine_num++;
}
NewMarine::NewMarine(int x, int y, int default_damage)
	: hp(50), coord_x(x), coord_y(y), default_damage(default_damage), is_dead(false) {
	total_marine_num++;
}
void NewMarine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int NewMarine::attack() {
	return default_damage;
}
NewMarine& NewMarine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) {
		is_dead = true;
	}
	return *this;
}
void NewMarine::show_status() {
	std::cout << "***Marine***" << std::endl;
	std::cout << "Location: (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "HP : " << hp << std::endl;
	std::cout << "현재 총 마린 수 : " << total_marine_num << std::endl;
}
void NewMarine::show_total_marine() {
	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
void create_marine() {
	NewMarine marine3(10, 10, 3);
	marine3.show_status();
}
int m1a1in() {
	NewMarine marine1(2, 3, 5);
	NewMarine marine2(3, 5, 10);
	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "마린 1이 마린 2를 공격" << std::endl;
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
	marine1.show_status();
	marine2.show_status();
	return 0;
}