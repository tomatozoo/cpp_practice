#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v;
	std::vector<int> dp(301);

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		v.push_back(tmp);
	}

	dp[0] = v[0];
	dp[1] = v[0] + v[1];
	dp[2] = std::max(v[0], v[1])+v[2];
	
	for (int i = 3; i < n; i++) {
		dp[i] = std::max(dp[i - 3] + v[i - 1], dp[i - 2]) + v[i];
	}
	std::cout << dp[n-1] << std::endl;
	return 0;
} 