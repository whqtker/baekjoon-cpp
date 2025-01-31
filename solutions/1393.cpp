#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b; // ������ ��ǥ
	cin >> a >> b;

	double m, n, dx, dy; // ���� ��ġ �� x, y ������
	cin >> m >> n >> dx >> dy;

	// ������ �̵� ��ΰ� x��� ������ ���
	if (dx == 0) {
		// ���� �̵� ���⿡ �������� ���� ���
		if (dy * (b - n) < 0)
			cout << m << " " << n;
		else
			cout << m << " " << b;
	}

	// ���� �̵� ���⿡ �������� ���� ��� 
	else if (dx * (a - m) < 0 || dy * (b - n) < 0) {
		cout << m << " " << n;
	}
	else {
		double k = dy / dx; // ����
		int x = (a + b * k + pow(k, 2) * m - n * k) / (pow(k, 2) + 1);
		int y = k * (x - m) + n;
		cout << x << " " << y;
	}
}