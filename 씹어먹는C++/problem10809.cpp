#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

class FlipWaffle
{
public:
	int frontWa;
	int backWa;
	int thousand = 1000;
	std::vector<std::vector<int>> waffle;

	FlipWaffle(int row, int col) {
		for (int i = 0; i < 1000; i++) {
			std::vector<int> tmp(1000);
			waffle.push_back(tmp);
		}
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

int m.ain() {
	FlipWaffle waffle(1000, 1000);

	std::string line;
	while (true) {
		// initialize
		std::string line;
		std::cin.ignore();
		std::getline(std::cin, line);

		std::cout << "line start" << line << "line end" << std::endl;

		std::vector<std::string> current_line;

		// if empty 
		if (line.empty()) {
			waffle.end();
			break;
		}

		else if (line == "\n") {
			waffle.end();
			break;
		}

		else if (line == "\n\n") {
			waffle.end();
			break;
		}
		// else
		else {
			std::istringstream iss(line);
			std::string ch;
			while (iss >> ch) {
				current_line.push_back(ch); // 0 : ��ɾ� 1 : ���� ��ǥ 2 : through 3 : ���� ��ǥ
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
					waffle.back(x1, y1, x2, y2);
				}
				else if (current_line[0] == "ront") {
					waffle.front(x1, y1, x2, y2);
				}
				else if (current_line[0] == "lip") {
					waffle.flip(x1, y1, x2, y2);
				}
			}
		}
	}

	return 0;
}

/*
vector�� ũ�⸦ ����� ������ �׸��� �����Ϸ��� �� �� �߻�

�ذ� ���

vector�� traverse �ϴ� for�� ���� ���� (�ڰ�谪)



waffle.back/front/flip �Լ� ����
waffle ���� vector ���� ����
�ϸ� �ɵ�!

*/