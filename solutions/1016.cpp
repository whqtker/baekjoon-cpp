#include <iostream>
#include <cmath>

using namespace std;

int arr[1000001]; // a�� ���� �ε����� 0 / ��, Ư�� �� x�� �ε����� x - a

int main() {
	long long a, b;
	cin >> a >> b;

	// p^2���� ������ �������ٸ� ���� ���� ���� �� �� ����. (p�� �Ҽ�)
	// a���� p^2���� ������ �������� ������ arr�� ǥ���Ͽ�, b �������� �����Ѵ�.
	// ��, ǥ��� ������ ���� ���� ���� �� �� ����.

	long long p = 2; // 2���� ����
	long long ans = b - a + 1;

	while (p * p <= b) {
		// start: a���� ū (p * p) * k�� �� �� a�� ���� ����� �������� k
		long long start = a / (p * p);
		if (start * (p * p) < a)
			start++;

		// a�� b ������ �� �� p * p�� ����� ������ ǥ��
		while (start * (p * p) <= b) {
			// �̹� ǥ��Ǿ��ٸ� ��ŵ
			if (!arr[start * (p * p) - a]){
				arr[start * (p * p) - a] = 1;
				ans--;
			}

			start++;
		}

		p++;
	}

	cout << ans;
}