#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, l, d; // n: �뷡 �� ��, l: �� �뷡�� ����, d: ��ȭ���� ����
	cin >> n >> l >> d;

	vector<int> album, ring; // �ٹ��� ��ȭ���� �ð�(�ε���)�� ���� ��ȭ���� ���� �� �ִ���, �Ǵ� ��ȭ���� �︮�� �� ���θ� �����ϴ� ����
	
	// ���� �� ���� �����̰ų� ��ȭ���� �︮�� �ʴ´ٸ� 0, ���� �� �ְų� �︰�ٸ� 1�� �����Ѵ�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			album.push_back(0);
		}
		if (i != n - 1) {
			for (int j = 0; j < 5; j++) {
				album.push_back(1);
			}
		}
	}

	while (1) {
		ring.push_back(1);
		if (ring.size() == album.size()) break;

		// ��ȭ���� �︰ �������� d�� �� �ٽ� �︮�Ƿ� �︮�� �ʴ� �ð��� d - 1���̴�.
		bool flag = true;
		for (int i = 0; i < d - 1; i++) { 
			ring.push_back(0);
			if (ring.size() == album.size()) {
				flag = false;
				break;
			}
		}
		if (flag == false) break;
	}

	int t = -1;
	for (int i = 0; i < album.size(); i++) {
		if (album[i] == 1 && ring[i] == 1) {
			t = i;
			break;
		}
	}

	// t == -1 �̶�� ���� �뷡�� ���� ������ ��ġ�� ������ �����ٴ� ���̴�.
	if (t == -1) {
		int i = 0;
		while (i * d <= album.size() - 1) {
			t = i * d;
			i++;
		}
		t = i * d;
	}

	cout << t;
}