#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	int digit = 0;
	while (1) {
		if (n / pow(10, digit) > 9) {
			int x = (n % (int)pow(10, digit + 1)) / (int)pow(10, digit); // 반올림을 진행할 수
			if (x >= 5) {
				n = (n / (int)pow(10, digit + 1) + 1) * pow(10, digit + 1);
			}
			else {
				n = n / (int)pow(10, digit + 1) * pow(10, digit + 1);
			}
			digit++;
		}
		else break;
	}
	cout << n;
}