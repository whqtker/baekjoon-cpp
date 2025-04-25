#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	vector<int> cnt(n + 1); // cnt[i]: i�� ° ������� Ű�� ū ����� ��ġ�� ��

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cnt[j] == v[j]) {
				cout << j << " ";
				cnt[j] = -1; // �̹� ��ġ�Ǿ����� ǥ��

				for (int k = 1; k < j; k++) {
					if (cnt[k] >= 0)
						cnt[k]++;
				}

				break;
			}
		}
	}
}