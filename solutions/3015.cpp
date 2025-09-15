#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	long long ans = 0;
	stack<pair<int, int>> s; // {Ű, ���� Ű�� ���� ����� ��}
	for (int i = 0; i < n; i++) {
		// ���� ����� ���κ��� Ű�� ���� ����� �ִ��� Ȯ���Ͽ� ���� �̷��.
		while (!s.empty() && s.top().first < v[i]) {
			ans += s.top().second;
			s.pop();
		}

		// ���� ����� ���� ������ ���ÿ� �����Ѵ�.
		// ���� ����� ���� ������ �����ϴ� ���
		if (!s.empty() && s.top().first == v[i]) {
			ans += s.top().second; // Ű�� ���� ����鳢���� ��
			int cnt = s.top().second;
			s.pop();

			if (!s.empty()) ans++; // ���ÿ� �����ϴ� �� ū ������� ��
			s.push({ v[i], cnt + 1 });
		}
		// ���� ����� ���� ������ �������� �ʴ� ���
		else {
			if (!s.empty()) ans++;
			s.push({ v[i], 1 });
		}
	}

	cout << ans;
}