#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n * n);
	for (int i = 0;i < n * n;i++) {
		cin >> v[i];
	}

	// v�� ������ ���Ұ� A�� �������� ���� �� �ִ�. 4=2*2
	// A={2,3,4}��� M={4,6,8,6,9,12,8,12,16}
	// M�� ���� �۰ų� ū ������ �������� A�� �ݵ�� ���Եȴ�.
	// A={2,2,3}��� M={4,4,6,4,4,6,6,6,9}
}