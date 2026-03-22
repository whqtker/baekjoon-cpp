#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, k; // 트랙의 길이, 심판의 수, 지정 공간의 수
	cin >> n >> m >> k;

	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}

	int l = 1; // 심판 간 최소 거리
	int r = v[k - 1] - v[0]; // 심판 간 최대 거리
	string ans = "";

	while (l <= r) {
		int mid = (l + r) / 2; // 현재 loop의 심판 간 거리

		int x = v[0];
		int cnt = 1; // 배치된 심판의 수
		string cur_ans = "1";
		for (int i = 1; i < k; i++) {
			// 심판을 배치할 수 있는 경우만 처리
			if (v[i] - x >= mid && cnt < m) {
				cnt++;
				x = v[i];
				cur_ans += "1";
			}
			else
				cur_ans += "0";
		}

		// 심판이 옳게 배치된 경우 최소 거리를 늘리고 정답 갱신
		// 최소 거리 증가(더 적합한 답이 있는지 탐색)
		if (cnt == m) {
			l = mid + 1;
			ans = cur_ans;
		}
		// 심판이 너무 적게 배치된 경우 최대 거리를 줄인다.
		else {
			r = mid - 1;
		}
	}

	cout << ans;
}