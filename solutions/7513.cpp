#include <iostream>
#include <vector>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0;i < testCase;i++) {
		cout << "Scenario #" << i + 1 << ":" << "\n";
		int n; // �ܾ��� ����
		cin >> n;

		vector<string> words;
		for (int j = 0;j < n;j++) {
			string str;
			cin >> str;
			words.push_back(str);
		}

		int m; // ����� ��
		cin >> m;

		for (int j = 0;j < m;j++) {
			int cnt; // ���Ǵ� �ܾ��� ��
			cin >> cnt;

			for (int k = 0;k < cnt;k++) {
				int idx;
				cin >> idx;
				cout << words[idx];
			}
			cout << "\n";
		}
		cout << "\n";
	}
}