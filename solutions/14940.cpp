#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool outOfBound(int row, int col, int n, int m) {
	// ���� ���� �����ϸ� true ����
	if (row < 0 || row >= n || col < 0 || col >= m) return true;
	return false;
}

void bfs(vector<vector<int>> v, int row, int col, int n, int m) {
	vector < vector<int>> visited(n, vector<int>(m, -1));
	queue<pair<int,int>> q;
	q.push({ row,col });
	visited[row][col] = 0;

	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		// ������������ �湮 ������ ���� Ž��
		if (!outOfBound(row, col + 1, n, m) && v[row][col + 1] != 0 && visited[row][col + 1] == -1) {
			q.push({ row,col + 1 });
			visited[row][col + 1] = visited[row][col] + 1;
		}
		if (!outOfBound(row, col - 1, n, m) && v[row][col - 1] != 0 && visited[row][col - 1] == -1) {
			q.push({ row,col - 1 });
			visited[row][col - 1] = visited[row][col] + 1;
		}
		if (!outOfBound(row + 1, col, n, m) && v[row + 1][col] != 0 && visited[row + 1][col] == -1) {
			q.push({ row + 1,col });
			visited[row + 1][col] = visited[row][col] + 1;
		}
		if (!outOfBound(row - 1, col, n, m) && v[row - 1][col] != 0 && visited[row - 1][col] == -1) {
			q.push({ row - 1,col });
			visited[row - 1][col] = visited[row][col] + 1;
		}

		q.pop();
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (v[i][j] == 0)visited[i][j] = 0;
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	int n, m;
	cin >> n >> m; // n: ���� ����, m: ���� ����

	vector<vector<int>> v(n);
	int row, col; // ��ǥ������ ��� ��
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			int x;
			cin >> x;
			v[i].push_back(x);

			if (x == 2) {
				col = j;
				row = i;
			}
		}
	}

	bfs(v, row, col, n, m);
}