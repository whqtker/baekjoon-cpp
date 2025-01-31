#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, m; // n���� ����� ����Ʈ, m���� ã������ ����Ʈ
	cin >> n >> m;
	map<string, string> site;

	for (int i = 0; i < n; i++) {
		string s, pw;
		cin >> s >> pw;
		site[s] = pw;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		cout << site.find(s)->second << "\n";
	}
}