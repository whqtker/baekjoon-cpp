#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k; // n���� ����, ��ǥ �ݾ� k��
	cin >> n >> k;

	vector<int> v; // ���� �ݾ�
	int idx = 0; // k������ ���� ���� �� ���� ū ������ �ε���
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);

		if (x <= k)idx = i;
	}

	int cnt = 0;
	for (int i = idx; i >= 0; i--) {
		while (k - v[i] >= 0) {
			k -= v[i];
			cnt++;
		}
	}

	cout << cnt;
}