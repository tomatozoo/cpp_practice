#include <iostream>
#include <string>

class Employeed {
protected:
	std::string name;
	int age;

	std::string position;
	int rank;

public:
	Employeed(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}
	Employeed(const Employeed& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}
	Employeed() {}

	virtual void print_info() {
		std::cout << name << " (" << position << " , " << age << ") ==> "
			<< calculate_pay() << "����" << std::endl;
	}
	virtual int calculate_pay() {
		return 200 + rank * 50;
	}
};

class Managerd : public Employeed {
	int year_of_service;
public:
	Managerd(std::string name, int age, std::string position, int rank, int year_of_service)
		: year_of_service(year_of_service), Employeed(name, age, position, rank) {}
	int calculate_pay() override { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() override {
		std::cout << name << " (" << position << ", " << age << ", "
			<< year_of_service << "����) ==> " << calculate_pay() << "����"
			<< std::endl;
	}
};

class EmployeeLst {
	int alloc_employee;
	int current_employee;
	Employeed** employee_list;
public:
	EmployeeLst(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employeed * [alloc_employee];
		current_employee = 0;
	}
	void add_employee(Employeed* employee) {
		employee_list[current_employee] = employee;
		current_employee++;
	}
	int current_employee_num() { return current_employee; }
	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		std::cout << "�� ��� : " << total_pay << "����" << std::endl;
	}
	~EmployeeLst() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		delete[] employee_list;
	}
};

int mwassssain() {
	EmployeeLst emp_list(10);
	emp_list.add_employee(new Employeed("��ȫö", 34, "����", 3));
	emp_list.add_employee(new Employeed("����", 34, "����", 3));
	emp_list.add_employee(new Managerd("���缮", 34, "����", 7,12));
	emp_list.add_employee(new Managerd("������", 34, "����", 5,15));
	emp_list.add_employee(new Managerd("�ڸ��", 34, "����", 6, 13));
	emp_list.add_employee(new Employeed("������", 34, "�븮", 4));
	emp_list.add_employee(new Employeed("��", 34, "����", 1));
	emp_list.print_employee_info();
	return 0;
}