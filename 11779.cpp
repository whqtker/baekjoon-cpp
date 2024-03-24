#include <iostream>
#include <queue>
#include <vector>

#define INF 10000000000

using namespace std;

vector<pair<long long, long long>> nodes[1001];
long long dist[1001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		nodes[s].push_back({ e,c });
		nodes[e].push_back({ s,c });
	}

	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++) {
		if (i == start)
			dist[i] = 0;
		else
			dist[i] = INF;
	}

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	pq.push({ 0,start });
}