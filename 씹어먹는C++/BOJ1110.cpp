#include <iostream>

int mai() {
	int n;
	std::cin >> n;

	int** test_case = new int*[n];
	int tmp_size = 0;

	for (int i = 0; i < n; i++) {
		std::cin >> tmp_size;
		test_case[i] = new int[tmp_size+1];
		test_case[i][0] = tmp_size;
		for (int j = 1; j < tmp_size; j++) {
			std::cin >> test_case[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		tmp_size = test_case[i][0];
		for (int j = 1; j < tmp_size; j++) {
			std::cout << test_case[i][j] << " ";
		}
		std::cout << std::endl;
	}
	/*
	double sum = 0, mean = 0;
	int upper = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		mean = 0;
		upper = 0;
		tmp_size = test_case[i][0];
		for (int j = 1; j < tmp_size; j++) {
			std::cout << test_case[i][j];
			sum += test_case[i][j];
		}
		mean = sum / tmp_size;
		for (int j = 1; j < tmp_size; j++) {
			if (test_case[i][j] > mean) {
				upper += 1;
			}
		}
		std::cout << upper / tmp_size * 100 << "%" << std::endl;
	}
	*/

	return 0;
}