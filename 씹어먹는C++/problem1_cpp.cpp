#include <iostream>
#include <vector>
#include <string>
//.

class FlipWaffle
{
public:
	int frontWa;
	int backWa;
	int thousand = 1000;
	std::vector<std::vector<int>> waffle;

	FlipWaffle(int row, int col) {
		std::vector<std::vector<int>> waffle(row, std::vector<int>(col, 0));
		frontWa = row * col;
		backWa = 0;
	}
	~FlipWaffle() {}
	void front(int x1, int y1, int x2, int y2);
	void back(int x1, int y1, int x2, int y2);
	void flip(int x1, int y1, int x2, int y2);
	void end();

private:

};

void FlipWaffle::front(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2 + 1; i++) {
		for (int j = y1; j < y2 + 1; j++) {
			if (waffle[i][j] == 1) {
				
			}
		}
	}
}
void FlipWaffle::back(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2 + 1; i++) {
		for (int j = y1; j < y2 + 1; j++) {

		}
	}
}
void FlipWaffle::flip(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2 + 1; i++) {
		for (int j = y1; j < y2 + 1; j++) {

		}
	}
}
void FlipWaffle::end() {
	std::cout << frontWa << std::endl;
}

int main() {
	
	return 0;
} // hi