#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000000];
vector<int> who; // dp[i]�� �� �� ���� ���� �� ����

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0;i < n;i++) {
		// ���� ���Ұ� LIS�� ������ ���Һ��� �� ŭ
		int lower= lower_bound(who.begin(), who.end(), v[i]) - who.begin();

		if (lower == who.size()) {
			who.push_back(v[i]);
		}
		else {
			who[lower] = v[i];
		}
	}

	cout << who.size();
}