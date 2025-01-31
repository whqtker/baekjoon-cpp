#include <iostream>

using namespace std;

long long dp[101][10]; // dp[i][j]: ���̰� i�� ��ܼ��� ��, ������ ���� j

int main() {
	int n;
	cin >> n;

	for (int i = 1;i <= 9;i++) {
		dp[1][i] = 1;
	}

	for (int i = 2;i <= n;i++) {
		for (int j = 0;j <= 9;j++) {
			if (j - 1 >= 0 && dp[i - 1][j] != 0)
				dp[i][j - 1] += dp[i - 1][j] % 1000000000;
			if (j + 1 <= 9 && dp[i - 1][j] != 0)
				dp[i][j + 1] += dp[i - 1][j] % 1000000000;
		}
	}

	long long sum = 0;
	for (int i = 0;i <= 9;i++) {
		sum += dp[n][i];
		sum %= 1000000000;
	}

	cout << sum;
}