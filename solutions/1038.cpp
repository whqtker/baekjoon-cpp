#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; // n��°�� �����ϴ� �� ���
	cin >> n;

	vector<int> v(1);
	int digit = 0; // v�� �ڸ����� digit + 1, digit�� v�� ���� ���� �ڸ����� �ε����� ������
	int ret = 0;
	while (n != ret) {
		// ���� 1��ŭ ������Ŵ
		// ��, ������ ��� ���Ұ� 9�̸� �ڸ����� �������Ѿ� ��. ex) 9 -> 10, 999 -> 1000
		vector<int> isNine(digit + 1, 9);
		if (v == isNine) {
			digit++;
			v = vector<int>(digit + 1, 0);
			v[0] = 1;
		}
		else {
			v[digit]++;
			// 19 -> 20�� �Ǿ� ��
			if (v[digit] == 10) {

			}
		}

		vector<int> sorted = v;
		sort(sorted.rbegin(), sorted.rend()); // �������� ����
		sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // 11 ���� ���� �����ϴ� ���� �ƴϴ�.
		if (v == sorted) {
			ret++;
		}
	}

	cout << ret;
}