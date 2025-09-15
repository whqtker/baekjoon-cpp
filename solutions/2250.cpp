#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int left, right;
};

Node nodes[10001];
int num[10001]; // ����� �� ��ȣ
int min_num[10001]; // �� �������� �ּ� �� ��ȣ
int max_num[10001]; // �� �������� �ִ� �� ��ȣ
bool is_child[10001];
int cnt = 1; // ���� ��ȸ �� �湮�� ����� ��

void inorder(int node, int depth) {
    if (node == -1) {
        return;
    }

    inorder(nodes[node].left, depth + 1);

    num[node] = cnt++;
    min_num[depth] = min(min_num[depth], num[node]);
    max_num[depth] = max(max_num[depth], num[node]);

    inorder(nodes[node].right, depth + 1);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        min_num[i] = n + 1;
    }

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a] = { b, c };

        if (b != -1)
            is_child[b] = true;
        if (c != -1)
            is_child[c] = true;
    }

    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (!is_child[i]) {
            root = i;
            break;
        }
    }

    // ���� ��ȸ�� �湮�ϴ� ������ �� ��ȣ��
    inorder(root, 1);

    int max_width = 0;
    int level = -1;

    // ������ �ִ��� n
    for (int i = 1; i <= n; i++) {
        if (max_num[i] == 0)
            break;

        int width = max_num[i] - min_num[i] + 1;
        if (width > max_width) {
            max_width = width;
            level = i;
        }
    }

    cout << level << " " << max_width;
}
