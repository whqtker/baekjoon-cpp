#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis_idx[500001];
int conn[500001]; // conn[i] = j: BÀüº¿´ëÀÇ i¹ø°ú AÀüº¿´ëÀÇ j¹øÀÌ ¿¬°áµÊ

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
		conn[b] = a;
	}

	sort(v.begin(), v.end());

	vector<int> end, lis;
	for (int i = 0; i < n; i++) {
		end.push_back(v[i].second);
	}

	for (int i = 0; i < n; i++) {
		int idx = lower_bound(lis.begin(), lis.end(), end[i]) - lis.begin();

		if (idx == lis.size())
			lis.push_back(end[i]);
		else
			lis[idx] = end[i];

		lis_idx[i] = idx;
	}

	int cur = lis.size() - 1;
	vector<int> not_lis;
	for (int i = n - 1; i >= 0; i--) {
		if (cur != lis_idx[i]) {
			not_lis.push_back(conn[end[i]]);
		}
		else
			cur--;
	}

	cout << not_lis.size() << "\n";
	sort(not_lis.begin(), not_lis.end());
	for (int i = 0; i < not_lis.size(); i++) {
		cout << not_lis[i] << "\n";
	}
}