#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m; // n���� ����, m�� ° ������ ã�� ����(�� ������ 0�� °)
		cin >> n >> m;

		queue<pair<int, int>> q; // ������ ť, pair�� �ε���, �߿䵵�̴�.
		vector<int> v; // �߿䵵�� �����ϴ� ����
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			v.push_back(x);
			q.push(pair<int, int>(j, x));
		}

		sort(v.rbegin(), v.rend());
		int max = v[0]; // ���� ū �߿䵵
		int cnt = 0; // �μ�� ������ ��
		while (1) {
			// q.front()�� �߿䵵�� ���� ũ�� ã���� �ϴ� �ε������ �μ��Ѵ�.
			if (q.front().second == max && q.front().first == m) {
				cout << cnt + 1 << "\n";
				break;
			}
			// q.front()�� �߿䵵�� ���� ũ�ٸ� �μ��Ѵ�.
			else if (q.front().second == max) {
				q.pop();
				cnt++;

				// �ִ� ����
				v.erase(v.begin());
				max = v[0];
			}
			else {
				q.push(q.front());
				q.pop();
			}

		}
	}
}