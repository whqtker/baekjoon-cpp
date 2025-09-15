#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, c;
	cin >> n >> c;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int l = 1; // ������ ���� �Ÿ� �ּҰ�
	int r = v[n - 1] - v[0]; // ������ ���� �Ÿ� �ִ밪
	int ans = 0; // ���� ������ ���� �ִ� �Ÿ�

	while (l <= r) {
		int m = (l + r) / 2; // ���� ������ ���� �ִ� �Ÿ� �ĺ���

		// ù ��° ������ �ݵ�� �����⸦ ��ġ�Ѵ�.
		int cnt = 1;
		int s = v[0]; // ���� ������ ��ġ ��ġ
		for (int i = 1;i < n;i++) {
			if (v[i] - s >= m) {
				cnt++;
				s = v[i];
			}
		}

		if (cnt >= c) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << ans;
}