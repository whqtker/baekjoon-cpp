#include <iostream>

#define MAX 5003

using namespace std;

int arr[MAX][MAX]; // imos ������ ����

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b, x;
		cin >> a >> b >> x;
		arr[a][b]++;
		arr[a][b + 1]--;
		arr[a + x + 1][b + x + 2]++;
		arr[a + x + 1][b]--;
		arr[a + x + 2][b + 1]++;
		arr[a + x + 2][b + x + 2]--;
	}

	// ���ﰢ���� ���� imos�� ����
	// ����������
	for (int i = 1;i < MAX;i++) {
		for (int j = 2;j < MAX;j++) {
			arr[i][j] += arr[i][j - 1];
		}
	}
	// �Ʒ�������
	for (int i = 2;i < MAX;i++) {
		for (int j = 1;j < MAX;j++) {
			arr[i][j] += arr[i - 1][j];
		}
	}
	// �밢��������
	for (int i = 2;i < MAX;i++) {
		for (int j = 2;j < MAX;j++) {
			arr[i][j] += arr[i - 1][j - 1];
		}
	}

	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (arr[i][j])
				cnt++;
		}
	}

	cout << cnt;
}