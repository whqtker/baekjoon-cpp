#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void check(vector<int>& cnt, vector<string> c, vector<string>& b, vector<string>& w, int x, int y) {
	int m = x - 8;
	int n = y - 8;

	int change = 0;
	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if (c[i][j] != w[i - n][j - m]) change++;
		}
	}
	cnt.push_back(change);

	change = 0;
	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if (c[i][j] != b[i - n][j - m]) change++;
		}
	}
	cnt.push_back(change);
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> chess; //chess�� ���Ҵ� ü���� ���̰�, n���� ���� ������ ���� ���Ҵ� m����, m * n ũ��
	for (int i = 0; i < n; i++) {
		string e;
		cin >> e;
		chess.push_back(e);
	}

	// 8 * 8 ü���� Ʋ�̸� black�� white�� ù ��° ���� ù ��° ������ ���̴�.
	vector<string> black;
	vector<string> white;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			black.push_back("BWBWBWBW");
			white.push_back("WBWBWBWB");
		}
		else if (i % 2 == 1) {
			black.push_back("WBWBWBWB");
			white.push_back("BWBWBWBW");
		}
	}

	vector<int> cnt; // �ٽ� ĥ�ؾ� �ϴ� Ƚ���� �����ϴ� ����
	// i - 8: Ʋ�� �� ���� ü������ ���� ���� ���� �ε���, j - 8: Ʋ�� �� ���� ü������ ���� ���� ���� �ε���, ��, [j - 8][i - 8]�� ü������ ���� ù ��° ����
	for (int i = 8; i <= m; i++) {
		for (int j = 8; j <= n; j++) {
			check(cnt, chess, black, white, i, j);
		}
	}

	cout << *min_element(cnt.begin(), cnt.end());
}