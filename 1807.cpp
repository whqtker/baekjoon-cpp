#include <iostream>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

// 수 k의 길이를 구함
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

		n--; // 인덱스 보정
		while (1) {
			ll m = (l + r) >> 1;

			// A[N]에서 N이 4의 배수면 A[N]의 길이는 N의 길이와 동일하다.
			// N이 4의 배수가 아니면 A[N]의 길이는 N의 길이 + 1이다.
			ll N = 1; // m에 존재하는 수(A[N])의 N의 값
			ll s = 0; // m에 존재하는 수의 첫 번째 숫자의 인덱스
			while (s + len(N) < m) {
				cout << s << "가 시작인덱스인 N: " << N << "\n";
				if (N % 4 == 0) {
					s += len(N);
				}
				else {
					s += len(N) + 1;
				}
				N++;
			}
			ll e = N % 4 == 0 ? s + len(N) : s + len(N) - 1; // m에 존재하는 수의 마지막 숫자의 인덱스

			if (s <= n && n <= e) {
				if (N % 4 != 0 && n == e) {
					// N의 일의 자리수 * 10 + x가 4의 배수가 되는 x 찾기
					int num = N % (int)pow(10, len(N));
					for (int i = 0;i < 10;i++) {
						if ((num + i) % 4 == 0) {
							cout << i << "\n";
						}
					}
				}
				else {
					cout << to_string(N)[n - s] << "\n";
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