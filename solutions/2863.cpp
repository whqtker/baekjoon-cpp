#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	double a, b, c, d; // 0ȸ��: a/c+b/d, 1ȸ��: c/d+a/b, 2ȸ��: d/b+c/a, 3ȸ��: b/a+d/c
	cin >> a >> b >> c >> d;

	vector<double> result;
	result.push_back(a / c + b / d);
	result.push_back(c / d + a / b);
	result.push_back(d / b + c / a);
	result.push_back(b / a + d / c);

	int maxIdx = max_element(result.begin(), result.end()) - result.begin(); // �ִ��� �ε����� ���Ѵ�.
	cout << maxIdx;
}