#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, b;
	cin >> n >> m >> b;
	vector<int> coor;
	for (int i = 0; i < n * m; i++) {
		int x;
		cin >> x;
		coor.push_back(x);
	}

	vector<int> h = coor; // h: �Է¹��� ���̸� �����ϰ� �ߺ����� ������ ���� �������
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());

	vector<int> time; // �ɸ� �ð��� �����ϴ� ����
	sort(coor.rbegin(), coor.rend()); // ������������ �����Ѵ�. ���̰� ���� ��Ϻ��� �����ؾ� ���� ����� ì�� �� �ִ�.
	for (int i = h[0]; i <= h[h.size() - 1]; i++) {
		int inventory = b; // ���� �κ��丮�� �ִ� ���
		int cnt = 0; // ����� �״� �� ����� Ƚ��
		int t = 0; // �ɸ� �ð�
		for (int j = 0; j < coor.size(); j++) {
			// ��ǥ ���̰� ���� ���̺��� Ŭ �� - ����� �״´�.
			if (i > coor[j]) {
				// ���� ���� ����� ���� ��
				if (i - coor[j] > inventory - cnt) {
					t = -1;
					break;
				}
				else {
					t += i - coor[j];
					cnt += i - coor[j];
				}
			}
			// ��ǥ ���̰� ���� ���̺��� ���� ��  - ����� �����Ѵ�.
			else if (i < coor[j]) {
				t += 2 * (coor[j] - i);
				inventory += coor[j] - i;
			}
		}
		time.push_back(t); // t�� -1�� ��� ���� �� ���� ����̴�(���� ����� ������ ���).
	}

	int min = time[0];
	int minIdx = 0;
	for (int i = 0; i < time.size(); i++) {
		if (time[i] != -1 && min >= time[i]) {
			min = time[i];
			minIdx = i;
		}
	}

	cout << min << " " << h[0] + minIdx;
}