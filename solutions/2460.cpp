#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> total; // ���� ����� ��
	for (int i = 0; i < 10; i++) {
		int a, b; // a: ���� ���, b: ź ���
		cin >> a >> b;

		if (i == 0)
			total.push_back(b);
		else
			total.push_back(total[i - 1] - a + b);
	}

	cout << *max_element(total.begin(), total.end());
}