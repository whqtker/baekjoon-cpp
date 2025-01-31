#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char change(char c) {
	return !(c - '0') + '0';
}

int main() {
	int n;
	string a, b;
	cin >> n >> a >> b;

	// 0�� ° ������ ������ �� Ƚ���� ������ �ʾ��� �� Ƚ���� �ּڰ��� ��
	int x = 0, y = 0; // Ƚ��

	// 0�� ° ������ ������ ���� ���
	string tmp = a;
	for (int i = 1; i < n; i++) {
		if (tmp[i - 1] != b[i - 1]) {
			tmp[i - 1] = change(tmp[i - 1]);
			tmp[i] = change(tmp[i]);
			if (i + 1 < n)
				tmp[i + 1] = change(tmp[i + 1]);

			x++;
		}
	}
	if (tmp != b)
		x = 1e5 + 1;

	// 0�� ° ������ ���� ���
	a[0] = change(a[0]);
	a[1] = change(a[1]);
	y++;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] != b[i - 1]) {
			a[i - 1] = change(a[i - 1]);
			a[i] = change(a[i]);
			if (i + 1 < n)
				a[i + 1] = change(a[i + 1]);

			y++;
		}
	}
	if (a != b)
		y = 1e5 + 1;

	if (min(x, y) == 1e5 + 1)
		cout << -1;
	else
		cout << min(x, y);
}