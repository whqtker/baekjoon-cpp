#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int s;
		cin >> s;

		vector<int> shop;
		int sum = 0;
		for (int j = 0; j < s; j++) {
			int d;
			cin >> d;
			shop.push_back(d);
		}

		// �ִܰŸ��� �׻� ��ǥ�� ���� ū ������ ���� ������ �Ÿ��� �� ���̴�.
		// ���Ը� �� �� � ���Ը� ������ ���� ���� �ִܰŸ��� �ƴϴ�.
		sort(shop.begin(), shop.end());
		cout << (shop[shop.size() - 1] - shop[0]) * 2 << "\n";
	}
}