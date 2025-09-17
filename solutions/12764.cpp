#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> com; // {���� �ð�, ��ǻ�� ��ȣ}
	priority_queue<int, vector<int>, greater<int>> able; // ������ ��ǻ�� ��ȣ

	int total = 0; // ����� �� ��ǻ��
	vector<int> cnt(n); // ��ǻ�� ��� Ƚ��
	for (int i = 0; i < n; i++) {
		int start = v[i].first;
		int end = v[i].second;

		// ����� ���� �ð����� ��ǻ�� ���� �ð��� ���� ��� ����
		while (!com.empty() && com.top().first < start) {
			int num = com.top().second;
			com.pop();
			able.push(num);
		}

		// ��ǻ�� ����
		if (able.empty()) {
			cnt[total]++;
			com.push({ end,total });
			total++;
		}
		else {
			cnt[able.top()]++;
			com.push({ end,able.top() });
			able.pop();
		}
	}

	cout << total << "\n";
	for (int i = 0; i < total; i++) {
		cout << cnt[i] << " ";
	}
}