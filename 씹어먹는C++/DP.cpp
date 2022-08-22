#include <iostream>

int fib(int n) {
	if (n > 1) {
		int* fibo = new int[n];
		fibo[0] = 0;
		fibo[1] = 1;

		for (int i = 2; i < n; i++) {
			fibo[i] = fibo[i - 1] + fibo[i - 2];
		}
		return fibo[n - 1];
	}
}
int maindp() {

	std::cout << fib(2) << std::endl;
	return 0;
} 