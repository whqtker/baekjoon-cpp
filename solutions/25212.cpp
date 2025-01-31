#include <iostream>

using namespace std;

int n;
double cake[10];
int ans = 0;

// ���� idx, ���� ��
void recur(int pos, double sum) {
	if (pos == n) {
		if (sum >= 0.99 && sum <= 1.01)
			ans++;
		return;
	}

	// ���� ����ũ ���� ����
	recur(pos + 1, sum);

	// ���� ����ũ ������
	recur(pos + 1, sum + cake[pos]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cake[i] = 1.0 / x;
	}

	recur(0, 0.0);
	cout << ans;
}