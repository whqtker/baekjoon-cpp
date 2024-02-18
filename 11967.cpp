#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<vector<pair<int, int>>>> v(n, vector <vector<pair<int, int>>>(n)); // 스위치 연결 관계
	for (int i = 0;i < m;i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a - 1][b - 1].push_back({ c - 1,d - 1 });
	}

	vector<vector<int>> light(n, vector<int>(n)); // 켜진 전등
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	light[0][0] = 1;

	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 불 켜기
		bool flag = false;
		for (int i = 0;i < v[x][y].size();i++) {
			int a = v[x][y][i].first;
			int b = v[x][y][i].second;

			if (!light[a][b]) {
				light[a][b] = 1;
				cnt++;
				flag = true;
			}
		}

		if (flag) {
			// 움직이기
			queue<pair<int, int>> move;
			vector<vector<int>> visited(n, vector<int>(n));

			move.push({ x,y });
			visited[x][y] = 1;

			while (!move.empty()) {
				int a = move.front().first;
				int b = move.front().second;
				move.pop();

				if (a - 1 >= 0 && !visited[a - 1][b] && light[a - 1][b]) {
					q.push({ a - 1,b });
					move.push({ a - 1,b });
					visited[a - 1][b] = 1;
				}
				if (a + 1 < n && !visited[a + 1][b] && light[a + 1][b]) {
					q.push({ a + 1,b });
					move.push({ a + 1,b });
					visited[a + 1][b] = 1;
				}
				if (b - 1 >= 0 && !visited[a][b - 1] && light[a][b - 1]) {
					q.push({ a,b - 1 });
					move.push({ a ,b - 1 });
					visited[a][b - 1] = 1;
				}
				if (b + 1 < n && !visited[a][b + 1] && light[a][b + 1]) {
					q.push({ a,b + 1 });
					move.push({ a ,b + 1 });
					visited[a][b + 1] = 1;
				}
			}
		}
	}

	cout << cnt;
}