#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int dp[2501]; // dp[i]: i�� °���� ���ҵ� �Ӹ������ �ּڰ�

bool isPalindrome(int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    cin >> s;
    
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int minCuts = i + 1; // �ִ� i + 1�� ���� ����
        for (int j = 0; j <= i; j++) {
            if (isPalindrome(j, i)) {
                // j���� i���� �ϳ��� �Ӹ������. �̶� i���� �ּ� �Ӹ������ ���� dp[j - 1] + 1�� �� �� ����.
                // ���� ó������ �ϳ��� �Ӹ�����̶�� 1�� ����
                minCuts = (j == 0) ? 1 : min(minCuts, dp[j - 1] + 1);
            }
        }
        dp[i] = minCuts;
    }

    cout << dp[n - 1];
}