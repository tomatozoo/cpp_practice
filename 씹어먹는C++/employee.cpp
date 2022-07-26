#include <iostream>
#include <string>

class Employee {
	std::string name;
	int age;

	std::string position;
	int rank;
	
public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}

	// 복사 생성자
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	Employee() {}

	void print_info() {
		std::cout<< name << " (" <<position << " , "<<age << ") ==> " << calculate_pay() << "만원" << std::endl;
	}

	int calculate_pay() { return 200 + rank * 50; }
};

class EmployeeList {
	int alloc_employee; // 데이터의 크기
	int current_employee; // 실제 양
	Employee** employee_list;

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		current_employee = 0;
	}

	void add_employee(Employee* employee) {
		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_num() { return current_employee; }
	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++)
		{
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		std::cout << "총 임금 : " << total_pay << std::endl;
	}
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		delete[] employee_list;
	}
};
int main() {
	return 0;
}