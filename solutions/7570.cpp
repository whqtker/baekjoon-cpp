#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// m: v���� 1�� �����ϴ� �κм����� �ִ� ����
	// ���� n - m �̴�.
	unordered_map<int, int>dp; // dp[i]: i�� ������ 1�� �����ϴ� �κм����� �ִ� ����
	int m = -1;
	for (int i = 0; i < n; i++) {
		int cur = v[i];

		// cur - 1�� ���� ������ �ִٸ�
		if (dp.count(cur - 1))
			dp[cur] = dp[cur - 1] + 1;
		else
			dp[cur] = 1;

		m = max(dp[cur], m);
	}

	cout << n - m;
}