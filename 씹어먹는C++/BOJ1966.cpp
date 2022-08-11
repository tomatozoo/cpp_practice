#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

int ma_9in() {
	int testcase;
	std::cin >> testcase;
	std::vector<int> answer;


	for (int i = 0; i < testcase; i++) {
		// 문서의 개수 n
		// 출력 순서(우선순위 큐에서 몇번째 자리인지) 궁금한 m
		int n, m;
		std::cin >> n >> m;

		std::vector<int> v;
		std::queue<std::pair<int, int>> pqueue;
		int tmp;
		for (int j = 0; j < n; j++) {
			std::cin >> tmp;
			v.push_back(tmp);

			if (j == m) {
				pqueue.push(std::make_pair(tmp, 1));
			}
			else {
				pqueue.push(std::make_pair(tmp, 0));
			}
		}

		std::sort(v.begin(), v.end());

		// m의 출력 순서는 m이 우선순위 큐 몇 번째 원소인지에 따라 알 수 있다. 
		int tmp_ans = 0;
		while (true) {
			if (v.back() == pqueue.front().first) {
				if (pqueue.front().second == 1) {
					tmp_ans++;
					break;
				}
				else {
					v.pop_back();
					pqueue.pop();
					tmp_ans++;
				}
			}
			else {
				pqueue.push(std::make_pair(pqueue.front().first, pqueue.front().second));
				pqueue.pop();
			}
		}
		answer.push_back(tmp_ans);
	}

	std::vector<int>::iterator iter;
	for (iter = answer.begin(); iter != answer.end(); iter++) {
		std::cout << *iter << std::endl;
	}
	return 0;
}