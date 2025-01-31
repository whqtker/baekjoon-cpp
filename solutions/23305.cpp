#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> lec(1000001); // ���� ��ȣ�� �� �ε�����.

	// �ε���(���� ��ȣ)�� �ش��ϴ� ���� ������ ������ �ִ� �л��� ���� ��.
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		lec[a]++;
	}

	// ��ȯ�� ���� ������ ������ ������ 1�� ����. ���� 0�̶�� ��ȯ �Ұ�.
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		if (lec[b] >= 1)
			lec[b] -= 1;
		else
			cnt++;
	}

	cout << cnt;
}