#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int min_seg_tree[400000];

void init(int start, int end, int node) {
	// ���� ����� ���
	if (start == end) {
		min_seg_tree[node] = arr[start];
		return;
	}

	// ����, ������ �ڽ��� ��������� �ʱ�ȭ
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);

	min_seg_tree[node] = min(min_seg_tree[node * 2], min_seg_tree[node * 2 + 1]);
}

// [start, end]: ���� ��尡 ����ϴ� ����, idx: ������ ����� �ε���
void update(int start, int end, int idx, int node, int val) {
	// ������ ��� ���
	if (start > idx || idx > end)
		return;

	// ���� ��忡 ������ ��� �� ����
	if (start == end) {
		min_seg_tree[node] = val;
		arr[idx] = val;
		return;
	}

	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, idx, node * 2, val);
		update(mid + 1, end, idx, node * 2 + 1, val);

		min_seg_tree[node] = min(min_seg_tree[node * 2], min_seg_tree[node * 2 + 1]);
	}
}

// [start, end]: ���� ��尡 ����ϴ� ����, [left, right]: ã���� �ϴ� ����
int findMin(int start, int end, int left, int right, int node) {
	// ��ġ�� �ʴ� ���
	if (start > right || end < left)
		return 1e9 + 1;

	// ã���� �ϴ� ������ ��尡 ����ϴ� ������ ���Ե� ���
	if (left <= start && end <= right)
		return min_seg_tree[node];

	int mid = (start + end) / 2;
	return min(findMin(start, mid, left, right, node * 2), findMin(mid + 1, end, left, right, node * 2 + 1));
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(0, n - 1, 1);

	int m;
	cin >> m;
	while (m--) {
		int op;
		cin >> op;

		if (op == 1) {
			int i, v;
			cin >> i >> v;
			update(0, n - 1, i - 1, 1, v);
		}
		else {
			int i, j;
			cin >> i >> j;
			cout << findMin(0, n - 1, i - 1, j - 1, 1) << "\n";
		}
	}
}