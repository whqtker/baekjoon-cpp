#include <iostream>
#include <vector>

using namespace std;

int parent[51];
vector<vector<int>> party(50, vector<int>(50));

int find_parent(int x) {
	if (x != parent[x]) {
		return parent[x] = find_parent(parent[x]);
	}
	return x;
}

void merge(int x, int y) {
	int px = find_parent(parent[x]);
	int py = find_parent(parent[y]);

	if (px != py) {
		if (px < py)
			parent[py] = parent[px];
		else
			parent[px] = parent[py];
	}
}

int main() {
	int n, m; // ����� ��, ��Ƽ�� ��
	cin >> n >> m;

	// �θ� ��� �ʱ�ȭ
	for (int i = 1;i <= n;i++) {
		parent[i] = i;
	}

	int k; // ������ �ƴ� ����� ��
	cin >> k;
	for (int i = 0;i < k;i++) {
		int x;
		cin >> x;
		parent[x] = 0; // ������ �ƴ� ����� �θ� ���� 0���� ����
	}

	for (int i = 0;i < m;i++) {
		int num; // ��Ƽ�� �����ϴ� ����� ��
		cin >> num;

		for (int j = 0;j < num;j++) {
			int x;
			cin >> x;
			party[i][j] = x;

			if (j > 0)
				merge(party[i][0], x);
		}
	}

	int ans = m;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < party[i].size();j++) {
			if (party[i][j] == 0)
				break;

			if (find_parent(parent[party[i][j]]) == 0) {
				ans--;
				break;
			}
		}
	}

	cout << ans;
}