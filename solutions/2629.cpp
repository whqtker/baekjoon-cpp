#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int weight[30]; // ���� ����
int dp[30][40001]; // dp[i][j]: i��° ������ �������� �� ������ �ִ� ���Դ� j

int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> weight[i];
		dp[i][weight[i]] = 1;
	}


	for (int i = 1;i < n;i++) {
		for (int j = 1;j <= 40000;j++) {
			// ���� �߸� ���� �� �ִٸ�
			if (weight[i] <= j) {
				// ���� �߸� ���Ƽ� j�� ���� �� �ִٸ�
				if (dp[i - 1][j - weight[i]]) {
					dp[i][j] = 1;
				}
			}

			// j ���԰� ������ ��������ٸ�
			if (dp[i - 1][j]) {
				dp[i][j] = 1;
				dp[i][abs(j - weight[i])] = 1; // ���� �ʿ� �߸� ���� ���
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int x;
		cin >> x;

		if (dp[n - 1][x])
			cout << "Y ";
		else
			cout << "N ";
	}
}