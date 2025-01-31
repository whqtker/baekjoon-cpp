#include <iostream>
#include <vector>

using namespace std;

vector<int> v[51];
int visited[51];
int leaves;
int rnode; // ������ ���
int root;

void dfs(int node) {
	// ������ ���� ���캸�� ����
	if (node == rnode) return;

	// node�� ���� ����� ���
	if (v[node].size() == 0) leaves++;

	// ���� ����� ������ �ڽ��� ������ ����� ���� ��尡 ���� ��尡 ��
	if (v[node].size() == 1 && v[node][0] == rnode) leaves++;

	visited[node] = 1;

	int cnt = 0;
	for (int i = 0;i < v[node].size();i++) {
		int nnode = v[node][i];

		if (!visited[nnode]) {
			dfs(nnode);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		int x;
		cin >> x;

		if (x == -1) root = i;
		else
			v[x].push_back(i);
	}

	cin >> rnode;

	dfs(root);

	cout << leaves;
}