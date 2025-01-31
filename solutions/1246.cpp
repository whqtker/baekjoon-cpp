#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m; // n���� �ް�, m���� ��
	cin >> n >> m;

	vector<int> cost; // ���� ����ϴ� �ް��� ����. �ް��� ������ cost�� ���Һ��� �۰ų� ������ ����.
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cost.push_back(x);
	}

	// �Ǹ� ������ �ִ밡 �Ǵ� ���� ���� ��� ���ݰ� ������ �� ������.
	sort(cost.begin(), cost.end());

	vector<int> sell;
	for (int i = 0; i < m; i++) {
		if (n < m - i) {
			int s = cost[i] * n;
			sell.push_back(s);
		}
		else {
			int s = cost[i] * (m - i);
			sell.push_back(s);
		}
	}

	cout << cost[max_element(sell.begin(), sell.end()) - sell.begin()] << " " << *max_element(sell.begin(), sell.end());
}