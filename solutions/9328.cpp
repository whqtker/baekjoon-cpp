#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

string arr[100];
int keys[26];
int h, w;
int visited[100][100]; // [x��ǥ][y��ǥ]
int opened[26];
int ans = 0;
bool re = false; // bfs ����� ����

queue<pair<int, int>> q;

bool outOfBound(int x, int y) {
	return x < 0 || y < 0 || x >= h || y >= w;
}

void visited_clear() {
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			visited[i][j] = 0;
		}
	}
}

void keys_opened_clear() {
	for (int i = 0;i < 26;i++) {
		keys[i] = 0;
		opened[i] = 0;
	}
}

// Ű�� ã�Ҵٸ� bfs �����
bool bfs() {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	visited_clear();
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// ���� �߰�
			if (!outOfBound(nx, ny) && arr[nx][ny] - 'a' >= 0 && arr[nx][ny] - 'a' <= 25 && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				keys[arr[nx][ny] - 'a'] = 1;
				arr[nx][ny] = '.';
				re = true;
				q.push({ nx,ny });
			}

			// �� �������� �̵�
			if (!outOfBound(nx, ny) && arr[nx][ny] == '.' && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}

			// �� �߰�
			if (!outOfBound(nx, ny) && arr[nx][ny] - 'A' >= 0 && arr[nx][ny] - 'A' <= 25 && !visited[nx][ny]) {
				// ���� �� �� �ִ� ���谡 �ִ� ���(���� ������ ��ҹ����� �ƽ�Ű �ڵ�� 32 ����)
				if (keys[arr[nx][ny] + 32 - 'a']) {
					opened[arr[nx][ny] - 'A'] = 1;
					visited[nx][ny] = 1;
					arr[nx][ny] = '.';
					re = true;
					q.push({ nx,ny });
				}
			}

			// ���� �߰�
			if (!outOfBound(nx, ny) && arr[nx][ny] == '$' && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				arr[nx][ny] = '.';
				ans++;
				q.push({ nx,ny });
			}
		}
	}

	return re;
}

void q_push() {
	// �����ڸ��� ��ȸ�ϸ� �� �� �ִ� ������ ť�� �ִ´�.

	re = false;
	for (int i = 0;i < h;i++) {
		if (i == 0 || i == h - 1) {
			for (int j = 0;j < w;j++) {
				if (arr[i][j] == '.') {
					visited[i][j] = 1;
					q.push({ i, j});
				}
				else if (arr[i][j] - 'a' >= 0 && arr[i][j] - 'a' <= 25) {
					re = true;
					visited[i][j] = 1;
					keys[arr[i][j] - 'a'] = 1;
					arr[i][j] = '.';
					q.push({ i, j});
				}
				else if (arr[i][j] == '$') {
					arr[i][j] = '.';
					visited[i][j] = 1;
					ans++;
					q.push({ i, j});
				}
				else if (arr[i][j] - 'A' >= 0 && arr[i][j] - 'A' <= 25 && keys[arr[i][j] + 32 - 'a']) {
					re = true;
					arr[i][j] = '.';
					visited[i][j] = 1;
					q.push({ i, j});
				}
			}
		}
		else {
			if (arr[i][0] == '.') {
				visited[i][0] = 1;
				q.push({ i, 0 });
			}
			if (arr[i][w - 1] == '.') {
				visited[i][w - 1] = 1;
				q.push({ i, w - 1 });
			}
			else if (arr[i][0] - 'a' >= 0 && arr[i][0] - 'a' <= 25) {
				re = true;
				arr[i][0] = '.';
				visited[i][0] = 1;
				keys[arr[i][0] - 'a'] = 1;
				q.push({ i, 0 });
			}
			else if (arr[i][0] == '$') {
				visited[i][0] = 1;
				arr[i][0] = '.';
				ans++;
				q.push({ i, 0});
			}
			else if (arr[i][w - 1] - 'a' >= 0 && arr[i][w - 1] - 'a' <= 25) {
				re = true;
				arr[i][w - 1] = '.';
				visited[i][w - 1] = 1;
				keys[arr[i][w - 1]] = 1;
				q.push({ i, w - 1 });
			}
			else if (arr[i][w - 1] == '$') {
				visited[i][w - 1] = 1;
				ans++;
				arr[i][w - 1] = '.';
				q.push({ i, w - 1 });
			}
			else if (arr[i][0] - 'A' >= 0 && arr[i][0] - 'A' <= 25 && keys[arr[i][0] + 32 - 'a']) {
				re = true;
				arr[i][0] = '.';
				visited[i][0] = 1;
				q.push({ i, 0});
			}
			else if (arr[i][w - 1] - 'A' >= 0 && arr[i][w - 1] - 'A' <= 25 && keys[arr[i][w - 1] + 32 - 'a']) {
				re = true;
				arr[i][w - 1] = '.';
				visited[i][w - 1] = 1;
				q.push({ i, w - 1});
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		ans = 0;
		visited_clear();
		keys_opened_clear();

		cin >> h >> w;
		for (int i = 0;i < h;i++) {
			cin >> arr[i];
		}

		string k;
		cin >> k;
		for (int i = 0;i < k.size();i++) {
			if (k[0] == '0')
				break;

			keys[k[i] - 'a'] = 1;
		}

		q_push();
		while (1) {
			if (bfs()) {
				q_push();
			}
			else
				break;
		}

		cout << ans << "\n";
	}
}