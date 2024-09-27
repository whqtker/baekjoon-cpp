#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int ans = 65; // 사각지대의 최소 크기
int cnt; // cctv로 감지할 수 있는 영역의 수
int board[8][8];
int visited[8][8];
vector<pair<int, int>> cctv; // cctv의 좌표

int cal(int x, int y, int d) {
	// 기본 형태를 기준으로 d의 값이 1씩 증가하면 반시계 방향으로 90도 회전

	int type = board[x][y];

	if (type == 1) {

	}
}

void dfs(int k) {
	// 모든 cctv에 접근한 경우
	if (k == cctv.size() - 1) {
		ans = min(ans, n * m - cnt);
		return;
	}

	int x = cctv[k].first;
	int y = cctv[k].second;
	for (int i = 0;i < 4;i++) {
		// 현재 cctv와 방향에 따라 계산된 새로운 감지 영역의 수
		int newCnt = cal(x, y, i);

		cnt += newCnt;
		dfs(k + 1);
		cnt -= newCnt;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];

			// 입력된 값이 cctv라면
			if (board[i][j] > 0 && board[i][j] < 6) {
				cctv.push_back({ i,j });
			}
		}
	}

	dfs(0);
	cout << ans;
}