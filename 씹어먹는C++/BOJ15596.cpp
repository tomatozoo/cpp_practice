#include <iostream>
#include <vector>

long long sum(std::vector<int>& a) {
	long long result = 0;
	for (int i = 0; i < a.size(); i++) {
		result += a[i];
	}
	return result;
}
// a: ���� ���ؾ� �ϴ� ���� n���� ����Ǿ� �ִ� �迭(0 �� a[i] �� 1, 000, 000, 1 �� n �� 3, 000, 000)
// ���ϰ� : a�� ���ԵǾ� �ִ� ���� n���� ��