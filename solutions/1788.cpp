#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

const int SIZE = 2000001;
const int MOD = 1000000000;
int arr[SIZE];

int main() {
	// arr[0]�� n = -1000000�� �Ǻ���ġ ��, arr[2000000]�� n = 1000000�� �Ǻ���ġ ���̴�.
	memset(arr, 0, sizeof(int) * SIZE);
	int n;
	cin >> n;

	// ���� ���� ����
	arr[1000000] = 0;
	arr[1000001] = 1;

	int idx = n + 1000000;
	if (idx > 1000001) {
		int tmp = 1000002;
		while (tmp <= idx) {
			arr[tmp] = (arr[tmp - 1] + arr[tmp - 2]) % MOD;
			tmp++;
		}
	}
	else if (idx < 1000000) {
		int tmp = 999999;
		while (tmp >= idx) {
			arr[tmp] = (arr[tmp + 2] - arr[tmp + 1]) % MOD;
			tmp--;
		}
	}

	int sign = 0;
	if (arr[idx] < 0)
		sign = -1;
	else if (arr[idx] > 0)
		sign = 1;

	cout << sign << "\n";
	cout << abs(arr[idx]);
}