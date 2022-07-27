#include <iostream>
#include <string>

int main() {
	int n, m;
	std::cin >> n >> m;

	int** chess = new int* [n];
	for (int i = 0; i < n; i++) {
		chess[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> chess[i][j];
		}
		std::cin.getline();
	}

	int min = 64, tmp = 0;
	char std = '-';

	for (int j=0;j<n-8;j++){
		for (int k = 0; k < m - 8; k++) {
			// °¢ ÄÉÀÌ½º¿¡¼­ tmpÀ» ±¸ÇÏ°í
			for (int x = j; x < j + 8; x++) {
				for (int y = k; y < k + 8; y++) {
					if (((x % 2 == 0) && (y % 2 == 0)) || ((j % 2 == 1) && (k % 2 == 1))) {
						if (chess[x][y] != std) {
							tmp += 1;
						}
					}
					// Â¦ È¦
					else if (((x % 2 == 0) && (y % 2 == 1)) || ((j % 2 == 1) && (k % 2 == 0))) {
						if (chess[x][y] == std) {
							tmp += 1;
						}
					}
				}
			}
			// ÃÖ¼Ú°ª ¾÷µ¥ÀÌÆ®
			if (min > tmp) {
				min = tmp;
			}
		}
	}

	std::cout << min << std::endl;
	return 0;
}
/*std = chess[0][0];
			// Â¦ Â¦
			if (((x % 2 == 0) && (y % 2 == 0)) || ((j % 2 == 1) && (k % 2 == 1))) {
				if (chess[i][j] != std) {
					tmp += 1;
				}
			}
			// Â¦ È¦
			else if (((x % 2 == 0) && (y % 2 == 1))||((j % 2 == 1) && (k % 2 == 0))) {
				if (chess[i][j] == std) {
					tmp += 1;
				}
			}*/