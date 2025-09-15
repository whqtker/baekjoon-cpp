#include <iostream>

using namespace std;

int n, m; // ������ ��, �� ���� ��
int parent[100001];
int weight[100001]; // weight[i]: i�� ��Ʈ �� ���� ����

int Find(int x) {
	if (x == parent[x]) return x;

	int root = Find(parent[x]);
	weight[x] += weight[parent[x]];
	return parent[x] = root;
}

void Union(int x, int y, int w) {
	int px = Find(x);
	int py = Find(y);

	if (px != py) {
		// ��Ʈ�� ���Կ� ���� weight�� �����Ѵ�.
		// px�� �θ� py�� �����ϰ�, px�� ��Ʈ�� ��� ��忡 px->py (offset) ����ġ�� ���Ѵ�.
		// ��Ʈ�� px�� ������ ��带 x, ��Ʈ�� py�� ������ ��带 y��� ����.
		// �˰� �ִ� ����: x->y, x->px, y->py
		// x->px->py == x->y->py���� px->py�� ����ġ offset = w + weight[y] - weight[x]
		int offset = w + weight[y] - weight[x];
		weight[px] = offset;
		parent[px] = py;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	// ������ ���� �ȴٸ� �θ�� ���� ����.
	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 1;i <= n;i++) {
			parent[i] = i;
			weight[i] = 0;
		}

		for (int i = 0;i < m;i++) {
			char cmd;
			cin >> cmd;

			if (cmd == '!') {
				int a, b, w; // b�� a���� w��ŭ ���̴�.
				cin >> a >> b >> w;

				Union(b, a, w);
			}
			else if (cmd == '?') {
				int a, b; // b�� a���� �󸶳� ���ſ?
				cin >> a >> b;

				int pa = Find(a);
				int pb = Find(b);

				if (pa != pb) cout << "UNKNOWN\n";
				else {
					cout << weight[b] - weight[a] << "\n";
				}
			}
		}
	}
}