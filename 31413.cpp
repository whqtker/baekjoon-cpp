#include <iostream>
#include <algorithm>

using namespace std;

int v[1000]; // 봉사활동 가산점
int dp[1000][1000]; // dp[i][j]: i일까지의 최대 가산점, 헌혈 j번 함

int main() {
	int n, m, a, d; // n: 남은 일수, m: 필요한 가산점, a: 헌혈 가산점, d: 헌혈 후 쉬어야 하는 날
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> a >> d;

	dp[0][0] = v[0];
	dp[0][1] = a;

	int ans = 1001;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			// 봉사활동을 하는 경우
			if (dp[i - 1][j] > dp[i - 1][j - 1]) {
				dp[i][j] = dp[i - 1][j] + v[i];
			}
			// 헌혈을 하는 경우
			else {
				dp[i][j] = dp[i - 1][j - 1] + a;
				for (int k = 1; k <= d; k++) {
					dp[i + k][j] = dp[i][j];
				}
			}

			if (dp[i][j] >= m)
				ans = min(ans, j);
		}
	}

	if (ans != 1001)
		cout << ans;
	else
		cout << -1;
}