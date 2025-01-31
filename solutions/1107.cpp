#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string n; 
	cin >> n;

	int m;
	cin >> m;
	vector<int> broken; // ���峭 ����
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		broken.push_back(a);
	}

	vector<int> v;
	for (int i = 0; i <= 999999; i++) {
		bool flag = false;
		for (int j = 0; j < broken.size(); j++) {
			// i�� ���峭 ���ڰ� �ִ��� üũ
			if (to_string(i).find(to_string(broken[j])) != string::npos) {
				flag = true;
				break;
			}
		}
		// ���峭 ���ڰ� ���ٸ� ������ �ϴ� ��ư�� �ּڰ��� ����Ѵ�.
		if (flag == false) {
			int cnt = abs(i - stoi(n));
			int tmp = i;
			int digit = 0;
			while (tmp > 0) {
				tmp /= 10;
				digit++;
			}
			if (i == 0)
				cnt += 1;
			else
				cnt += digit;
			v.push_back(cnt);
		}
	}

	v.push_back(abs(100 - stoi(n))); // ���� ä��(100)���� +, -�� ������ Ƚ��
	cout << *min_element(v.begin(), v.end());
}