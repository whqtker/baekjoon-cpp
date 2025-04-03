#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, k; // Ʈ���� ����, ������ ��, ���� ������ ��
	cin >> n >> m >> k;

	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}

	int l = 1; // ���� �� �ּ� �Ÿ�
	int r = v[k - 1] - v[0]; // ���� �� �ִ� �Ÿ�
	string ans = "";

	while (l <= r) {
		int mid = (l + r) / 2; // ���� loop�� ���� �� �Ÿ�

		int x = v[0];
		int cnt = 1; // ��ġ�� ������ ��
		string cur_ans = "1";
		for (int i = 1; i < k; i++) {
			// ������ ��ġ�� �� �ִ� ��츸 ó��
			if (v[i] - x >= mid && cnt < m) {
				cnt++;
				x = v[i];
				cur_ans += "1";
			}
			else
				cur_ans += "0";
		}

		// ������ �ǰ� ��ġ�� ��� �ּ� �Ÿ��� �ø��� ���� ����
		// �ּ� �Ÿ� ����(�� ������ ���� �ִ��� Ž��)
		if (cnt == m) {
			l = mid + 1;
			ans = cur_ans;
		}
		// ������ �ʹ� ���� ��ġ�� ��� �ִ� �Ÿ��� ���δ�.
		else {
			r = mid - 1;
		}
	}

	cout << ans;
}