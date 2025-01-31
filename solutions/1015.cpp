#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // ���� a, b�� ũ��
	cin >> n;

	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	// b[p[i]] = a[i]�̰� b�� �񳻸�����(�ش� ���Ұ� �տ� �ִ� ���Һ��� ũ�ų� ����)
	// a�� sort�� ����� ������ ���� �ε����� p�̴�.
	vector<int> sorted = a;
	sort(sorted.begin(), sorted.end());

	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sorted[i] == a[j]) {
				p[j] = i;
				a[j] = -1;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << p[i] << " ";
}