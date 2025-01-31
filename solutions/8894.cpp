#include <iostream>

using namespace std;

int arr[10][10];

int main() {
	int T;
	cin >> T;
	while (--T) {
		// 간선의 수
		int e;
		cin >> e;
		
		for (int i = 0;i < e;i++) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
			arr[b][a] = 1;
		}

		for (int i = 1;i <= 9;i++) {
			for (int j = 1;j <= 9;j++) {
				if (arr[i][j] == 1) {

				}
			}
		}
	}
}