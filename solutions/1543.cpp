#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	string find;
	getline(cin, find);

	int cnt = 0;
	int idx = 0;
	while (str.find(find, idx) != string::npos) {
		// find()�� ã�� ���ҵ��� ù ��° �ε����� ��ȯ��.
		idx = str.find(find, idx) + find.length();
		cnt++;
	}

	cout << cnt;
}