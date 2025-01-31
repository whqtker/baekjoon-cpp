#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nodes[1000001]; // ��� ���� ����
int dp[1000001][2]; // dp[i][j]: i�� ° ��尡 �� ����Ͱ� �ƴ� ��(j == 0) �Ǵ� �� ������� ��(j == 1) �ּ� �� �����

void dfs(int node, int parent) {
	dp[node][0] = 0;
	dp[node][1] = 1;

	for (int i = 0; i < nodes[node].size(); i++) {
		int child = nodes[node][i];

		if (child == parent)
			continue;

		dfs(child, node);

		dp[node][0] += dp[child][1]; // node�� �� ����Ͱ� �ƴ� ��� �ڽ��� ������ �� ����Ϳ��� ��.
		dp[node][1] += min(dp[child][0], dp[child][1]); // node�� �� ������� ��� �ڽ��� �� ������� ���� �ְ� �ƴ� ���� ����
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		nodes[x].push_back(y);
		nodes[y].push_back(x);
	}

	dfs(1, -1);
	cout << min(dp[1][0], dp[1][1]);
}