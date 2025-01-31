#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int m, int n, vector<vector<int>> v, vector<vector<int>> visited, vector<pair<int, int>> coor) {
	queue<pair<int, int>> q;
	int cnt = 0;

	for (int i = 0; i < coor.size(); i++) {
		if (visited[coor[i].first][coor[i].second] == 0) {
			q.push(coor[i]);

			while (!q.empty()) {
				// q.front()�� �����̰� �湮�� �� �ߴٸ� �������� ��ǥ�� ť�� �ִ´�.
				if (v[q.front().first][q.front().second] == 1 && visited[q.front().first][q.front().second] == 0) {
					visited[q.front().first][q.front().second] = 1;
					if (q.front().first != 0)
						q.push(make_pair(q.front().first - 1, q.front().second));
					if (q.front().second != 0)
						q.push(make_pair(q.front().first, q.front().second - 1));
					if (q.front().first != m - 1)
						q.push(make_pair(q.front().first + 1, q.front().second));
					if (q.front().second != n - 1)
						q.push(make_pair(q.front().first, q.front().second + 1));
					q.pop();
				}
				// �湮�� �����̰ų� ���߰� �ƴ϶��
				else {
					q.pop();
				}
			}
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n, k; // m: ���߹��� ���� ����, n: ���߹��� ���� ����, k: ������ ����
		cin >> m >> n >> k;

		vector<vector<int>> v(m, vector<int>(n, 0)); // ���߹�
		vector<pair<int, int>> coor; // ���߰� �ִ� ��ǥ
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y; // ������ ��ǥ, x�� ° ��, y�� ° ��
			v[x][y] = 1;
			coor.push_back(make_pair(x, y));
		}

		vector<vector<int>> visited(m, vector<int>(n, 0)); // �湮�� �� �ߴٸ� 0, �ߴٸ� 1
		cout << bfs(m, n, v, visited, coor) << "\n";
	}

}