#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int result; // ��� ����� ���� �ڸ�
	int next = 0; // ��� ����� ���� �ڸ�
	vector<int> ret; // ���� ��

	int x = max(a.length(), b.length()); // �캯�� �ٷ� for���� ������ �� ��. for���� ���鼭 ���ڿ��� ���̰� �ٲ�� ����.
	for (int i = 0; i < x; i++) {
		result = 0;
		if (!a.empty()) {
			result += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			result += b.back() - '0';
			b.pop_back();
		}
		result += next;
		next = result / 10;
		result %= 10;

		ret.push_back(result);
	}

	if (next == 1)
		ret.push_back(next);

	reverse(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i];
	}
}