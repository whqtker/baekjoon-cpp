#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> e; // ���� ���
	vector<int> r; // ���� ���

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		e.push_back(x);
		r.push_back(i + 1);
	}

	sort(e.begin(), e.end());
	sort(r.begin(), r.end());

	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(e[i] - r[i]);
	}
	cout << ans;
}