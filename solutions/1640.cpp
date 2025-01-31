#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int col[1001];
int row[1001];

// 1. �� �Ǵ� ���� ¦�� �Ǵ� Ȧ���� �����Ѵ�.
// 2. Ȧ�� ���� ������ ��� �ٸ� �� �Ǵ� ���� ¦�� ���� �����´�.
// 3. ¦�� ���� ������ ��� �� �ݴ�
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			int x = s[j] - '0';
			row[i] += x;
			col[j] += x;
		}
	}

	int row_odd = 0, row_even = 0, col_odd = 0, col_even = 0;
	for (int i = 0; i < n; i++) {
		if (row[i] % 2)
			row_odd++;
		else
			row_even++;
	}
	for (int i = 0; i < m; i++) {
		if (col[i] % 2)
			col_odd++;
		else
			col_even++;
	}

	int ans1, ans2;

	// ���� ��� ¦����
	if (row_odd % 2 == 0)
		ans1 = row_odd + col_odd;
	else
		ans1 = row_odd + col_even;

	// ���� ��� Ȧ����
	if (row_even % 2 == 0)
		ans2 = row_even + col_odd;
	else
		ans2 = row_even + col_even;

	cout << min(ans1, ans2);

}