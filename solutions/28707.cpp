#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v; // �ʱ� �迭
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	string init = string(v.begin(), v.end());

	vector<int> target = v; // ��ǥ �迭(�񳻸�����)
	sort(target.begin(), target.end());
	string tar = string(target.begin(), target.end());

	int m;
	cin >> m;
	vector<tuple<int, int, int>> nodes; // ��� ���� ����, { ����, ��, ����ġ }
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		nodes.push_back({ a - 1,b - 1,w });
	}

	unordered_map<string, int> visited;
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

	pq.push({ 0, init });
	visited[string(v.begin(), v.end())] = 0;

	int ans = INT_MAX;
	while (!pq.empty()) {
		int cur_w = pq.top().first;
		string cur_s = string(pq.top().second.begin(), pq.top().second.end());
		pq.pop();

		if (cur_s == tar)
			ans = min(ans, cur_w);

		for (int i = 0; i < m; i++) {
			int s = get<0>(nodes[i]);
			int e = get<1>(nodes[i]);
			int w = get<2>(nodes[i]);

			string nxt_s = cur_s;
			swap(nxt_s[s], nxt_s[e]);
			int nxt_w = cur_w + w;

			// ���� �迭�� �湮���� �ʾҴ��� ���� ����ġ�� ����� ������ ���� ���(�� ������ ���)
			if (visited.find(nxt_s) == visited.end() || visited[nxt_s] > nxt_w) {
				visited[nxt_s] = nxt_w;
				pq.push({ nxt_w,nxt_s });
			}
		}
	}

	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;
}