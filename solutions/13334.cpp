#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v; // ��ǥ ����
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		if (s > e)
			swap(s, e);

		v.push_back({ s,e });
	}

	// ������ �������� ����
	sort(v.begin(), v.end(), cmp);

	int d;
	cin >> d;

	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq; // �������� �����ϴ� �켱���� ť

	// �� ������ ������ ö�θ� ��ġ�Ѵ�.
	for (int i = 0; i < n; i++) {
		int e = v[i].second; // ö���� ����
		int s = e - d; // ö���� ������

		// ������ �����ϱ�
		pq.push(v[i].first);

		// pq�� ����� �������� s���� ���� ��� ����
		while (!pq.empty()) {
			if (pq.top() < s)
				pq.pop();
			else
				break;
		}

		ans = max(ans, (int)pq.size());
	}

	cout << ans;
}