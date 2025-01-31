#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;

bool isFit(vector<int> row, vector<int> col, int i, int j) {
	// ���� 1�� ��ƼĿ�� ���»�ܿ� ��ġ�Ѵ�. limit_h�� limit_w�� �ִ�� ������ h �Ǵ� w�� ����.
	int limit_h = (h - row[i] == 0) ? h : h - row[i];
	int limit_w = (w - col[i] == 0) ? w : w - col[i];

	// 1�� ��ƼĿ�� �ùٸ��� �ٿ����� ���� ���
	if ((limit_h < 0 || limit_w < 0))
		return false;

	// 1�� ��ƼĿ�� �����̸� �Ѿ�� ���
	if ((row[i] > max(h, w)) || (col[i] > max(h, w)))
		return false;

	// 2�� ��ƼĿ�� �����̸� �Ѿ�� ���
	if ((row[j] > max(h, w)) || (col[j] > max(h, w)))
		return false;

	// 1�� ��ƼĿ�� ��ü �����̸� �� ���� ���
	if (limit_w == w && limit_h == h)
		return false;

	// 1�� ��ƼĿ�� �������� �� �� �𼭸��� �� ���� ���
	if (limit_w == w || limit_h == h) {
		if ((col[j] <= limit_w && row[j] <= limit_h) || (row[j] <= limit_w && col[j] <= limit_h) || (col[j] <= limit_h && row[j] <= limit_w) || (row[j] <= limit_h && col[j] <= limit_w))
			return true;
		else
			return false;
	}

	// 2�� ��ƼĿ�� �ֿ��ϴܿ� ��ġ�� �� �ִ� ��� (�� ������ �����¶�� ����)
	if ((row[j] <= h && col[j] <= limit_w) || (col[j] <= h && row[j] <= limit_w) || (row[j] <= w && col[j] <= limit_h) || (col[j] <= w && row[j] <= limit_h))
		return true;

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> h >> w >> n;

	vector<int> row;
	vector<int> col;
	for (int i = 0;i < n;i++) {
		int r, c;
		cin >> r >> c;
		row.push_back(r);
		col.push_back(c);
	}

	int m = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i != j && (isFit(row, col, i, j) || (isFit(col, row, i, j)))) {
				int s = row[i] * col[i] + row[j] * col[j];
				m = (m > s) ? m : s;
			}
		}
	}

	cout << m;
}