#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int dp[10001][3]; // dp[i][j]: i�� ° ���� ������ �� �ִ� �������� ��, ���� �����Ͽ� j�� ���� ����

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}

	int tmp = 0; // 1�� ° �ܺ��� i - 2�� ° �ܱ����� dp �ִ�
	int m = 0; // ���� �ִ�
	for (int i = 1;i <= n;i++) {
		if (i - 2 > 0)
			tmp = max({ tmp, dp[i - 2][1], dp[i - 2][2] });

		dp[i][1] = tmp + arr[i];
		if (i - 1 > 0)
			dp[i][2] = dp[i - 1][1] + arr[i];

		m = max({ m, dp[i][1], dp[i][2] });
	}

	cout << m;
}