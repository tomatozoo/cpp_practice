//const, const, const!

#include <iostream>
class NewMarine {
	int hp;
	int coord_x, coord_y;
	int damage;
	bool is_dead;

public:
	NewMarine();
	NewMarine(int x, int y);
	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);
	void show_status();
};

NewMarine::NewMarine() {
	hp = 50;
	coord_x = 0;
	coord_y = 0;
	damage = 5;
	is_dead = false;
}
NewMarine::NewMarine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}
void NewMarine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int NewMarine::attack() {
	return damage;
}
void NewMarine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) {
		is_dead = true;
	}
}
void NewMarine::show_status() {
	std::cout << "***Marine***" << std::endl;
	std::cout << "Location: (" << coord_x << ", " << coord_y << ")" << std::endl;
	std::cout << "HP : " << hp << std::endl;
}
int main() {
	NewMarine marine1(2, 3);
	NewMarine marine2(3, 5);
	marine1.show_status();
	marine2.show_status();
}