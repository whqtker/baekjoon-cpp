#include <iostream>
#include <algorithm>

using namespace std;

int v[1000]; // ����Ȱ�� ������
int dp[2001][1000]; // dp[i][j]: i�ϱ����� �ִ� ������, ���� j�� ��

int main() {
	int n, m, a, d; // n: ���� �ϼ�, m: �ʿ��� ������, a: ���� ������, d: ���� �� ����� �ϴ� ��
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> a >> d;

	dp[0][0] = v[0];
	dp[d - 1][1] = a;

	int ans = 1001;
	for (int i = 1;i < n;i++) {
		for (int j = 0;j <= i;j++) {
			// ����Ȱ���� �ϴ� ���
			// ���� �ִ� �������� �������� �ʴ� ���
			if (dp[i - 1][j] == 0)
				continue;
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + v[i]);
			if (dp[i][j] >= m)
				ans = min(ans, j);

			// ������ �ϴ� ���, ���� �� ���� �� ���, ���� ���� dp �ʱ�ȭ X
			dp[i + d - 1][j + 1] = max(dp[i + d - 1][j + 1], dp[i - 1][j] + a);
			if (dp[i + d - 1][j + 1] >= m)
				ans = min(ans, j + 1);

		}
	}

	if (ans == 1001)
		cout << -1;
	else
		cout << ans;
}