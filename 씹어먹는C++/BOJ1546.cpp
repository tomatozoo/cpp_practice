#include <iostream>

int m1sain() {
	int N;
	std::cin >> N;
	
	double* exam = new double[N];
	double max = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> exam[i];
		if (exam[i] > max) {
			max = exam[i];
		}
	}

	double sum = 0;
	for (int i = 0; i < N; i++) {
		exam[i] = (exam[i] / max) * 100;
		sum += exam[i];
	}

	double n = N;
	double mean = sum / n;
	std::cout << mean << std::endl;


	return 0;
}