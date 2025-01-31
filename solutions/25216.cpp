#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t; // n: ������ ��, m: ��Ż�� ��, t: ���� ���� �ð�
int a[5001]; // ���� �⺻ ���ݷ�
int x[5001]; // ���� ���ݷ�/�ð�
int y[5001]; // ���ݷ� ���ҷ�/����
int c[5001]; // ����
int dp[5001][101]; // dp[i][j]: j�п� i ������ ���� �� �ִ� ������ ��
vector<int> portal[5001]; // portal[i][j]: i���� j�� �̵��ϴ� ��Ż ����

void dp_clear() {
	for (int i = 0;i < 5001;i++) {
		for (int j = 0;j < 101;j++) {
			dp[i][j] = -1;
		}
	}
}

// Ư�� ������ �� ���� �� �ִ� �ִ� ���� ���� ����, (���� �ð�, ���� ���� ��ġ, ����)
int dungeon(int cur, int pos, long long armor) {
	// ���� �ð��� 0�̸� 0 ����
	if (cur == 0)
		return 0;

	// �������� �й��ϸ� 0 ����
	if (a[pos] + x[pos] * (t - cur) - y[pos] * armor > 0)
		return 0;

	// ������ ����, �ð��� dp�� �̹� �����ϴ� ��� �ش� �� ����
	if (dp[pos][cur] != -1) {
		return dp[pos][cur];
	}

	int max_coin = c[pos]; // �ִ� ���� ��
	for (int i = 0;i < portal[pos].size();i++) {
		max_coin = max(dungeon(cur - 1, portal[pos][i], armor) + c[pos], max_coin);
	}

	dp[pos][cur] = max_coin;
	return max_coin;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> t;
	for (int i = 1;i <= n;i++) {
		cin >> a[i] >> x[i] >> y[i] >> c[i];
	}
	for (int i = 1;i <= m;i++) {
		int p, q;
		cin >> p >> q;
		portal[p].push_back(q);
	}

	// 1�� �������� ����
	// �÷��̾��� ������ ����� ũ�ٰ� �����ϰ� ���� �� �ִ� �ִ� ���� ���� ã�´�.
	// �� ���� �̺� Ž���� ���� �ִ� ���� ���� ��� ���� �ּ� ������ ã�´�.
	// �־��� ���� �� ������ ������ �ִ��� 1e9+1e6�̴�. ��, ������ 1e9+1e6�̶�� ��� ���ݵ� ��ƿ �� �ִ�.
	dp_clear();
	long long armor = 1e9 + 1e6;
	int max_coin = dungeon(t, 1, armor); // ������ �ִ� ���� ��

	long long l = 0;
	long long r = 1e9 + 1e6;
	long long mid = (l + r) / 2;

	while (l <= r) {
		dp_clear();
		mid = (l + r) / 2;
		if (dungeon(t, 1, mid) < max_coin) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << l;
}