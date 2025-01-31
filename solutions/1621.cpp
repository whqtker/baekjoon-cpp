#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int weight[1000001]; // �ٳ����� ����
int dp[1000001];
int route[1000001]; // ��� ������
// route[i]: i���� �۰ų� ���� �ٳ��� �� ���� ����� �ٳ��� ������ ù ��° �ٳ��� �ε���

int main() {
	int n, k, c; // �ٳ����� ��, �� ���� ��� �� �ִ� ��, �ɸ��� �ð�
	cin >> n >> k >> c;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
	}

	for (int i = 1; i <= n; i++) {
		if (i < k) {
			dp[i] = dp[i - 1] + weight[i];
		}
		else {
			int case1 = dp[i - k] + c; // ���� �ٳ����� ���´ٸ�
			int case2 = weight[i] + dp[i - 1]; // ���� �ٳ��� �ϳ��� ��� ���ٸ�

			if (case1 < case2) {
				dp[i] = case1;
				route[i] = i - k + 1;
			}
			else {
				dp[i] = case2;
				route[i] = route[i - 1];
			}
		}
	}

	cout << dp[n] << "\n";

	stack<int> s;
	int idx = n;
	int cnt = 0;
	while (route[idx] > 0) {
		cnt++;
		s.push(route[idx]);
		idx = route[idx] - 1;
	}

	cout << cnt << "\n";

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}