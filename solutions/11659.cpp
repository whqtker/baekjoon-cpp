#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	
	vector<int> v; // ���� ���� �����ϴ� ����, v[i]: 1�� °���� i�� °���� ������ ��
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x + v[i]);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << v[b] - v[a - 1] << "\n";
	}
}