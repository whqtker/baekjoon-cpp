#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<string>> info(201); // �ε����� ���̸� �ǹ��ϰ� ���Ҵ� �̸��̴�.
	for (int i = 0; i < n; i++) {
		int age;
		cin >> age;
		string name;
		cin >> name;
		info[age].push_back(name);
	}

	for (int i = 0; i < info.size(); i++) {
		if (info[i].size() != 0) {
			for (int j = 0; j < info[i].size(); j++) {
				cout << i << " " << info[i][j] << "\n";
			}
		}
	}
}