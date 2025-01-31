#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001][5][5]; // dp[t][x][y]: t��°�� �޹��� x, �������� y�� ��ġ��

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	dp[0][0][0] = 1;
	int t = 0;
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0;i < 5;i++) {
			for (int j = 0;j < 5;j++) {
				if (dp[t][i][j] != 0) {
					// ���� 0�� �ִ� ���
					if (i == 0 && j != n) {
						if (dp[t + 1][n][j] != 0) {
							dp[t + 1][n][j] = min(dp[t + 1][n][j], dp[t][i][j] + 2);
						}
						else
							dp[t + 1][n][j] = dp[t][i][j] + 2;
					}
					if (j == 0 && i != n) {
						if (dp[t + 1][i][n] != 0) {
							dp[t + 1][i][n] = min(dp[t + 1][i][n], dp[t][i][j] + 2);
						}
						else
							dp[t + 1][i][n] = dp[t][i][j] + 2;
					}

					// �޹��� �̵�
					if (i == n) {
						if (dp[t + 1][i][j] != 0)
							dp[t + 1][i][j] = min(dp[t + 1][i][j], dp[t][i][j] + 1);
						else
							dp[t + 1][i][j] = dp[t][i][j] + 1;
					}

					int tmp;
					if (i != 0) {
						tmp = (i + 1) % 4 == 0 ? 4 : (i + 1) % 4;
						if (tmp != j&&tmp==n) {
							if (dp[t + 1][tmp][j] != 0)
								dp[t + 1][tmp][j] = min(dp[t + 1][tmp][j], dp[t][i][j] + 3);
							else
								dp[t + 1][tmp][j] = dp[t][i][j] + 3;
						}

						tmp = (i + 3) % 4 == 0 ? 4 : (i + 3) % 4;
						if (tmp != j && tmp == n) {
							if (dp[t + 1][tmp][j] != 0)
								dp[t + 1][tmp][j] = min(dp[t + 1][tmp][j], dp[t][i][j] + 3);
							else
								dp[t + 1][tmp][j] = dp[t][i][j] + 3;
						}

						tmp = (i + 2) % 4 == 0 ? 4 : (i + 2) % 4;
						if (tmp != j && tmp == n) {
							if (dp[t + 1][tmp][j] != 0)
								dp[t + 1][tmp][j] = min(dp[t + 1][tmp][j], dp[t][i][j] + 4);
							else
								dp[t + 1][tmp][j] = dp[t][i][j] + 4;
						}
					}

					// �������� �̵�
					if (j == n) {
						if (dp[t + 1][i][j] != 0)
							dp[t + 1][i][j] = min(dp[t + 1][i][j], dp[t][i][j] + 1);
						else
							dp[t + 1][i][j] = dp[t][i][j] + 1;
					}

					if (j != 0) {
						tmp = (j + 1) % 4 == 0 ? 4 : (j + 1) % 4;
						if (tmp != i && tmp == n) {
							if (dp[t + 1][i][tmp] != 0)
								dp[t + 1][i][tmp] = min(dp[t + 1][i][tmp], dp[t][i][j] + 3);
							else
								dp[t + 1][i][tmp] = dp[t][i][j] + 3;
						}

						tmp = (j + 3) % 4 == 0 ? 4 : (j + 3) % 4;
						if (tmp != i && tmp == n) {
							if (dp[t + 1][i][tmp] != 0)
								dp[t + 1][i][tmp] = min(dp[t + 1][i][tmp], dp[t][i][j] + 3);
							else
								dp[t + 1][i][tmp] = dp[t][i][j] + 3;
						}

						tmp = (j + 2) % 4 == 0 ? 4 : (j + 2) % 4;
						if (tmp != i && tmp == n) {
							if (dp[t + 1][i][tmp] != 0)
								dp[t + 1][i][tmp] = min(dp[t + 1][i][tmp], dp[t][i][j] + 4);
							else
								dp[t + 1][i][tmp] = dp[t][i][j] + 4;
						}
					}
				}
			}
		}

		t++;
	}

	int ans = 400001;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (dp[t][i][j] != 0)
				ans = min(ans, dp[t][i][j]);
		}
	}
	cout << ans - 1;
}