#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][10101]; // dp[x][y]: x: x��°�� �� ó��, y: �� ��Ȱ��ȭ ���, dp[x][y]: �޸� Ȯ���� ������ ũ��(m���� Ŀ�� ��)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<int> a, c;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		c.push_back(x);
	}

	int ans = 10001;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= 10000;j++) {
			int tmp = dp[2][0];
			// ���� �� ��Ȱ��ȭ
			if (dp[i - 1][j] < m)
				dp[i][j + c[i - 1]] = max(dp[i][j + c[i - 1]], dp[i - 1][j] + a[i - 1]);

			// ���� �� pass
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);

			// ����� ������ Ȯ���� ���
			if (dp[i][j] >= m) {
				ans = min(ans, j);
			}
		}
	}

	cout << ans;
}