#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <stdio.h>

int mai010828() {
	// ¸í·ÉÀÇ °³¼ö
	int n;
	scanf("%d", &n);
	std::vector<int> answer;

	std::stack<int> st;
	for (int i = 0; i < n; i++) {
		char tmp[10];
		scanf("%s", tmp);
		if (strcmp(tmp, "push") == 0) {
			int x;
			scanf("%d", &x);
			st.push(x);
		}
		else if (strcmp(tmp,"pop") == 0) {
			if (st.size() == 0) {
				answer.push_back(-1);
			}
			else {
				answer.push_back(st.top());
				st.pop();
			}
		}
		else if (strcmp(tmp, "size") == 0) {
			answer.push_back(st.size());
		}
		else if (strcmp(tmp, "empty") == 0) {
			if (st.empty()) {
				answer.push_back(1);
			}
			else {
				answer.push_back(0);
			}
		}
		else if (strcmp(tmp, "top") == 0) {
			if (st.empty()) {
				answer.push_back(-1);
			}
			else {
				answer.push_back(st.top());
			}
		}
	}

	std::vector<int>::iterator iter;
	for (iter = answer.begin(); iter != answer.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	return 0;
}
