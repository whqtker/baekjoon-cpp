#include <iostream>
#include <queue>

using namespace std;

int arr[100001];
int visited[100001];

int main() {
	int n, m;
	cin >> n >> m;
	arr[n] = 1; // ������ ��ġ
	arr[m] = 2; // ���� ��ġ

	queue<pair<int, int>> q;
	q.push({ n,0 });

	int min = 100001; // ���� ��ġ���� ã�� ���� ���� �ð�
	int ans = 0; // ���� ���� �ð����� ã�� Ƚ��
	while (!q.empty()) {
		int x = q.front().first; // ����ġ
		int cnt = q.front().second; // �ɸ� �ð�
		q.pop();

		visited[x] = 1;

		if (arr[x] == 2) {
			if (min >= cnt) {
				min = cnt;
				ans++;
			}
		}

		if (x - 1 >= 0 && !visited[x - 1]) {
			q.push({ x - 1,cnt + 1 });
		}
		if (x + 1 <= 100000 && !visited[x + 1]) {
			q.push({ x + 1,cnt + 1 });
		}
		if (2 * x <= 100000 && !visited[2 * x]) {
			q.push({ 2 * x,cnt + 1 });
		}
	}

	cout << min << "\n" << ans;
}