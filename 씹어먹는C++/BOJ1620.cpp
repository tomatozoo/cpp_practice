#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
 
int main1620() {
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);

	std::string name[100001];
	std::map<std::string, int> string_to_int;

	for (int i = 0; i < n; i++) {
		char* tmp = new char[21];
		scanf("%s", tmp);
		string_to_int[tmp] = i + 1;
		name[i + 1] = tmp;
	}

	for (int i = 0; i < m; i++) {
		char* tmp = new char[21];
		scanf("%s", tmp);

		// 숫자
		if (std::isdigit(tmp[0]) != 0) {
			int n = std::stoi(tmp);
			char* answer = strcpy(new char[name[n].length() + 1], name[n].c_str());
			printf("%s\n", answer);
		}
		// 문자
		else {

			printf("%d\n", string_to_int[tmp]);

		}
	}
	return 0;
}