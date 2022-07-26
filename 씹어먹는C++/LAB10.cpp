#include <iostream>

// 1. class declaration
class Point {
	int x, y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) : x(x), y(y) {}

	void print_point() {
		std::cout << "( " << x << ", " << y << " )" << std::endl;
	}
	
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

};

class Grid {
	int** grid; // 2차원 배열
	int row, column;

public:
	Grid() {
		row = 1;
		column = 1;
		grid = new int*[1];
	}
	Grid(int r, int c) {
		row = r;
		column = c;
		grid = new int*[r];
		for (int i = 0; i < row; i++) {
			grid[i] = new int[column];
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				grid[i][j] = 0;
			}
		}
	}
	Grid(Grid& g) {
		row = g.getRow();
		column = g.getColumn();
		grid = new int* [row];
		for (int i = 0; i < row; i++) {
			grid[i] = new int[column];
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				grid[i][j] = g.getPoint(i, j);
			}
		}
	}
	int getRow() {
		return row;
	}
	int getColumn() {
		return column;
	}
	int getPoint(int r, int c) {
		return grid[r][c];
	}

	void PrintGrid() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				std::cout << grid[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	void setAt(int r, int c, int val) {
		grid[r][c] = val;
	}

	~Grid() {
		for (int i = 0; i < row; i++) {
			delete[] grid[i];
		}
		delete[] grid;
		std::cout << "Clean-up Grid" << std::endl;
	}
};

void printNumberGrid(Grid& g) {
	Grid tmp(g);

	for (int i = 0; i < tmp.getRow(); i++) {
		for (int j = 0; j < tmp.getColumn(); j++) {
			std::cout << g.getPoint(i, j) + 1 << " ";
		}
		std::cout << std::endl;
	}
}
void problem1() {
	Point p(1, 3);
	Grid g(2, 3);

	std::cout << "x : "<< p.getX() << "y : " << p.getY() << std::endl;

	g.PrintGrid();
}
// 2. copy constructor
void problem2() {
	Grid g(2, 3);
	g.setAt(0, 0, 1);
	g.PrintGrid();
	printNumberGrid(g);
	g.PrintGrid();
}
// 3. destructor
void problem3() {
	Grid g(2, 3);
	g.PrintGrid();
}

// 4. interface vs implementation


int mawasderin() {
	problem3();
	return 0;
}