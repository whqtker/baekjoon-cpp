#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int arr[20][20];
int visited[20][20];
int n;

void clear() {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			visited[i][j] = 0;
		}
	}
}

int main() {
	cin >> n;

	int sx, sy; // ����� ��ġ
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 9) {
				sx = i;
				sy = j;
				arr[i][j] = 0;
			}
		}
	}

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	queue<tuple<int, int, int, int>> q; // {����� x��ǥ, ����� y��ǥ, �ɸ� �ð�, ����� ũ��}
	q.push({ sx,sy,0,2 });

	int cnt = 0; // ���� ������� ��
	while (!q.empty()) {
		clear();

		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int t = get<2>(q.front());
		int s = get<3>(q.front());
		q.pop();

		queue<tuple<int, int, int>> fish; // {������� x��ǥ, ������� y��ǥ, �ɸ� �ð�}
		fish.push({ x,y,0 });
		visited[x][y] = 1;

		int d = 400; // ���� ����� ������� �Ÿ�
		int w = 0; // ���ǿ� �´� ������� ����
		int fX = 0; // ���ǿ� �´� ������� x��ǥ
		int fY = 0; // ���ǿ� �´� ������� y��ǥ
		bool flag = false; // ���ǿ� �´� ����Ⱑ �����ϴ���
		while (!fish.empty()) {
			int curX = get<0>(fish.front());
			int curY = get<1>(fish.front());
			int curT = get<2>(fish.front());
			fish.pop();

			for (int i = 0;i < 4;i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];

				if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
					// �� ĭ�̰ų� ������� ���԰� ���� ��� ������ �� ����
					if (arr[nx][ny] == 0 || arr[nx][ny] == s) {
						visited[nx][ny] = 1;
						fish.push({ nx,ny,curT + 1 });
					}
					// ����Ⱑ �ִ� ĭ�̸� ����� ���Ժ��� ���� ���
					else if (arr[nx][ny] > 0 && arr[nx][ny] < 7 && s > arr[nx][ny]) {
						flag = true;
						// �ִ� �Ÿ��� ���
						if (curT + 1 < d) {
							d = curT + 1;
							w = arr[nx][ny];
							fX = nx;
							fY = ny;

							visited[nx][ny] = 1;
							fish.push({ nx,ny,curT + 1 });
						}
						// �Ÿ��� ���� ���
						else if (curT + 1 == d) {
							// ���� ����Ⱑ �� ���� �ִ� ���
							if (fX > nx) {
								w = arr[nx][ny];
								fX = nx;
								fY = ny;

								visited[nx][ny] = 1;
								fish.push({ nx,ny,curT + 1 });
							}
							// ���� ����Ⱑ �� ���ʿ� �ִ� ���
							else if (fX == nx) {
								if (fY > ny) {
									w = arr[nx][ny];
									fX = nx;
									fY = ny;

									visited[nx][ny] = 1;
									fish.push({ nx,ny,curT + 1 });
								}
							}
						}
					}
				}
			}
		}

		// ���� �� �ִ� ����Ⱑ ���� ���
		if (!flag) {
			cout << t;
			break;
		}

		// ����⸦ �Դ´�.
		arr[fX][fY] = 0;
		x = fX;
		y = fY;
		cnt++;
		// �� �ڽ��� ũ��� ���� ���� ����⸦ ���� ��� ũ�Ⱑ 1 ����
		if (cnt == s) {
			s++;
			cnt = 0;
		}
		t += d;
		q.push({ x,y,t,s });
	}
}