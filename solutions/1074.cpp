#include <iostream>
#include <cmath>

using namespace std;

int z(int n, int r, int c) {

	// 0����
	if (pow(2, n - 1) > r && pow(2, n - 1) > c) {
		if (n == 1)
			return pow(pow(2, n - 1), 2) * 0;
		else
			return pow(pow(2, n - 1), 2) * 0 + z(n - 1, r % (int)pow(2, n - 1), c % (int)pow(2, n - 1));
	}
	// 1����
	else if (pow(2, n - 1) > r && pow(2, n - 1) <= c) {
		if (n == 1)
			return pow(pow(2, n - 1), 2) * 1;
		else
			return pow(pow(2, n - 1), 2) * 1 + z(n - 1, r % (int)pow(2, n - 1), c % (int)pow(2, n - 1));
	}
	// 2����
	else if (pow(2, n - 1) <= r && pow(2, n - 1) > c) {
		if (n == 1)
			return pow(pow(2, n - 1), 2) * 2;
		else
			return pow(pow(2, n - 1), 2) * 2 + z(n - 1, r % (int)pow(2, n - 1), c % (int)pow(2, n - 1));
	}
	// 3����
	else if (pow(2, n - 1) <= r && pow(2, n - 1) <= c) {
		if (n == 1)
			return pow(pow(2, n - 1), 2) * 3;
		else
			return pow(pow(2, n - 1), 2) * 3 + z(n - 1, r % (int)pow(2, n - 1), c % (int)pow(2, n - 1));
	}

}

int main() {
	int n, r, c; // 2^n * 2^n�� ������ �迭, r�� c���� �� ��°�� �湮�ϴ��� ���
	cin >> n >> r >> c;

	cout << z(n, r, c);
}