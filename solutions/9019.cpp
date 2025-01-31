#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int a, b;
		cin >> a >> b;

		queue<pair<int, string>> q; // { ���� ����, ��ɾ� ���� }
		q.push({ a,"" });
		int visited[10000] = {};
		visited[a] = 1;

		while (!q.empty()) {
			int num = q.front().first;
			string cmd = q.front().second;

			q.pop();

			// ���ڰ� ��ġ�ϸ� ��ɾ� ���
			if (num == b) {
				cout << cmd << "\n";
				break;
			}

			// ��� ����
			// ���� ����� R�̸� L�� �����ϸ� �� �ȴ�. ���� ����� L�̸� R�� �����ϸ� �� �ȴ�.
			// D
			int tar = (num * 2) % 10000;
			if (!visited[tar]) {
				visited[tar] = 1;
				q.push({ tar,cmd + 'D' });
			}

			// S
			tar = num - 1;
			if (tar < 0) tar = 9999;

			if (!visited[tar]) {
				visited[tar] = 1;
				q.push({ tar,cmd + 'S' });
			}

			// L
			tar = num / 1000 + (num % 1000) * 10;
			if (!visited[tar]) {
				visited[tar] = 1;
				q.push({ tar,cmd + 'L' });
			}


			// R
			tar = num / 10 + (num % 10) * 1000;
			if (!visited[tar]) {
				visited[tar] = 1;
				q.push({ tar,cmd + 'R' });
			}

		}
	}
}