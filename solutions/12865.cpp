#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][100001]; // dp[i][k]: i�� ° ������ ����� �뷮 k�� �賶�� �ִ� ��ġ
int value[101];
int weight[101];

int main() {
	int n, k; // n: ������ ��, k: �賶 �뷮
	cin >> n >> k;

	for (int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		weight[i + 1] = a;
		value[i + 1] = b;
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= k;j++) {
			if (weight[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], value[i] + dp[i - 1][j - weight[i]]);
		}
	}

	cout << dp[n][k];
}