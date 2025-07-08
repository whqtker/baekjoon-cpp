#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char arr[51][51];
int visited[51][51];
vector<pair<int, int>> dist[252]; // i -> j ������ �ִ� �Ÿ� (i, j: nodes ������ �ε���)
int n, m;
int mst[252];

bool outOfBound(int x, int y) {
	return x < 0 || y < 0 || x >= n || y >= n;
}

int main() {
	// 1. BFS�� ���� S �Ǵ� K �� �ִ� �Ÿ��� ���Ѵ�. -> �ִ� �Ÿ��� ���� �� ���� ������ �����ϴ� ��� -1
	// 2. S, K �� MST�� �ִ� �Ÿ��� ���� ���Ѵ�.

	cin >> n >> m;

	vector<pair<int, int>> nodes;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'S' || arr[i][j] == 'K') {
				nodes.push_back({ i,j });
			}
		}
	}

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<pair<int, int>> q;

	for (int i = 0; i < nodes.size(); i++) {
		// �� ��忡 ���Ͽ� BFS ����
		memset(visited, -1, sizeof(visited));
		int x = nodes[i].first;
		int y = nodes[i].second;
		q.push({ x,y });
		visited[x][y] = 0;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (!outOfBound(nx, ny) && arr[nx][ny] != '1' && visited[nx][ny] == -1) {
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}

		// ��� �� �ִ� �Ÿ� �ʱ�ȭ
		for (int j = 0; j < nodes.size(); j++) {
			if (i != j) {
				int x = nodes[j].first;
				int y = nodes[j].second;

				if (visited[x][y] != -1)
					dist[i].push_back({ j,visited[x][y] });
			}
		}
	}

	int total_dist = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	mst[0] = 1;
	int node_cnt = 1; // ���� mst�� �����ϴ� ����� ��
	for (int i = 0; i < dist[0].size(); i++) {
		pq.push({ dist[0][i].second,dist[0][i].first });
	}

	while (!pq.empty()) {
		int d = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (mst[node]) continue;

		total_dist += d;
		node_cnt++;
		mst[node] = 1;

		for (int i = 0; i < dist[node].size(); i++) {
			int nnode = dist[node][i].first;
			int nd = dist[node][i].second;

			if (!mst[nnode]) {
				pq.push({ nd,nnode });
			}
		}
	}

	// ������ �� �ִ� ��ġ�� m + 1��
	if (m + 1 != node_cnt)
		cout << -1;
	else
		cout << total_dist;
}