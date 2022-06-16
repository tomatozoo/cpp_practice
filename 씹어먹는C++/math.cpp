#include <iostream>
#include <algorithm>
#include <cmath>

class Point {
	int x, y;
public:
	Point(int pos_x, int pos_y) {
		x = pos_x;
		y = pos_y;
	}
	int getPosX() {
		return x;
	}
	int getPosY() {
		return y;
	}
	void printPoint() {
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}
};

class Geometry {
	//point 클래스 포인터의 배열
	Point* point_array[100];
	int index;
public:
	Geometry(Point** point_list) {
		for (int i = 0; i < 100; i++)
		{
			point_array[i] = *point_list;
			point_list++;
		}
		index = 0;
	}
	Geometry() {
		Point pt(0, 0);
		Point* pt_ptr = &pt;
		for (int i = 0; i < 100; i++)
		{
			point_array[i] = pt_ptr;
		}
		index = 0;
	}
	//Geometry();
	void AddPoint(Point& point);
	void PrintDistance();
	void PrintNumMeets();
	void PrintList();
};

void Geometry::PrintList() {
	for (int i = 0; i <= index; i++) {
		(*point_array[i]).printPoint();
	}
	return;
}
void Geometry::AddPoint(Point& point) {
	point_array[index] = &point;
	index++;
	return;
}
void Geometry::PrintDistance() {
	for (int i = 0; i <= index; i++)
	{
		for (int j = i+1; j <= index; j++)
		{
			int subx = (*point_array[i]).getPosX()- (*point_array[j]).getPosX();
			double pow_x = pow(subx, 2); 
			int suby = (*point_array[i]).getPosY() - (*point_array[j]).getPosY();
			double pow_y = pow(suby, 2);
			double sqrt_xy = sqrt(pow_x + pow_y);
			std::cout << sqrt_xy << std::endl;
		}
	}
	return;
}
void Geometry::PrintNumMeets() {
	return;
}

int main1() {
	Point pt(0, 0);
	Point* pt_ptr = &pt;
	Point* pt_lst[100];
	for  (int i = 0; i < 100; i++)
	{
		pt_lst[i] = pt_ptr;
	}
	Geometry geo = Geometry(pt_lst);
	for (int i = 0; i < 10; i++) {
		Point newpt(i*10, i * 30);
		newpt.printPoint();
		geo.AddPoint(newpt);
	}
	geo.PrintList();
	geo.PrintDistance();
	return 0;
}