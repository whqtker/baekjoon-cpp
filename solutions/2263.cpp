#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inorder, postorder;
int n;

vector<int> recur(int startInorder, int endInorder, int startPostorder, int endPostorder) {
	if (startInorder > endInorder || startPostorder > endPostorder) {
		return {};
	}

	// ��Ʈ ���� postorder�� ������ ����
	int root = postorder[endPostorder];
	int inorderRootIndex = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	// ���� ����Ʈ���� ũ��
	int leftTreeSize = inorderRootIndex - startInorder;

	vector<int> preorder;
	preorder.push_back(root);

	// ���� ����Ʈ��
	vector<int> leftPreorder = recur(startInorder, inorderRootIndex - 1, startPostorder, startPostorder + leftTreeSize - 1);

	// ������ ����Ʈ��
	vector<int> rightPreorder = recur(inorderRootIndex + 1, endInorder, startPostorder + leftTreeSize, endPostorder - 1);

	preorder.insert(preorder.end(), leftPreorder.begin(), leftPreorder.end());
	preorder.insert(preorder.end(), rightPreorder.begin(), rightPreorder.end());

	return preorder;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		inorder.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		postorder.push_back(x);
	}


	vector<int> preorder = recur(0, n - 1, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << preorder[i] << " ";
	}
}