#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

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
};

void FlipWaffle::front(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2 + 1; i++) {
		for (int j = y1; j < y2 + 1; j++) {
			if (waffle[i][j] == 1) {
				frontWa += 1;
				backWa -= 1;
				waffle[i][j] = 0;
			}
		}
	}
}
void FlipWaffle::back(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2 + 1; i++) {
		for (int j = y1; j < y2 + 1; j++) {
			if (waffle[i][j] == 0) {
				frontWa -= 1;
				backWa += 1;
				waffle[i][j] = 1;
			}
		}
	}
}
void FlipWaffle::flip(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2 + 1; i++) {
		for (int j = y1; j < y2 + 1; j++) {
			if (waffle[i][j] == 0) {
				frontWa -= 1;
				backWa += 1;
				waffle[i][j] = 1;
			}
			else {
				frontWa += 1;
				backWa -= 1;
				waffle[i][j] = 0;
			}
		}
	}
}
void FlipWaffle::end() {
	std::cout << frontWa << std::endl;
}

void tokenize(std::string const& str, const char delim, std::vector<std::string>& out) {
	std::stringstream ss(str);
	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(s);
	}
}

std::vector<std::string> split(std::string s, std::string divid) {
	std::vector<std::string> v;
	char* c = strtok((char*)s.c_str(), divid.c_str());
	while (c) {
		v.push_back(c);
		c = strtok(NULL, divid.c_str());
	}
	return v;
}

int main() {
	FlipWaffle waffle(1000, 1000);

	std::string line;
	while (true) {
		// initialize
		std::string line;
		std::cin.ignore();
		std::getline(std::cin, line);
		std::vector<std::string> current_line;

		// if empty 
		if (line.empty()) {
			waffle.end();
			break;
		}

		// else
		else {
			std::istringstream iss(line);
			std::string ch;
			while (iss >> ch) {
				current_line.push_back(ch); // 0 : 명령어 1 : 시작 좌표 2 : through 3 : 종료 좌표
				std::cout << ch << std::endl;
			}

			if (current_line.size() == 4) {
				int x1, y1, x2, y2;
				std::vector<std::string> xy1 = split(current_line[1], ",");
				std::vector<std::string> xy2 = split(current_line[3], ",");
				std::stringstream ssInt1(xy1[0]);
				ssInt1 >> x1;
				std::stringstream ssInt2(xy1[1]);
				ssInt2 >> y1;
				std::stringstream ssInt3(xy2[0]);
				ssInt3 >> x2;
				std::stringstream ssInt4(xy2[1]);
				ssInt4 >> y2;

				if (current_line[0] == "ack") {
					std::cout << "back" << std::endl;
					waffle.back(x1, y1, x2, y2);
				}
				else if (current_line[0] == "ront") {
					std::cout << "front" << std::endl;
					waffle.front(x1, y1, x2, y2);
				}
				else if (current_line[0] == "lip") {
					std::cout << "flip" << std::endl;
					waffle.flip(x1, y1, x2, y2);
				}
			}
		}
	}

	return 0;
}

/*
vector의 크기를 벗어나는 데이터 항목을 참조하려고 할 때 발생





해결 방법

vector를 traverse 하는 for문 범위 점검 (★경계값)



waffle.back/front/flip 함수 점검
waffle 내부 vector 형성 점검
하면 될듯!

*/