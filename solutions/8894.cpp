#include <iostream>
#include <vector>

using namespace std;

// arr[x][y] = 1: x�� y ���̿� ������ ����(x, y�� ����)
// arr[x][y] = 2: x�� y ���̿� ������ ����(x, y�� ���� X)
int arr[10][10];
int between[10][10]; // conn[x][y] = z: ���� (x, y) ���̿� �ִ� ���� z
int nodeVisited[10];
int edgeVisited[10][10];
vector<int> ans;
bool findAnswer = false; // ���� ã�Ҵ���
int e; // ������ ��
int adjacentEdgeCnt = 0; // ���� ������ ��

void init() {
	adjacentEdgeCnt = 0;
	findAnswer = false;
	ans.clear();
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			arr[i][j] = 0;
			edgeVisited[i][j] = 0;
		}
		nodeVisited[i] = 0;
	}
}

// n: ������ ������ ��, prev: ������ �湮�� ����
void dfs(int n, int prev) {
	// ���� ã�� ���
	if (findAnswer)
		return;

	// ��� ������ �湮�� ���
	if (n == adjacentEdgeCnt) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		findAnswer = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		// (prev, i) ������ �����ϰ�, ������ ���
		if (arr[prev][i] == 1) {
			// i�� �湮���� ���� ��� ���� ����
			if (!nodeVisited[i]) {
				nodeVisited[i] = 1;
				edgeVisited[prev][i] = 1;
				edgeVisited[i][prev] = 1;
				ans.push_back(i);

				dfs(n + 1, i);

				nodeVisited[i] = 0;
				edgeVisited[prev][i] = 0;
				edgeVisited[i][prev] = 0;
				ans.pop_back();
			}
		}
		// (prev, i) ������ �����ϰ�, �������� �ʴ� ���
		else if (arr[prev][i] == 2) {
			// i�� �湮���� �ʾҰ� �߰� ������ �湮�� ��� ���� ����
			int mid = between[prev][i];
			if (!nodeVisited[i] && nodeVisited[mid]) {
				nodeVisited[i] = 1;
				edgeVisited[prev][i] = 1;
				edgeVisited[i][prev] = 1;
				ans.push_back(i);

				// (prev, mid) ������ �湮�� ��� 1�� ������ �湮�� ������ ����
				if (edgeVisited[prev][mid]) {
					edgeVisited[mid][i] = 1;
					edgeVisited[i][mid] = 1;

					dfs(n + 1, i);

					edgeVisited[mid][i] = 0;
					edgeVisited[i][mid] = 0;
				}
				// �׷��� ���� ��� 2�� ������ �湮�� ������ ����
				else {
					edgeVisited[mid][i] = 1;
					edgeVisited[i][mid] = 1;
					edgeVisited[prev][mid] = 1;
					edgeVisited[mid][prev] = 1;

					dfs(n + 2, i);

					edgeVisited[mid][i] = 0;
					edgeVisited[i][mid] = 0;
					edgeVisited[prev][mid] = 0;
					edgeVisited[mid][prev] = 0;
				}

				nodeVisited[i] = 0;
				edgeVisited[prev][i] = 0;
				edgeVisited[i][prev] = 0;
				ans.pop_back();
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	between[1][3] = 2;
	between[1][7] = 4;
	between[1][9] = 5;
	between[2][8] = 5;
	between[3][7] = 5;
	between[3][9] = 6;
	between[4][6] = 5;
	between[7][9] = 8;

	between[3][1] = 2;
	between[7][1] = 4;
	between[9][1] = 5;
	between[8][2] = 5;
	between[7][3] = 5;
	between[9][3] = 6;
	between[6][4] = 5;
	between[9][7] = 8;

	while (T--) {
		init();

		cin >> e;

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
			arr[b][a] = 1;
		}

		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				for (int k = 1; k <= 9; k++) {
					// (x, y), (y, z) ������ ������ �� (x, z) ���� �߰�
					if (arr[i][j] && arr[j][k] && between[i][k] == j) {
						arr[i][k] = 2;
						arr[k][i] = 2;
					}

					// ������ �Է¹��� ���� (x, y)�� �߰� ��尡 �ִ� ���
					else if (arr[i][j] == 1 && between[i][j]) {
						int mid = between[i][j];
						arr[i][j] = 2;
						arr[j][i] = 2;
						arr[i][mid] = 1;
						arr[mid][i] = 1;
						arr[mid][j] = 1;
						arr[j][mid] = 1;
					}
				}
			}
		}

		for (int i = 1; i <= 9; i++) {
			for (int j = i + 1; j <= 9; j++) {
				if (arr[i][j] == 1)
					adjacentEdgeCnt++;
			}
		}

		for (int i = 1; i <= 9; i++) {
			nodeVisited[i] = 1;
			ans.push_back(i);
			dfs(0, i);
			nodeVisited[i] = 0;
			ans.pop_back();
		}

		// ���� ã�� ���� ���
		if (!findAnswer)
			cout << "IMPOSSIBLE\n";
	}
}