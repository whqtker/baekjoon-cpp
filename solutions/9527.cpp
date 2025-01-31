#include <iostream>
#include <cmath>

using namespace std;

long long arr[54]; // arr[i]: MSB�� i���� ���ų� ���� ������ 1�� ����, 10^16�� ��Ʈ ���� 54��

long long sum(long long x) {
	long long ans = 0;

	// �ֻ�� ��Ʈ���� ����
	for (int i = 54; i >= 0; i--) {
		// ���� x�� i�� ° ��Ʈ�� 1�̶��
		if (x & (1LL << i)) {
			ans += arr[i - 1] + (x - (1LL << i) + 1);
			x -= 1LL << i;
		}
	}

	return ans;
}

int main() {
	long long a, b;
	cin >> a >> b;

	arr[0] = 1;
	for (int i = 1; i < 55; i++) {
		arr[i] = 2 * arr[i - 1] + (1LL << i);
	}

	cout << sum(b) - sum(a - 1);
}