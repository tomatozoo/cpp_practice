#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>

int mai() {
	// 정답 저장소 
	std::vector<int> answer;

	// 연산의 개수 n
	int n;
	scanf("%d", &n);

	std::priority_queue<int> pqueue;

	// n개의 줄에서 연산을 수행하기
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x > 0) {
			pqueue.push(-x);
		}
		else if (x == 0) {
			if (pqueue.empty()) {
				answer.push_back(0);
			}
			else {
				// 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거하기
				answer.push_back(-pqueue.top());
				pqueue.pop();
			}
		}
	}

	std::vector<int>::iterator iter;
	for (iter = answer.begin(); iter != answer.end(); iter++) {
		printf("%d\n", *iter);
	}
	return 0;
}