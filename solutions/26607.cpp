#include <iostream>
#include <algorithm>

using namespace std;

int dp[81][81]; // dp[i][j]: i�� ° ��������� �ִ� ��(a), j�� ����
pair<int, int> arr[81];

int main() {
	int n, k, x;
	cin >> n >> k >> x;

	for (int i = 1;i <= n;i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= k;j++) {
			// i�� ° ��� �̱� vs. ���� �ʱ�
			dp[i][j] = max(dp[i - 1][j - 1] + arr[i].first, dp[i - 1][j]);
		}
	}

	// sum(a) + sum(b) = k * x, sum(a) * sum(b) = sum(a) * (k * x - sum(a))
	cout << dp[n][k] * (k * x - dp[n][k]);
}