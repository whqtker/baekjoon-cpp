#include <iostream>
#include <algorithm>

using namespace std;

struct Ball {
	int color;
	int size;
	int idx;
};

Ball balls[200001];
int cumsumByColor[200001];
int cumsumBySize[2001];

int ans[200001];

bool cmp(Ball a, Ball b) {
	if (a.size == b.size)
		return a.color < b.color;
	return a.size < b.size;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> balls[i].color >> balls[i].size;
		balls[i].idx = i;
	}

	sort(balls, balls + n, cmp);

	// i�� ° ���� ������� ���� ũ��: i�� °���� ��� ���� ũ���� �� 
	// - i�� ° ���� ���� ���� ���� ũ���� ��(1) - i�� ° ���� ũ�Ⱑ ���� ���� ũ���� ��(2)
	// + i�� ° ���� ũ��(3) ((2)���� ���ʿ��ϰ� ���� ���� ����)
	int total = 0;
	for (int i = 0; i < n; i++) {
		int color = balls[i].color;
		int size = balls[i].size;
		int idx = balls[i].idx;

		total += size;
		cumsumByColor[color] += size;
		cumsumBySize[size] += size;

		// ���� ���� �ߺ��� ���� ��� ���� ���� ������ �����´�.
		if (i - 1 >= 0 && balls[i - 1].color == color && balls[i - 1].size == size) {
			ans[idx] = ans[balls[i - 1].idx];
		}
		else
			ans[idx] = total - cumsumByColor[color] - cumsumBySize[size] + size;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
}