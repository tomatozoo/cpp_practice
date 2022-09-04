#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>

int main15649() {
	int n, m;
	scanf("%d %d", &n, &m);

	std::vector<int> v;

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	int index = 0;

	do {
		if (n - m == 0) {
			for (int i = 0; i < m ; i++) {
				printf("%d ", v[i]);
			}
			printf("\n");
		}
		else {
			if (index == 0) {
				for (int i = 0; i < m; i++) {
					printf("%d ", v[i]);
				}
				printf("\n");
			}
			else {
				if ((n - m) <= index && index % (n - m) == 0) {
					for (int i = 0; i < m; i++) {
						printf("%d ", v[i]);
					}
					printf("\n");
				}
			}
		}

		index++;
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}
