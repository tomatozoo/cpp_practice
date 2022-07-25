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


};
int main() {
	return 0;
}