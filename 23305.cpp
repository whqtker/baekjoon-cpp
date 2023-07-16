#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> current; // 현재 신청한 수업
	vector<int> change; // 교환을 통해 신청하고 싶은 수업

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		current.push_back(k);
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		change.push_back(k);
	}

	// change에 있는 수업이 current에 있으면 원하는 수업을 들을 수 있음.
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (change[i] == current[j]) {
				cnt++;
				current[j] = -1;
				break;
			}
		}
	}

	cout << n - cnt;
}