#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int ans = 2e9;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// �� �������� ������ (i, j)
			int l = i + 1;
			int r = j - 1;

			// (i, j), (l, r)�� ���� ���� ���Ѵ�.
			while (l < r) {
				int outer = v[i] + v[j];
				int inner = v[l] + v[r];
				int cand = abs(outer - inner);

				if (cand < ans) {
					ans = cand;
				}
				
				if (outer > inner) {
					l++;
				}
				else {
					r--;
				}
			}
		}
	}

	cout << ans;
}