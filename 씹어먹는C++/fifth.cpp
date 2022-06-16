// assembly language
// procedural programming
// object oriented language
#include <iostream>
class Animal {
private:
	int food;
	int weight;
public:
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}
	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}
	void view_stat() {
		std::cout << "food: " << food << std::endl;
		std::cout << "weight: " << weight << std::endl;
	}
}; //세미콜론 필요함

class Date
{
private:
	int year_;
	int month_;
	int date_;
public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		date_ = date;
	}
	void AddDay(int inc) {
		int date_info[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		date_ += inc;
		while (true)
		{
			if (date_ <= date_info[month_]) {
				break;
			}
			else {
				date_ -= date_info[month_];
				AddMonth(1);
			}
		}
	}
	void AddMonth(int inc) {
		month_ += inc;
		if (month_ > 12) {
			year_ += (month_ / 12);
			month_ -= month_ % 12;
		}
	}
	void ShowDate() {
		std::cout<<year_<<"/"<<month_<<"/"<<date_<< std::endl;
	}
};

int main() {
	Animal animal;
	animal.set_animal(100, 50);
	animal.increase_food(30);
	animal.view_stat();

	Date date;
	date.SetDate(2022, 6, 16);
	date.ShowDate();
	date.AddMonth(10);
	date.ShowDate();
	date.AddDay(100);
	date.ShowDate();


	return 0;
}