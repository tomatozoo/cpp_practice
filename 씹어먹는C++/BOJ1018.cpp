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


	// �ٽ� ĥ�ؾ� �ϴ� �ּڰ� ���ϱ�
	int min = 64, tmp = 0, tmp_same = 0, tmp_diff = 0, same = 0, diff = 0;
	char std = '-';

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			// i, j���� i+7, j+7���� ���� ü������ ���� ���� ����Ѵ�
			tmp = 0; tmp_same = 0; tmp_diff = 0, same = 0, diff = 0;
			std = chess[i][j];
			for (int p = i; p < i + 8; p++) {
				for (int q = j; q < j + 8; q++) {
					// std�� ���ƾ� �ϴ� ���
					if (((p-i) % 2==1 && (q-j)%2==1)||((p - i) %2==0&& (q - j) %2==0)) {
						same += 1;
						if (std != chess[p][q]) {
							tmp_same += 1;
						}
					}
					// std�� �޶�� �ϴ� ���
					if (((p - i) % 2 == 0 && (q - j) % 2 == 1) || ((p - i) % 2 == 1 && (q - j) % 2 == 0)) {
						diff += 1;
						if (std == chess[p][q]) {
							tmp_diff += 1;
						}
					}
					// std�� �ٲ� ���� �ִ�. 
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