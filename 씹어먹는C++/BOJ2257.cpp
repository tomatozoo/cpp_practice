#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stack>
#include <cstring>


int main2257() {
	char* str = new char[100];
	scanf("%s", str);
	int size = strlen(str);
	std::stack<int> stk;

	int i = 0;
	while (i < size) {
		if (str[i] == '(') {
			stk.push(-1);
		}
		else if (str[i] == ')') {
			int tmp = 0;
			while (stk.top() != -1) {
				tmp += stk.top();
				stk.pop();
			}
			// 이제 stk.top()==-1
			stk.pop();
			stk.push(tmp);
		}
		else if (str[i] == 'H') {
			stk.push(1);
		}
		else if (str[i] == 'C') {
			stk.push(12);
		}
		else if (str[i] == 'O') {
			stk.push(16);
		}
		else { // 숫자
			int tmp=0;
			tmp = stk.top();
			stk.pop();
			int number = str[i] - '0';
			tmp *= number;
			stk.push(tmp);
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