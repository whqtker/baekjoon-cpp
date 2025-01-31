#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n;
vector<pair<int, int>> v[10001];
int visited[10001];
int ans = 0;
int endNode = 0;

void dfs(int s,int len) {
	if (visited[s])
		return;

	visited[s] = 1;

	if (ans < len) {
		ans = len;
		endNode = s;
	}

	for (int i = 0;i < v[s].size();i++) {
		dfs(v[s][i].first, len + v[s][i].second);
	}
}

int main() {
	// ���� �ָ� �������ִ� ��带 ã�� ������ ����Ѵ�.
	cin >> n;

	for (int i = 0;i < n - 1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	// ���� �ָ� �ִ� ��� ã��
	dfs(1, 0);

	// ���� ����ϱ�
	ans = 0;
	memset(visited, 0, sizeof(visited));
	dfs(endNode, 0);
	cout << ans;
}