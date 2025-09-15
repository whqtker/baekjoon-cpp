#include <iostream>
#include <vector>
#include <string>

using namespace std;

// dp[mask][r] = x: mask�� ���Ե� ���� ���� ������ ������� ��, k�� ���� �������� r�� �Ǵ� ����� ���� x
long long dp[1 << 15][100];

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int k;
	cin >> k;

	// 10^l % k
	vector<int> pow_of_tens(51);
	pow_of_tens[0] = 1;
	for (int i = 1; i <= 50; i++) {
		pow_of_tens[i] = (pow_of_tens[i - 1] * 10) % k;
	}

	vector<int> len(n), modk(n); // len[i]: v[i]�� ����, modk[i]: v[i] % k
	for (int i = 0; i < n; i++) {
		len[i] = v[i].length();

		for (int j = 0; j < v[i].length(); j++) {
			modk[i] = (modk[i] * 10 + (v[i][j] - '0')) % k;
		}
	}

	dp[0][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int r = 0; r < k; r++) {
            if (dp[mask][r] == 0) continue;

            for (int i = 0; i < n; i++) {
                // i��° ���ڸ� ������ ���Խ�Ű�� ���� ���
                if (!(mask & (1 << i))) {
                    int nmask = mask | (1 << i); // ������ ���Խ�Ų��.

                    int nr = (r * pow_of_tens[len[i]] + modk[i]) % k;

                    dp[nmask][nr] += dp[mask][r];
                }
            }
        }
    }

    long long p = dp[(1 << n) - 1][0]; // ��� ���ڸ� ���� �� �������� 0�� ����� ��

    if (p == 0) {
        cout << "0/1" << endl;
        return 0;
    }

    // q = n!
    long long q = 1;
    for (int i = 1; i <= n; i++) {
        q *= i;
    }

    cout << p / gcd(p, q) << "/" << q / gcd(p, q);
}