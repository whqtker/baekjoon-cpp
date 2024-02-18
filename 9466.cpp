#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<int> v;
		v.push_back(0); // 인덱스 보정
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		int cnt = 0;
		vector<int> team(n + 1);
		for (int j = 1; j <= n; j++) {
			stack<int> s;
			s.push(j);

			vector<int> visited(n + 1);
			visited[j] = 1;

			while (!s.empty()) {
				int x = s.top();
				int target = v[x];
				s.pop();

				// 팀을 찾는 과정
				if (!visited[target]) {
					s.push(target);
					visited[target] = 1;
				}
				else if (visited[target] && !team[target]) {
					cnt++;
					break;
				}
			}
		}

		cout << cnt << "\n";
	}
}