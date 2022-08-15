#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>

int mai() {
	// ���� ����� 
	std::vector<int> answer;

	// ������ ���� n
	int n;
	scanf("%d", &n);

	std::priority_queue<int> pqueue;

	// n���� �ٿ��� ������ �����ϱ�
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
				// �迭���� ���� ���� ���� ����ϰ�, �� ���� �迭���� �����ϱ�
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