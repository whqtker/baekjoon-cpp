#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	// 5 * a <= x < 5 * (a + 1) �϶� x!�� 0�� ���� : a + a / 5 + a / 25 + ...
	int sum = 0;
	while (n != 0) {
		n /= 5;
		sum += n;
	}
	cout << sum;
}