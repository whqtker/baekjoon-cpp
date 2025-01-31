#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[50001]; // dp[i]: i���� ���� �� �ִ°�?

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int idx = 0; idx < 3; idx++) {
        int n;
        cin >> n;

        vector<pair<int, int>> coins(n); // ������ (����, ����)
        int amount = 0;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            coins[i] = { a, b };
            amount += a * b;
        }

        // ������ Ȧ���� ������ �� ��
        if (amount % 2 == 1) {
            cout << "0\n";
            continue;
        }
        amount /= 2; // ���� ������� amount�� ���� �� �ִٸ� ���ݾ� �й� ����

        // dp �ʱ�ȭ
        fill(dp, dp + amount + 1, 0);
        dp[0] = 1; // 0���� ����� ���

        for (auto coin : coins) {
            int value = coin.first; // ������ �ݾ�
            int count = coin.second; // ������ ����

            for (int j = amount; j >= value; j--) {
                // ���� ������ ����� �� �ִ� ��ŭ �ݺ�
                for (int k = 1; k <= count && j >= k * value; k++) {
                    // j���� ���� �� �ִ� ���
                    if (dp[j - k * value]) {
                        dp[j] = 1;
                        break; // �� ���̶� j���� ���� �� �ִٸ� �� �̻� k�� ������ų �ʿ� ����
                    }
                }
            }
        }

        cout << dp[amount] << "\n";
    }
}
