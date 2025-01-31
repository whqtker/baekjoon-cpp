#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void postorder(int s, int e) {
	if (s >= e)
		return;

	// ����Ʈ���� ���� ��� ���
	if (s == e - 1) {
		cout << v[s] << "\n";
		return;
	}

	int i = s + 1;
	// ��Ʈ ��庸�� �� ū ���� �ε����� ã�´�.
	while (i < e) {
		if (v[s] < v[i])
			break;
		i++;
	}

	// ���� ����Ʈ�� ��ȸ
	postorder(s + 1, i);

	// ������ ����Ʈ�� ��ȸ
	postorder(i, e);

	// ����Ʈ���� ��Ʈ ��� ���
	cout << v[s] << "\n";
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	while (cin >> n) {
		v.push_back(n);
	}

	// ��Ʈ ��庸�� ���� ������ ���� ����Ʈ��, ū ������ ������ ����Ʈ���̴�.
	postorder(0, v.size());
}