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
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void ShowDate();
	Date() {
		year_ = 2022;
		month_ = 6;
		date_ = 16;
	}
	Date(int year, int month, int day) {
		year_ = year;
		month_ = month;
		date_ = day;
	}
};
void Date::SetDate(int year, int month, int date) {
	year_ = year;
	month_ = month;
	date_ = date;
}
void Date::AddDay(int inc) {
	int date_info[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
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
void Date::AddMonth(int inc) {
	month_ += inc;
	if (month_ > 12) {
		year_ += (month_ / 12);
		month_ -= month_ % 12;
	}
}
void Date::ShowDate() {
	std::cout << year_ << "/" << month_ << "/" << date_ << std::endl;
}
int fifthmain() {
	Date date(2011,3,1);
	date.ShowDate();
	Date newdate = Date();
	newdate.ShowDate();


	return 0;
}