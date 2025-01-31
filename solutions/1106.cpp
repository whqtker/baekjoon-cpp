#include <iostream>
#include <algorithm>

using namespace std;

int cost[21]; // ȫ�� ���
int customer[21]; // ��ġ �� ��
int dp[100001]; // dp[i]: i ������� ���� �� �ִ� �ִ� �� ��

int main() {
	int c, n; // �ּ� �� ��ġ ��, ������ ��
	cin >> c >> n;

	for (int i = 0;i < n;i++) {
		cin >> cost[i] >> customer[i];
	}

	for (int i = 0;i < n;i++) {
		for (int j = 1;j <= 100001;j++) {
			if (j - cost[i] >= 0) {
				dp[j] = max(dp[j], dp[j - cost[i]] + customer[i]);
			}
		}
	}

	for (int i = 1;i <= 100001;i++) {
		if (dp[i] >= c) {
			cout << i;
			break;
		}
	}
}