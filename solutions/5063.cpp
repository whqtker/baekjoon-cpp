#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int r, e, c; // r: ���� ���� �ʾ��� �� ����, e: ���� ���� �� ����, c: ���� ���
		cin >> r >> e >> c;

		// e - c�� ���� ���� �� �������̴�.
		if (r > e - c) cout << "do not advertise\n";
		else if (r < e - c) cout << "advertise\n";
		else cout << "does not matter\n";
	}
}