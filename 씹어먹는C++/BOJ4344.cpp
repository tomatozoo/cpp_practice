#include <iostream>

int main4344() {
	int c;
	std::cin >> c;
	double* mean = new double[c];
	for (int i = 0; i < c; i++) {
		mean[i] = 0;
	}

	int tmp_size;
	double tmp_sum, tmp_val, tmp_mean;
	for (int i = 0; i < c; i++) {
		std::cin >> tmp_size;
		tmp_sum = 0; tmp_mean = 0;

		double* tmp_case = new double[tmp_size];
		for (int j = 0; j < tmp_size; j++) {
			tmp_case[j] = 0;
		}
		for (int j = 0; j < tmp_size; j++) {
			std::cin >> tmp_val;
			tmp_sum += tmp_val;
			tmp_case[j] = tmp_val;
		}
		tmp_mean = tmp_sum / tmp_size;

		for (int j = 0; j < tmp_size; j++) {
			if (tmp_case[j] > tmp_mean) {
				mean[i] += 1;
			}
		}
		mean[i] = mean[i] / tmp_size * 100;

	}

	std::cout.precision(3);
	std::cout << std::fixed;
	for (int i = 0; i < c; i++) {
		std::cout << mean[i] << "%" << std::endl;
	}
	return 0;
}