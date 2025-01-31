#include <iostream>

using namespace std;

int arr[100001];
int visited[100001]; // 0: �湮X, 1: �� ���� ����, -1: �� ���� �Ұ���
int n, start;

void dfs(int i) {
	// ��ȯ: x���� ����, y�� ��ȯ�� ���� => x���� y ������ visited�� -1�� ����
	// �� x�� y�� ���� ��� pass
	// ��ȯ �߻� ����: �����Ϸ��� �ϴ� ����� �̹� �湮��(y) ���

	if (visited[i]) {
		if (i == start)
			return;
		while (start != i) {
			visited[start] = -1;
			start = arr[start];
		}
		return;
	}

	visited[i] = 1;
	dfs(arr[i]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> arr[i];
		}

		for (int i = 1;i <= n;i++) {
			start = i;
			if (visited[i] == 0) {
				dfs(i);
			}
		}

		int cnt = 0;
		for (int i = 1;i <= n;i++) {
			if (visited[i] != 1)
				cnt++;
			visited[i] = 0;
		}

		cout << cnt << "\n";
	}
}