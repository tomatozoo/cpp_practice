#include <bits/stdc++.h>
using namespace std;
int n, a[2001], d[2001][2001];

int dp(int l, int r, int k) {
	if (l > r) {
		return 0;
	}
	int& ret = d[l][r];
	if (ret != -1) {
		return ret;
	}
	return ret = max(dp(l, r - 1, k + 1)+a[r]*k, dp(l+1, r, k+1)+a[l]*k);
}

int main() {
	memset(d, -1, sizeof(d));

	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];


	cout << dp(0,n-1,1);
	return 0;
}
 