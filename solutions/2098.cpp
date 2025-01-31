#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 16000001

using namespace std;
int n;
int w[16][16];
int dp[16][1 << 16]; // �湮 ���θ� ��Ʈ����ŷ�� ���� ����

// n = 4, visited == 0010 �̸� �� ��° ������ �湮, visited == 1111�̸� ��� ���� �湮
int dfs(int cur, int visited) {
	// ��� ���� �湮
	if (visited == (1 << n) - 1) {
		// �̵��� �� ���� ���
		if (w[cur][0] == 0)
			return INF;
		return w[cur][0];
	}

	// ���� ������ �湮�� ���
	if (dp[cur][visited] != -1)
		return dp[cur][visited];

	// ���� ���� �ʱ�ȭ
	dp[cur][visited] = INF;

	for (int i = 0;i < n;i++) {
		// ������� �ʾҴٸ� pass
		if (w[cur][i] == 0)
			continue;

		// �̹� �湮�ߴٸ� pass
		if ((visited & (1 << i)) == (1 << i))
			continue;

		dp[cur][visited] = min(dp[cur][visited], w[cur][i] + dfs(i, visited | 1 << i));
	}

	return dp[cur][visited];
}

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> w[i][j];
		}
	}

	// -1�� �ʱ�ȭ(�湮 ���ο� ������� ���� ���� ����)
	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1);
}