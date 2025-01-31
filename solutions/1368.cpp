#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> v;
int parents[301];

int Find(int x) {
	if (parents[x] == x)
		return x;
	else
		return parents[x] = Find(parents[x]);
}

void Union(int x, int y) {
	int px = parents[x];
	int py = parents[y];

	parents[px] = py;
}

int main() {
	int n;
	cin >> n;

	// �� �칰�� �Ĵ� ���� 0�� ���κ��� �´ٰ� �����Ѵ�.
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back({ x,{0,i} });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;

			if (i == j) continue;
			v.push_back({ x,{i,j} });
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i <= n; i++)
		parents[i] = i;

	int ans = 0; // �ּ� ����ġ
	for (int i = 0; i < v.size(); i++) {
		int w = v[i].first;
		int cur = v[i].second.first;
		int nxt = v[i].second.second;

		// cur�� nxt�� �θ� ���ٸ� ����Ŭ�� �����ϰ� ��.
		if (Find(cur) == Find(nxt)) continue;

		Union(cur, nxt);
		ans += w;
	}

	cout << ans;
}