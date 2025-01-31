#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int gap = 2e9 + 1; // gap�� 0�� ���� ����� ������ ã�´�.
	int l = 0, r = 0; // left, right index
	for (int i = 0; i < n; i++) {
		int tmp = lower_bound(v.begin() + i + 1, v.end(), -v[i]) - v.begin();

		// tmp ���� �� �ʵ� Ȯ��
		for (int j = -1; j <= 1; j++) {
			// out of bound Ȯ��
			if (tmp + j > 0 && tmp + j < n && tmp + j != i) {
				if (gap > abs(v[i] + v[tmp + j])) {
					gap = abs(v[i] + v[tmp + j]);
					l = i;
					r = tmp + j;
				}
			}
		}
	}

	cout << v[l] << " " << v[r];
}