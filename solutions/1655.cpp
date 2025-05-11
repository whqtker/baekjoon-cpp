#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	priority_queue<int> left; // �߾Ӱ��� �������� ���ʿ� ��ġ�� ��
	priority_queue<int, vector<int>, greater<int>> right; // �߾Ӱ��� �������� �����ʿ� ��ġ�� ��
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		// right���� �߾Ӱ��� ����� ��(right.top())�� x���� ������ �ܼ��� right�� x ����
		if (!right.empty() && right.top() < x)
			right.push(x);
		else
			left.push(x);

		int mid = i / 2 + 1;

		// left�� ���� ġ��ģ ���
		if (left.size() > mid) {
			right.push(left.top());
			left.pop();
		}
		else if (left.size() < mid) {
			left.push(right.top());
			right.pop();
		}

		cout << left.top() << "\n";
	}
}