/*#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

int wafmain() {
	FlipWaffle waffle(1000,1000);

	std::string tmp;
	int n;
	const char delim = ' ';

	while (true) {
		//std::cin >> n;
		
		std::getline(std::cin, tmp);
		std::cin.ignore();

		std::cout << tmp;

		if (tmp == "") {
			waffle.end();
			break;
		}
		else if (tmp == "\n") {
			waffle.end();
			break;
		}
		else if (tmp == "\n\n") {
			waffle.end();
			break;
		}
		else {
			// tmp
			std::vector<std::string> output;
			tokenize(tmp, delim, output);

			for (auto& s : output) {
				std::cout << s << '\n';
			}
		}
	}

	return 0;
} */