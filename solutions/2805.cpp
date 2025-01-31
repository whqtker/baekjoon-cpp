#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> tree;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		tree.push_back(x);
	}

	sort(tree.begin(), tree.end());

	int l = 0;
	int r = tree[tree.size() - 1];
	int mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		unsigned long long h = 0;
		for (int i = 0;i < n;i++) {
			// ���� �߸��ٸ�
			if (tree[i] - mid > 0) {
				h += tree[i] - mid;
			}

			// �߸� ���̰� ��ǥ ���̺��� Ŭ ��� ���� ����� �ʿ���� (�����÷ο� ����)
			if (h > m) break;
		}

		if (h > m) {
			if (l == mid) break;
			l = mid;
		}
		else if (h < m) {
			if (r == mid) break;
			r = mid;
		}
		else break;
	}

	cout << mid;
}