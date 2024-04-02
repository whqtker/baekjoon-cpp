#include <iostream>
#include <vector>

using namespace std;

int arr[4000001]; // 0이면 소수, 1이면 합성수

int main() {
	int n;
	cin >> n;

	for (int i = 2; i * i <= n; i++) {
		if (!arr[i]) {
			for (int j = i * i; j <= n; j++) {
				arr[i] = 1;
			}
		}
	}

	vector<int> v; // 2부터 n까지 소수 저장
	for (int i = 2; i <= n; i++) {
		if (!arr[i])
			v.push_back(i);
	}

	int l = 2, r = 2;
	while (1) {

	}
}