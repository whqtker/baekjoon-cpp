#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int w, h; // w: ���� ����, h: ���� ����
	int a, b; // �Է¹��� ��
	int r1, r2; // a, b�� 4�� ���� ������

	cin >> a >> b;
	if (a % 4 == 0) r1 = 4;
	else r1 = a % 4;
	if (b % 4 == 0) r2 = 4;
	else r2 = b % 4;

	h = abs(r1 - r2); // ���� ���̴� �Էµ� �� ���� mod���� �����̴�.
	w = abs((a - r1) - (b - r2)) / 4; // ���� ���̴� �������� �� ���� ���� ���� 4�� ���� ���̴�.

	cout << w + h;
}