#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[4000001];

int Find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x < y) {
		parent[x] = y;
	}
	else
		parent[y] = x;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	vector<int> v;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;

		int idx = upper_bound(v.begin(), v.end(), x) - v.begin();
		int card_idx = Find(idx); // ������ ���� �ϴ� ī���� �ε���
		cout << v[card_idx] << "\n";

		// ������ ���� �� ī�带 �ٽ� �����Ѵٸ� �� �������� ū ���� ī�带 ���� ��. ���� ���� ī��� ���� ī�带 Union
		Union(Find(card_idx), Find(card_idx) + 1);
	}
}