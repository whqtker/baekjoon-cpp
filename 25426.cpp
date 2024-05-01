#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool cmp(pair<int, int>& a, pair<int, int >& b) {
	return a.first * n + a.second < b.first * n + b.second;
}

int main() {
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end(), cmp);

	long long ans = 0;
	for (int i = n; i >= 1; i--) {
		ans += v[i - 1].first * i + v[i - 1].second;
	}
	cout << ans;
}