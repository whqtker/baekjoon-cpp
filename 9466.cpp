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
		for (int j = 1; j <= n; j++) {
			stack<int> s;
			s.push(j);

			vector<int> visited(n + 1);
			visited[j] = 1;

			bool flag = false;
			while (!s.empty()) {
				int x = s.top();
				int target = v[x];
				s.pop();

				// 짝지어진 경우
				if (j == target) {
					flag = true;
					break;
				}

				// 무한루프에 빠져 팀이 만들어질 수 없는 경우
				if (x == target)
					break;

				// 팀을 찾는 과정
				if (!visited[target]) {
					s.push(target);
					visited[target] = 1;
				}
			}

			if (!flag)
				cnt++;
		}

		cout << cnt << "\n";
	}
}