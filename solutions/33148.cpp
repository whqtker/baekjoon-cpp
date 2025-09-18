#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	map<long long, int> m; // m[x]=y: x�� ������ y
	vector<long long> a; // ���� �迭
	for (int i = 0; i < n * n; i++) {
		long long x;
		cin >> x;
		m[x]++;
	}

	// m���� ���� ���� ���� �������� a�� ���� ���� ���̴�.
	// cf) a�� ���� num�� ���� cnt����� m���� num^2�� cnt^2�� �����ϴ� ���� �ƴϴ�. �ݷ�: A: {2, 8}
	long long min = m.begin()->first;
	long long root = sqrtl(min);
	if (root * root == min) {
		a.push_back(root);
		m[min]--;
		if (m[min] == 0)
			m.erase(min);
	}
	else {
		cout << "NO";
		return 0;
	}

	// a�� ���� ���� ���Ҹ� ���� ���������� a�� �����Ѵ�.
	// ���� ã�� ���ҷ� m�� ���� �� �ִ��� �����Ѵ�.
	for (int i = 1; i < n; i++) {
		if (m.empty()) {
			cout << "NO";
			return 0;
		}

		long long min = m.begin()->first; // min = a[0]*a[i]
		if (min % a[0] != 0) {
			cout << "NO";
			return 0;
		}
		long long cur = min / a[0];
		a.push_back(cur);

		for (int j = 0; j < i; j++) {
			// �����÷ο� ����
			if (a[j] > 0 && cur > LLONG_MAX / a[j]) {
				cout << "NO";
				return 0;
			}

			long long chk = cur * a[j];

			m[chk] -= 2; // ��Ī���� �����ϹǷ�

			if (m[chk] < 0) {
				cout << "NO";
				return 0;
			}
			else if (m[chk] == 0) {
				m.erase(chk);
			}
		}

		// a[i] * a[i]
		// �����÷ο� ����
		if (cur > 0 && cur > LLONG_MAX / cur) {
			cout << "NO";
			return 0;
		}
		long long chk = cur * cur;
		m[chk]--;

		if (m[chk] < 0) {
			cout << "NO";
			return 0;
		}
		else if (m[chk] == 0) {
			m.erase(chk);
		}
	}

	if (!m.empty()) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}