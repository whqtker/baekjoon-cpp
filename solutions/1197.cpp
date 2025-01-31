//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<pair<int, pair<int, int>>> vec;
//int v, e;
//int parents[10001];
//
//int Find(int x) {
//	if (parents[x] == x)
//		return x;
//	else
//		return parents[x] = Find(parents[x]);
//}
//
//void Union(int x, int y) {
//	int px = Find(x);
//	int py = Find(y);
//	parents[px] = py;	
//}
//
//int main() {
//	// ũ�罺Į �˰��� ���
//	cin >> v >> e;
//
//	for (int i = 0;i < e;i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		vec.push_back({ c, { a,b } });
//	}
//
//	for (int i = 1;i <= v;i++) {
//		parents[i] = i;
//	}
//
//	// ����ġ�� �������� ����
//	sort(vec.begin(), vec.end());
//
//	int ans = 0;
//	int cnt = 0;
//	for (int i = 0;i < vec.size();i++) {
//		int w = vec[i].first;
//		int cur = vec[i].second.first;
//		int nxt = vec[i].second.second;
//
//		// ����Ŭ�� �����ϴ��� Ȯ��
//		if (Find(cur) == Find(nxt))
//			continue;
//
//		Union(cur, nxt);
//		ans += w;
//		cnt++;
//
//		// ���� ��� ���� ������ ����Ǿ��ٸ� break
//		if (cnt == vec.size() - 1)
//			break;
//	}
//
//	cout << ans;
//}

// ���� �˰���
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int MST[10001];
vector<pair<int, int>> nodes[10001]; // {��� ��ȣ, ����ġ}

int main() {
	int v, e;
	cin >> v >> e;

	for (int i = 0;i < e;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({ b,c });
		nodes[b].push_back({ a,c });
	}

	int start = 1;
	int cnt = 0;
	int ans = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	MST[start] = 1;
	for (int i = 0;i < nodes[start].size();i++) {
		int node = nodes[start][i].first;
		int w = nodes[start][i].second;
		pq.push({ w,node });
	}

	while (cnt < v - 1) {
		int weight, cur;
		tie(weight, cur) = pq.top();
		pq.pop();

		if (MST[cur])
			continue;

		MST[cur] = 1;
		ans += weight;
		cnt++;

		for (int i = 0;i < nodes[cur].size();i++) {
			int nw = nodes[cur][i].second;
			int nxt = nodes[cur][i].first;

			if (!MST[nxt])
				pq.push({ nw,nxt });
		}
	}

	cout << ans;
}