#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	v.push_back(0);
	v.push_back(1); // 1�� ���
	// �������� �ּ� ������ �׻� 1�̴�.

	for (int i = 2;i <= n;i++) {
		v.push_back(1 + v[i - 1]);
		for (int j = 2;j * j <= i;j++) {
			v[i] = min(v[i], 1 + v[i - j * j]);
		}
	}
	cout << v[n];
}