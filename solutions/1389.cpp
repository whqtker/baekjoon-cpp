#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 5000)); // ģ��, �ɺ� �������� ���� 5000 �̻��� �� �� ����.
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}

	// ���ΰ� ������ ����� 0���� �ʱ�ȭ�Ѵ�.
	for (int i = 1;i <= n;i++) {
		v[i][i] = 0;
	}

	// �÷��̵�-���� �˰���
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= n;k++) {
				v[j][k] = min(v[j][k], v[j][i] + v[i][k]);

			}
		}
	}

	vector<int> sum;
	for (int i = 1;i <= n;i++) {
		int tmp = 0;
		for (int j = 1;j <= n;j++) {
			tmp += v[i][j];
		} 
		sum.push_back(tmp);
	}

	cout << min_element(sum.begin(), sum.end()) - sum.begin() + 1;
}