#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <tuple>

#define INF 1e9

using namespace std;

int s, g, h; // �����, g - h ������ �ݵ�� ����
vector<int> cost(2001);
vector<pair<int, int>> nodes[2001]; // nodes[x] = {y, w}: x -> y ������ ����ġ�� w

void init(int n) {
	for (int i = 0; i <= n; i++) {
		nodes[i].clear();
	}
}

void dijkstra(int n) {
	for (int i = 1; i <= n; i++) {
		cost[i] = INF;
	}
	cost[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int w = pq.top().first;
		int x = pq.top().second;

		pq.pop();

		if (cost[x] < w)
			continue;

		for (int i = 0; i < nodes[x].size(); i++) {
			int y = nodes[x][i].first;
			int nw = nodes[x][i].second;

			if (w + nw < cost[y]) {
				cost[y] = w + nw;
				pq.push({ cost[y],y });
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int n, m, t; // ������, ����, ������ �ĺ�
		cin >> n >> m >> t;

		cin >> s >> g >> h;

		init(n);

		for (int i = 0; i < m; i++) {
			int a, b, d; // a - b ������ ����ġ�� d / �����
			cin >> a >> b >> d;

			// �ʼ� ��δ� ����ġ�� Ȧ���� ����
			if ((a == g && b == h) || (a == h && b == g)) {
				nodes[a].push_back({ b,d * 2 - 1 });
				nodes[b].push_back({ a,d * 2 - 1 });
			}

			// �ʼ� ��ΰ� �ƴ϶�� ����ġ�� ¦���� ����
			nodes[a].push_back({ b,d * 2 });
			nodes[b].push_back({ a,d * 2 });
		}

		set<int> candidate;
		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			candidate.insert(x);
		}

		// s -> candidate[i]�� �ִܰŸ��� �̵��� ��, g - h ������ ������ ��, �׷��� ������ �� X
		dijkstra(n);

		for (auto dest : candidate) {
			// ���� �ּ� ����� Ȧ���� �ʼ� ��θ� ���� ����.
			if (cost[dest] % 2)
				cout << dest << " ";
		}
		cout << "\n";
	}
}