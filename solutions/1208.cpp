#include <iostream>

using namespace std;

int n, s;
long long ans;
int arr[40];
int visited[40];

// 배열에 접근하는 인덱스는 y보다 같거나 커야 함
void dfs(int x, int y) {
	if (x > n) {
		return;
	}

	if (x != 0) {
		int sum = 0;
		for (int i = 0;i < n;i++) {
			if (visited[i])
				sum += arr[i];
		}
		if (sum == s) {
			ans++;
		}
	}

	for (int i = y;i < n;i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(x + 1, i + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> s;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	dfs(0, 0);
	cout << ans;
}