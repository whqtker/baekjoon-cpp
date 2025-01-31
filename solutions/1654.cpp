#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int k, n; // k���� ������ �ִ� ������ ��, n���� ������ �ϴ� ������ ����
	cin >> k >> n;
	vector<int> lan; // ������ �ִ� ������ ���̸� �����ϴ� ����
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		lan.push_back(x);
	}

	sort(lan.begin(), lan.end());
	long long int left = 1;
	long long int right = lan[lan.size() - 1];

	while (left <= right) {
		long long int mid = left + (right - left) / 2; // �����÷ο� ����
		long long int sum = 0; // �߸� ������ ����
		for (int i = 0; i < lan.size(); i++) {
			sum += lan[i] / mid;
			if (sum >= n) break; // sum�� n ���� ũ�� ���� �� ������ ������ �ʿ䰡 ����. �����÷ο� ������ ���� �ݺ����� ������.
		}

		if (sum >= n) {
			left = mid + 1;
		}
		else if (sum < n) {
			right = mid - 1;
		}
	}
	cout << right; // left�� right�� ���� �� while���� ���������� ������ right�� �ִ� ������ ���̰� ��

}