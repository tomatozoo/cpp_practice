#include <iostream>

int n, m;
int arr[9] = { 0, };
bool visit[9] = { 0, };

void back(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			std::cout << arr[i] << ' ';
		}
		std::cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[depth] = i;
			back(depth + 1);
			visit[i] = false;
		}
	}
}

int main15649() {
	std::cin >> n >> m;

	back(0);
	return 0; 
}
