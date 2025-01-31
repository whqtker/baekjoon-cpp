#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool outOfBound(int row, int col, int n, int m) {
	// ���� ���� �����ϸ� true ����
	if (row < 0 || row >= m || col < 0 || col >= n) return true;
	return false;
}

void bfs(vector<vector<int>> v, vector<int> x, vector<int> y, int n, int m) {
	vector <vector<int>> visited(m, vector<int>(n, -1));
	queue<pair<int, int>> q;

	for (int i = 0;i < x.size();i++) {
		q.push({ x[i],y[i] });
		visited[x[i]][y[i]] = 0;
	}

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		// ������������ �湮 ������ ���� Ž��
		if (!outOfBound(row, col + 1, n, m) && v[row][col + 1] == 0 && visited[row][col + 1] == -1) {
			q.push({ row,col + 1 });
			v[row][col + 1] = 1;
			visited[row][col + 1] = visited[row][col] + 1;
		}
		if (!outOfBound(row, col - 1, n, m) && v[row][col - 1] == 0 && visited[row][col - 1] == -1) {
			q.push({ row,col - 1 });
			v[row][col - 1] = 1;
			visited[row][col - 1] = visited[row][col] + 1;
		}
		if (!outOfBound(row + 1, col, n, m) && v[row + 1][col] == 0 && visited[row + 1][col] == -1) {
			q.push({ row + 1,col });
			v[row + 1][col] = 1;
			visited[row + 1][col] = visited[row][col] + 1;
		}
		if (!outOfBound(row - 1, col, n, m) && v[row - 1][col] == 0 && visited[row - 1][col] == -1) {
			q.push({ row - 1,col });
			v[row - 1][col] = 1;
			visited[row - 1][col] = visited[row][col] + 1;
		}

		q.pop();
	}

	bool flag = false;
	for (int i = 0;i < m;i++) {
		if (find(v[i].begin(), v[i].end(), 0) != v[i].end()) {
			cout << -1;
			flag = true;
			break;
		}
	}

	if (flag == false) {
		int max_element = visited[0][0];
		for (int i = 0; i < visited.size(); i++) {
			for (int j = 0; j < visited[i].size(); j++) {
				if (visited[i][j] > max_element) {
					max_element = visited[i][j];
				}
			}
		}
		cout << max_element;
	}
}

int main() {
	int n, m;
	cin >> n >> m; // n: ����, m: ����

	vector<vector<int>> v(m); // �丶�䰡 ����ִ� ����
	vector<int> x; // ���� �丶���� x��ǥ
	vector<int> y; // ���� �丶���� y��ǥ
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			int a;
			cin >> a;
			v[i].push_back(a);

			if (a == 1) {
				x.push_back(i);
				y.push_back(j);
			}
		}
	}

	bfs(v, x, y, n, m);
}