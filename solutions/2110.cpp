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

	int l = 0;
	int r = v[n - 1];
	int ans = 0;

	while (l <= r) {
		int cnt = 1;
		int m = (l + r) / 2;

		int s = v[0];
		for (int i = 1;i < n;i++) {
			if (v[i] - s >= m) {
				cnt++;
				s = v[i];
			}
		}

		if (cnt >= c) {
			ans = max(ans, m);
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << ans;
}