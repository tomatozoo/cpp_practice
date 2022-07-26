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

class Manager {
	std::string name;
	int age;

	std::string position;
	int rank;
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		: year_of_service(year_of_service), name(name), age(age), position(position), rank(rank) {}

	Manager(const Manager& manager) {
		name = manager.name;
		age = manager.age;
		position = manager.position;
		rank = manager.rank;
		year_of_service = manager.year_of_service;
	}

	Manager() {}

	int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }

	void print_info() {
		std::cout << name << " (" << position << ", " << age << ", " << year_of_service << "년차) ==> " << calculate_pay() << "만원 " << std::endl;
	}

};
class EmployeeList {
	int alloc_employee; // 데이터의 크기
	int current_employee; // 실제 양
	int current_manager;
	Employee** employee_list;
	Manager** manager_list;

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
		employee_list = new Employee * [alloc_employee];
		manager_list = new Manager * [alloc_employee];
		current_employee = 0;
		current_manager = 0;
	}

	void add_employee(Employee* employee) {
		employee_list[current_employee] = employee;
		current_employee++;
	}
	void add_manager(Manager* manager) {
		manager_list[current_manager] = manager;
		current_manager++;
	}
	int current_employee_num() { return current_employee + current_manager; }
	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++)
		{
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		for (int i = 0; i < current_manager; i++)
		{
			manager_list[i]->print_info();
			total_pay += manager_list[i]->calculate_pay();
		}
		std::cout << "총 임금 : " << total_pay << std::endl;
	}
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		delete[] employee_list;

		for (int i = 0; i < current_manager; i++) {
			delete manager_list[i];
		}
		delete[] manager_list;
	}
};
int mawasin() {
	EmployeeList emp_list(10);
//	(std::string name, int age, std::string position, int rank)
	emp_list.add_manager(new Manager("유재석", 50, "부장",1,12));
	emp_list.add_employee(new Employee("박명수", 48, "차장",2));
	emp_list.add_employee(new Employee("정준하", 40, "과장", 3));
	emp_list.add_employee(new Employee("정형돈", 35, "대리", 4));
	emp_list.add_employee(new Employee("노홍철", 30, "사원", 5));

	emp_list.add_employee(new Employee("하하", 28, "사원", 5));
	emp_list.add_employee(new Employee("길", 25, "인턴", 7));
	emp_list.print_employee_info();

	return 0;
}