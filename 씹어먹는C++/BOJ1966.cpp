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
		// ������ ���� n
		// ��� ����(�켱���� ť���� ���° �ڸ�����) �ñ��� m
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

		// m�� ��� ������ m�� �켱���� ť �� ��° ���������� ���� �� �� �ִ�. 
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