#include <iostream>
#include <string>

using namespace std;

int dp[101][101];

string pattern;
string s;

// dp�� �ʱⰪ�� -1�� ����
void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
			dp[i][j] = -1;
	}
}

// pattern�� pidx���� ���ڿ��� s�� sidx ���ڿ��� ��Ī�Ǹ� 1, �׷��� ������ 0 ����
int solve(int pidx, int sidx) {
	// �� ���ڿ� ��� ���������� �˻� �Ϸ�
	if (pidx == pattern.length() && sidx == s.length())
		return 1;

	// s�� �������� ��Ī�� ������ ���� ���
	if (pidx >= pattern.length())
		return 0;

	// ���� ������ ���ڰ� *�� �ƴѵ� s�� ���� ���
	if (sidx >= s.length() && pattern[pidx] != '*')
		return 0;

	// �ش� �ε����� dp���� �����ϴ� ���
	if (dp[pidx][sidx] != -1)
		return dp[pidx][sidx];

	// ���� ������ ���ڰ� *�� ���
	if (pattern[pidx] == '*') {
		int result = 0;

		if (sidx <= s.length()) {
			// *�� ��Ī�Ǵ� ���ڰ� 0���� ���
			if (solve(pidx + 1, sidx))
				result = 1;

			// *�� ��Ī�Ǵ� ���ڰ� 1���� ���
			if (solve(pidx + 1, sidx + 1))
				result = 1;

			// *�� ��Ī�Ǵ� ���ڰ� 2�� �̻��� ���
			if (solve(pidx, sidx + 1))
				result = 1;
		}

		return dp[pidx][sidx] = result;
	}
	else {
		if (pattern[pidx] == s[sidx])
			return dp[pidx][sidx] = solve(pidx + 1, sidx + 1);
		else
			return dp[pidx][sidx] = 0;
	}
}

int main() {
	cin >> pattern;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		init();
		cin >> s;

		if (solve(0, 0))
			cout << s << "\n";
	}
}