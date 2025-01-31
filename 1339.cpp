#include <iostream>
#include <map>
#include <string>

using namespace std;

string arr[10];

int main() {
	int n;
	cin >> n;

	map<char, int> m; // m[X] = y: ���ĺ� X�� ����ġ�� y

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr[i] = s;

		int digit = 1;
		for (int i = s.length() - 1; i >= 0; i--) {
			m[s[i]] += digit;
			digit *= 10;
		}
	}

	multimap<int, char, greater<int>> m_rev; // m_rev[y] = X: ����ġ y�� �ش��ϴ� ���ĺ��� X
	for (auto iter : m) {
		m_rev.insert({ iter.second,iter.first });
	}

	map<char, int> match; // match[X] = y: ���ĺ� X�� �����ϴ� ���ڴ� y
	int num = 9;
	for (auto iter : m_rev) {
		match[iter.second] = num;
		num--;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].length(); j++) {
			arr[i][j] = match[arr[i][j]] + '0';
		}

		ans += stoi(arr[i]);
	}

	cout << ans;
}