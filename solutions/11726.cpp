#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	// ��ȭ���� �ĺ���ġ ������ �����ϴ�.
	vector<int> v;
	v.push_back(0); // �ε����� n�� ���߱� ���� ��
	v.push_back(1);
	v.push_back(2);

	for (int i = 3; i <= n; i++)
		v.push_back((v[i - 1] + v[i - 2]) % 10007);
	cout << v[n];
}