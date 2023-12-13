#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int x = 1;
	for (int i = 0;i < k;i++) {
		x *= n - i;
		x %= 10007;
	}
	for (int i = 0;i < k;i++) {
		x /= k - i;
	}
	cout << x;
}