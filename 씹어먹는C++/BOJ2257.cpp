#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <sstream>


int main() {
	std::string str;
	std::cin >> str;
	std::stack<int> stk;

	int i = 0;
	while (i < str.size()) {
		if (str[i] == 'H') {
			if (stk.empty()) {
				stk.push(1);
			}
			else {
				int tmp = stk.top();
				stk.pop();
				stk.push(tmp + 1);
			}
		}
		else if (str[i] == 'C') {
			if (stk.empty()) {
				stk.push(12);
			}
			else {
				int tmp = stk.top();
				stk.pop();
				stk.push(tmp + 12);
			}
		}
		else if (str[i] == 'O') {
			if (stk.empty()) {
				stk.push(16);
			}
			else {
				int tmp = stk.top();
				stk.pop();
				stk.push(tmp + 16);
			}
		}
		else if (isdigit(str[i])) {
			int tmp = stk.top();
			int str_i = str[i] - '0';
			stk.pop();
			stk.push(tmp * str_i);
		}
		else if (str[i] == '(') {
			stk.push(-1);
		}
		else if (str[i] == ')') {
			while (stk.top() != -1) {
				int tmp = stk.top();
				stk.pop();

				if (stk.top() == -1) {
					stk.pop();
					stk.push(tmp);
					break;
				}
				else {
					int next = stk.top();
					stk.pop();
					stk.push(next + tmp);
				}
			}
		}
		i++; 
	}

	int answer = 0;
	while (!stk.empty()) {
		answer += stk.top();
		stk.pop();
	}
	std::cout << answer << std::endl;

	return 0;
}