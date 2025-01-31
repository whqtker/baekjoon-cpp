#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// upper_bound: ã������ ������ ū ���� iter�� ��ȯ��.
	// lower_bound: ã������ ���� ���ų� ū ���� iter�� ��ȯ��.
	// ��, ������������ ���ĵǾ�� �Ѵ�.

	vector<int> card;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		card.push_back(x);
	}

	sort(card.begin(), card.end());

	vector<int> find;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		find.push_back(x);
	}

	// a �̻� b ������ ���� ������ ���ϴ� �ڵ�� ������ ���� �ۼ��Ѵ�.
	// upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a)
	for (int i = 0; i < m; i++) {
		cout << upper_bound(card.begin(), card.end(), find[i]) - lower_bound(card.begin(), card.end(), find[i]) << " ";
	}
}