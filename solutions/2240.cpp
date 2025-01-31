#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][31]; // dp[i][j]: i�� �� j�� �������� ���� �ڵ��� ��
int tree[1001];

int main() {
	int t, w;
	cin >> t >> w;
	for (int i = 1;i <= t;i++) {
		int x;
		cin >> x;
		tree[i] = x;
	}

	if (tree[1] == 1) {
		dp[1][0] = 1;
		dp[1][1] = 0;
	}
	else {
		dp[1][0] = 0;
		dp[1][1] = 1;
	}

	// dp[i][j]���� j % 2 == 0�̸� 1�� ����, j % 2 == 1�̸� 2�� ������ ��ġ�Ѵ�.
	for (int i = 1;i < t;i++) {
		int tmp = 0;
		for (int j = 0;j <= i;j++) {
			if (j + 1 <= w) {
				if ((j + 1) % 2 + 1 == tree[i + 1])
					tmp = dp[i][j] + 1;
				else
					tmp = dp[i][j];
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], tmp);
			}

			if (j <= w) {
				if (j % 2 + 1 == tree[i + 1])
					tmp = dp[i][j] + 1;
				else
					tmp = dp[i][j];
				dp[i + 1][j] = max(dp[i + 1][j], tmp);
			}
		}
	}

	int ans = 0;
	for (int i = 0;i <= w;i++) {
		ans = max(dp[t][i], ans);
	}
	cout << ans;
}