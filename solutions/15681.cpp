#include <iostream>
#include <vector>

using namespace std;

vector<int> conn[100001]; // ��� �� ���� ���踦 �����ϴ� ����
vector<int> child[100001]; // �ڽ� ��带 �����ϴ� ����
int parent[100001]; // �θ� ��带 �����ϴ� ����
int cnt[100001];

// �ڽ� �� �θ� ���� ����
void makeTree(int cur,int par) {
	for (int i = 0; i < conn[cur].size(); i++) {
		int node = conn[cur][i];
		if (node != par) {
			parent[node] = cur;
			child[cur].push_back(node);
			makeTree(node, cur);
		}
	}
}

// ����Ʈ���� ��� ���� ����
void countNodes(int cur) {
	cnt[cur] = 1;
	for (int i = 0; i < child[cur].size(); i++) {
		countNodes(child[cur][i]);
		cnt[cur] += cnt[child[cur][i]];
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, r, q; // ����� ��, ��Ʈ ��� ��ȣ, ���� ��
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		conn[x].push_back(y);
		conn[y].push_back(x);
	}

	parent[r] = -1;
	makeTree(r, -1);

	countNodes(r);

	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		cout << cnt[x] << "\n";
	}
}