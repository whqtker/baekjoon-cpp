#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int n, m; // n: �赵 ���� ��� ��, m: ���� ���� ��� ��
	cin >> n >> m;

	map<string, int> m1; // �赵 ���� ��� ����
	map<string, int> m2; // ���� ���� ��� ����
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		m1.insert({ s, i });
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		m2.insert({ s, i });
	}

	vector<string> v; // �赵 ���� ���� ��� ����
	for (auto it : m1) {
		if (m2.find(it.first) != m2.end()) {
			v.push_back(it.first);
		}
	}
	
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}