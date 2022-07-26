#include <iostream>
#include "point.h"


class Grid {
	int** grid; // 2차원 배열
	int row, column;

public:
	Grid() {
		row = 1;
		column = 1;
		grid = new int* [1];
	}
	Grid(int r, int c) {
		row = r;
		column = c;
		grid = new int* [r];
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