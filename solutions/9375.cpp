#include <iostream>
#include <map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		multimap<string, string> mm;
		map<string, string>m; // �ߺ��� ���ŵ� key��(���� ����)�� ����
		for (int j = 0; j < n; j++) {
			string name;
			string type;
			cin >> name >> type;
			m[type] = name;
			mm.insert({ type,name });
		}

		int cnt = 1;
		for (auto it : m) {
			cnt *= (mm.count(it.first) + 1);
		}
		cout << cnt - 1 << "\n"; // �� �Դ� ��� ����
	}
}