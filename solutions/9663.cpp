#include <iostream>

using namespace std;

int n;
int col[16]; // ���� �� �� �Ǵ� ���� �ϳ��� �־�� �ϸ� �밢������ �������� ��ġ�ϸ� �� �ȴ�.
int ans = 0;

bool cond(int k) {
	for (int i = 0;i < k;i++) {
		if (col[i] == col[k] || abs(col[k] - col[i]) == k - i) {
			return false;
		}
	}
	return true;
}

void bt(int k) {
	if (n == k) {
		ans++;
		return;
	}

	for (int i = 0;i < n;i++) {
		col[k] = i;
		if (cond(k))
			bt(k + 1);
	}
}

int main() {
	cin >> n;

	bt(0);
	cout << ans;
}