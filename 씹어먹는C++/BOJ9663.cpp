#include <iostream>
/*
int N;
int* block = new int[16];
int cnt = 0;

void back(int depth) {
	if (depth == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		bool flag = true;

		for (int j = 0; j < depth; j++) {
			if (block[j] == i || abs(depth - j) == abs(i - block[j])) {
				flag = false;
			}
		}
		if (flag) {
			block[depth] = i;
			back(depth + 1);
			block[depth] = 0;
		}
	} 
	return;
}

int main9663() {
	std::cin >> N;

	back(0);

	std::cout << cnt << std::endl;
	return 0;
}*/