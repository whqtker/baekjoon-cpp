#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	double l; // ġŲ�� ��, �ü��� ����
	cin >> n >> l;

	vector<double> d; // ġŲ�� �Ÿ�
	double WX = 0;
	double W = 0;
	for (int i = 0; i < n; i++) {
		double x;
		cin >> x;
		d.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		double x;
		cin >> x;
		W += x;
		WX += d[i] * x;
	}

	cout << fixed;
	cout.precision(6);
	cout << WX / W;
}