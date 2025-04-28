#include <iostream>
#include <vector>
#include <queue>

#define INF 10001

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> nodes[1001];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		nodes[a].push_back({ b,c });
		nodes[b].push_back({ a,c });
	}

	vector<int> cost(n + 1);
	for (int i = 2; i <= n; i++) {
		cost[i] = INF;
	}

	// ������ǻ�ͷκ��� �ٸ� ��ǻ�� �� �ּ� �ð��� ���Ѵ�.
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({ 0,1 });

	vector<int> parent(1001); // �ִ� ��θ� �������ϱ� ���� �迭

	while (!pq.empty()) {
		int node = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (cost[node] < weight)
			continue;

		for (int i = 0; i < nodes[node].size(); i++) {
			int nnode = nodes[node][i].first;
			int nweight = nodes[node][i].second;

			if (weight + nweight < cost[nnode]) {
				cost[nnode] = weight + nweight;
				parent[nnode] = node;
				pq.push({ cost[nnode],nnode });
			}
		}
	}

	// n���� ��带 ������ �׷����� �ּ� ������ ���� n - 1���̴� (spanning tree)
	cout << n - 1 << "\n";
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << " " << i << "\n";
	}
}