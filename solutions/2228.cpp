#include <iostream>
#include <algorithm>

#define INF 3276701

using namespace std;

int cumsum[101]; // cumsum[i]: i��° ���ұ��� ���� ��
int dp[101][51]; // dp[i][j]: 0���� i-1������ �迭 �� j�� ���� ���� �ִ밪
int arr[100];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cumsum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cumsum[i] = cumsum[i - 1] + arr[i - 1];
    }

    // dp �ʱ�ȭ
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -INF;
        }
        // ������ ������ 0���� ���
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(m, (i + 1) / 2); j++) {
            // i��° ���Ҹ� �������� �ʴ� ���
            dp[i][j] = dp[i - 1][j];

            // i��° ���Ҹ� ���� �տ� ���Խ�Ű�� ���
            for (int k = 1; k <= i; k++) {
                // k��°���� i��°���� ���� ��
                int k2i = cumsum[i] - cumsum[k - 1];

                // ù ��° ������ ���
                if (j == 1) {
                    dp[i][j] = max(dp[i][j], k2i);
                }
                else if (k >= 2) {
                    dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + k2i);
                }
            }
        }
    }

    cout << dp[n][m];
}
