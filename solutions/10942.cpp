#include <iostream>

using namespace std;

int arr[2001];
int dp[2001][2001]; // dp[i][j]: i���� j������ ���� �Ӹ�����̸� 1, �׷��� ������ 0

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}

	for (int i = 1;i <= n;i++) {
		// s�� e�� ���� ��� ������ �Ӹ�����̴�.
		dp[i][i] = 1;

		// s�� e�� 1 ���̳��� ��� �� ���� ������ �Ӹ�����̴�.
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;
	}

	// s�� e�� 2 �̻� ���̳��� ��� �� ���� ���� s - 1���� e + 1������ ���� �Ӹ�����̸� �Ӹ�����̴�.
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; i + j <= n; j++) {
			if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1] == 1)
				dp[j][i + j] = 1;
		}
	}

	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
}