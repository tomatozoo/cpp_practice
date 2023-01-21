#include <iostream> 
#include <string> 
 
int m1018in() {
	// input
	int n, m;
	std::cin >> n >> m;

	char** chess = new char* [n];
	for (int i = 0; i < n; i++) {
		chess[i] = new char[m];
	}

	char getline;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> chess[i][j];
		}
	}


	// 다시 칠해야 하는 최솟값 구하기
	int min = 64, tmp = 0, tmp_same = 0, tmp_diff = 0, same = 0, diff = 0;
	char std = '-';

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			// i, j에서 i+7, j+7까지 가는 체스판의 값을 각각 계산한다
			tmp = 0; tmp_same = 0; tmp_diff = 0, same = 0, diff = 0;
			std = chess[i][j];
			for (int p = i; p < i + 8; p++) {
				for (int q = j; q < j + 8; q++) {
					// std와 같아야 하는 경우
					if (((p-i) % 2==1 && (q-j)%2==1)||((p - i) %2==0&& (q - j) %2==0)) {
						same += 1;
						if (std != chess[p][q]) {
							tmp_same += 1;
						}
					}
					// std와 달라야 하는 경우
					if (((p - i) % 2 == 0 && (q - j) % 2 == 1) || ((p - i) % 2 == 1 && (q - j) % 2 == 0)) {
						diff += 1;
						if (std == chess[p][q]) {
							tmp_diff += 1;
						}
					}
					// std를 바꿀 수도 있다. 
				}
			}
			if ((tmp_same+tmp_diff) < min) {
				min = (tmp_same + tmp_diff);
			}
			if ((same - tmp_same + diff - tmp_diff) < min) {
				min = (same - tmp_same + diff - tmp_diff);
			}
		}
	}

	std::cout << min << std::endl;
	return 0;
}
