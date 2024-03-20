#include <iostream>
#include <cmath>

using namespace std;

int n, m;
pair<int, int> clause[100];
int tmp[20];

void bt(int k) {
	if (k == m) {

	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> clause[i].first >> clause[i].second;
	}

	for (int i = 0; i < 20; i++) {
		tmp[i] = -1;
	}

	bt(1);
}