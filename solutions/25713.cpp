#include <iostream>

#define INF 2001

using namespace std;

int dp[1001][1001]; // dp[i][j]: (i, j)�� �����ϱ���� �μ� ����ī�޶��� �ּ� ����
int psum_row[1001][1001]; // �� ���� ���� ��
int psum_col[1001][1001]; // �� ���� ���� ��
int n, m, k;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> k;

	// ������ ù ��° ��, ���� ���Ͽ� 2���� imos�� ���
	// �������� ��� ������
	for (int i = 0;i < k;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		// 1. ù ��° ��, ���� ���Ͽ� ������ ���
		psum_row[a][b]++;
		psum_row[a + 1][b]--;
		psum_row[a][d + 1]--;
		psum_row[a + 1][d + 1]++;

		psum_col[a][b]++;
		psum_col[a][b + 1]--;
		psum_col[c + 1][b]--;
		psum_col[c + 1][b + 1]++;
	}

	// 2. ������ ������
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			psum_row[i][j] += psum_row[i][j - 1];
			psum_col[i][j] += psum_col[i][j - 1];
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			psum_row[i][j] += psum_row[i - 1][j];
			psum_col[i][j] += psum_col[i - 1][j];
		}
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			dp[i][j] = INF;
		}
	}

	dp[1][1] = psum_row[1][1];
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (i > 1)
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + psum_row[i][j]);
			if (j > 1)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + psum_col[i][j]);
		}
	}

	cout << dp[n][m];
}
