//���� �����ڿ� �Ҹ���
//�Ҹ���
//���� ������
//����Ʈ ���� �������� �Ѱ�
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS //visual studio 2015 �ں��� scanf, fopen, strcpy ���� �߻��ؼ� �� �κ� �ʿ�
#pragma warning(disable:4996)

class Marine {
	// private ���� : ��ü�� ������ ����, ���¿� ���� ����
	int hp;
	int coord_x, coord_y;
	int damage;
	bool is_dead;
	char* name;
public:
	// public ���� : ��ü�� �ܺο� �ϴ� �ൿ(�Լ�)
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
		std::cout << "������ ȣ��" << c << std::endl;
	}
	~Test() {
		std::cout << "�Ҹ��� ȣ��" << c << std::endl;
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
	name = new char[strlen(marine_name) + 1]; //name �迭�� ������ �ڿ�, 
	strcpy(name, marine_name); // �迭�� �迭�� �������ش�. 
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
	//delete�� ���߿� ȣ��ȴ�
	std::cout << name << " �� �Ҹ��� ȣ�� ! " << std::endl;
	if (name != NULL) {
		delete[] name; //�迭 delete�̴ϱ� delete[]
	}
}


int mai1n() {
	//�ϳ��ϳ� �����ϴ� ���
	Marine marine1(2, 3,"Marine 1");
	Marine marine2(3, 5,"Marine 2");
	marine1.show_status();
	marine2.show_status();
	std::cout << std::endl << "����1�� ����2�� ����!" << std::endl;
	marine2.be_attacked(marine1.attack());
	marine1.show_status();
	marine2.show_status();

	//���� �ν��Ͻ��� �ѹ��� ����� ���
	Marine* marines[100];
	marines[0] = new Marine(2, 3, "Marine 3");
	// �ν��Ͻ��� �������� �޸𸮿� ���� + �ڵ����� �����ڸ� ȣ�����ش�. 
	marines[1] = new Marine(3, 5, "Marine 4");
	marines[0]->be_attacked(marines[1]->attack());
	marines[0]->show_status();
	marines[1]->show_status();
	delete marines[0]; //�޸𸮿��� ����
	delete marines[1];
	//�Ҹ��ڸ� �̿��ؼ� �ڵ����� �޸𸮸� �����ϴ� ����� �ִ�. 

	Test a('a');
	simple_function();
	// ��ü�� �ٸ� �κп� ������ ��ġ�� �ʵ��� ����ϰ� �Ҹ��Ų��
	// ��ü�� �������� �Ҵ���� �޸𸮸� ������Ų��. 
	return 0;
}