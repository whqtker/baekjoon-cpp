#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<vector<pair<int, int>>>> v(n, vector<vector<pair<int, int>>>(n));
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		v[a - 1][b - 1].push_back({ c - 1,d - 1 }); // ¿Œµ¶Ω∫ ∫∏¡§
	}

	queue<pair<int, int>> q;
	vector<vector<int>> light(n, vector<int>(n));

	light[0][0] = 1;
	q.push({ 0,0 });

	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		vector<vector<int>> visited(n, vector<int>(n));
		visited[x][y] = 1;

		for (int i = 0; i < v[x][y].size(); i++) {
			int a = v[x][y][i].first;
			int b = v[x][y][i].second;

			if (!light[a][b]) {
				cnt++;
				light[a][b] = 1;
			}
		}

		if (x - 1 >= 0 && !visited[x - 1][y] && light[x - 1][y]) {
			q.push({ x - 1,y });
			visited[x - 1][y] = 1;
		}
		if (x + 1 < n && !visited[x + 1][y] && light[x + 1][y]) {
			q.push({ x + 1,y });
			visited[x + 1][y] = 1;
		}
		if (y - 1 >= 0 && !visited[x][y - 1] && light[x][y - 1]) {
			q.push({ x ,y - 1 });
			visited[x][y - 1] = 1;
		}
		if (y + 1 < n && !visited[x][y + 1] && light[x][y + 1]) {
			q.push({ x ,y + 1 });
			visited[x][y + 1] = 1;
		}
	}

	cout << cnt;
}