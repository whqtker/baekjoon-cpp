#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m; //������ n���� ��, ��Ÿ�� �귣�� m��, m���� ��Ű��(6���� �������) ���ݰ� ���� ������ �־�����.
	cin >> n >> m;

	vector<int> bundle;
	vector<int> piece;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		bundle.push_back(x);
		piece.push_back(y);
	}

	//���� * 6 ������ ��Ű�� ���ݺ��� �ΰų� ���� ���
	if (*min_element(bundle.begin(), bundle.end()) >= *min_element(piece.begin(), piece.end()) * 6) {
		cout << *min_element(piece.begin(), piece.end()) * n;
	}
	else {
		cout << *min_element(bundle.begin(), bundle.end()) * (n / 6) + min(*min_element(piece.begin(), piece.end()) * (n % 6), *min_element(bundle.begin(), bundle.end()));
	}
}