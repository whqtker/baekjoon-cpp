#include <iostream>

using namespace std;

int board[101][101];
int row[101]; // row[i] = 1: i번 째 행은 지나갈 수 있음
int col[101];

int main() {
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {

	}

	for (int j = 0; j < n; j++) {
		int seq = 1; // 높이가 같은 길이 연속된 수
		bool able = true; // 해당 탐색이 지나갈 수 있는 길인지

		for (int i = 1; i < n; i++) {
			if (board[i][j] == board[i - 1][j]) {
				seq++;
			}
			else if (board[i][j]  == board[i - 1][j]+1) {
				if (seq >= l) {
					seq = 1;
				}
				else {
					able = false;
					break;
				}
			}
			else {
				able = false;
				break;
			}
		}

		if (able) {
			if (!col[j]) {
				col[j] = 1;
				ans++;
			}
		}
	}

	cout << ans;
}