#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000][1000];

int main() {
	int r, c, n;
	cin >> r >> c >> n;
	vector<int> v;
	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.rbegin(), v.rend());

	int cnt = 0;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (i * c + j < n) {
				if (i == 0) {
					arr[i][j] = v[i * c + j];
					cnt++;
				}
				else {
					if (arr[i - 1][j] > v[i * c + j]) {
						arr[i][j] = v[i * c + j];
						cnt++;
					}
				}
			}
		}
	}

	cout << cnt;
}