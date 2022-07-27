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
			<< calculate_pay() << "만원" << std::endl;
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
			<< year_of_service << "년차) ==> " << calculate_pay() << "만원"
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
		std::cout << "총 비용 : " << total_pay << "만원" << std::endl;
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
	emp_list.add_employee(new Employeed("노홍철", 34, "평사원", 3));
	emp_list.add_employee(new Employeed("하하", 34, "평사원", 3));
	emp_list.add_employee(new Managerd("유재석", 34, "부장", 7,12));
	emp_list.add_employee(new Managerd("정준하", 34, "과장", 5,15));
	emp_list.add_employee(new Managerd("박명수", 34, "차장", 6, 13));
	emp_list.add_employee(new Employeed("정형돈", 34, "대리", 4));
	emp_list.add_employee(new Employeed("길", 34, "인턴", 1));
	emp_list.print_employee_info();
	return 0;
}