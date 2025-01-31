#include <iostream>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

// �� k�� ���̸� ����
ll len(ll k) {
	return (ll)log10(k) + 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (1) {
		ll n;
		cin >> n;
		if (n == 0)
			break;

		ll l = 1;
		ll r = 1e15;

		n--; // �ε��� ����
		while (1) {
			ll m = (l + r) >> 1;

			// A[N]���� N�� 4�� ����� A[N]�� ���̴� N�� ���̿� �����ϴ�.
			// N�� 4�� ����� �ƴϸ� A[N]�� ���̴� N�� ���� + 1�̴�.
			ll s = 0; // m�� �����ϴ� �� A[N]�� ù ��° ������ �ε���
			
			ll digit = len(m);

			ll e = m % 4 == 0 ? s + len(m)-1 : s + len(m); // m�� �����ϴ� ���� ������ ������ �ε���

			if (s <= n && n <= e) {
				if (m % 4 != 0 && n == e) {
					// N�� ���� �ڸ��� * 10 + x�� 4�� ����� �Ǵ� x ã��
					int num = m % (int)pow(10, len(m));
					for (int i = 0;i < 10;i++) {
						if ((num + i) % 4 == 0) {
							cout << i << "\n";
							break;
						}
					}
				}
				else {
					cout << to_string(m)[n - s] << "\n";
					break;
				}
			}
			else if (n < s) {
				r = m - 1;
			}
			else if (e < n) {
				l = m + 1;
			}
		}
	}
}