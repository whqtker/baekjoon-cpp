#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<int> last; // �۳� ����
		vector<int> inDegree(501);
		vector<int> lastRank(501); // lastRank[i] = x: i ���� �۳� ������ x
		vector<vector<int>> edge(501, vector<int>(501)); // edge[i][j] = 1: i -> j���� ������ ������

		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			last.push_back(x);
			lastRank[x] = i;
		}

		// �����ϴ� ��� ���� ���� ������ ������ �����Ѵ�. ��, n(n+1)/2���� ������ �����Ѵ�.
		// a -> b: a�� ���� �� ����
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int a = last[i];
				int b = last[j];

				inDegree[b]++;
				edge[a][b] = 1;
			}
		}

		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;

			// ���� ���踦 �����´�.
			if (lastRank[a] < lastRank[b]) {
				inDegree[b]--;
				inDegree[a]++;
				edge[a][b] = 0;
				edge[b][a] = 1;
			}
			else {
				inDegree[a]--;
				inDegree[b]++;
				edge[a][b] = 1;
				edge[b][a] = 0;
			}
		}

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!inDegree[i]) {
				q.push(i);
			}
		}

		vector<int> ans;
		bool impossible = true;
		bool notUniqueAnswer = false;
		while (!q.empty()) {
			// inDegree�� 0�� ��尡 �� �� �̻��̸� ������ �ϳ��� ���� �� ����
			if (q.size() >= 2) {
				notUniqueAnswer = true;
				break;
			}

			int x = q.front();
			q.pop();
			ans.push_back(x);


			for (int i = 1; i <= n; i++) {
				if (edge[x][i]) {
					int y = i;
					inDegree[y]--;

					if (!inDegree[y]) {
						impossible = false;
						q.push(y);
					}
				}
			}
		}

		// ��� ��带 �湮���� ���� ��� ������ ���� �� ����
		if (ans.size() != n) {
			impossible = true;
		}

		if (impossible)
			cout << "IMPOSSIBLE";
		else if (notUniqueAnswer)
			cout << "?";
		else {
			for (int i = 0; i < n; i++) {
				cout << ans[i] << " ";
			}
		}
		cout << "\n";
	}
}