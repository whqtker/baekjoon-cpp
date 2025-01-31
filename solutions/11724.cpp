#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> v, int n) {
	queue<int> q;
	vector<int> visited(n + 1, 0);
	int cnt = 0; // ���� ����� ��

	while (1) {
		int start;
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (visited[v[i][j]] == 0) {
					start = v[i][j];
					flag = true;
					break;
				}
			}
			if (flag == true) break;
		}

		// ��� ������ �� ������
		if (flag == false) {
			// ������ ���� ������ ���� ��ҿ� ���Խ��Ѿ� ��.
			for (int i = 1; i <= n; i++) {
				if (visited[i] == 0)
					cnt++;
			}
			break;
		}

		q.push(start);
		visited[start] = 1;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			for (int i = 0; i < v[f].size(); i++) {
				int e = v[f][i];
				if (visited[e] == 0) {
					q.push(e);
					visited[e] = 1;
				}
			}
		}
		cnt++;
	}
	cout << cnt;
}

int main() {
	int n, m; // n: ���� ����, m: ���� ����
	cin >> n >> m;

	vector<vector<int>> v(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(v, n);
}