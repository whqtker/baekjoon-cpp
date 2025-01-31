#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int whiteCnt = 0, blueCnt = 0;

void ans(vector<int> v) {
	int s = sqrt(v.size()); // v�� �� ���� ����
	vector<int> white(pow(s, 2), 0);
	vector<int> blue(pow(s, 2), 1);

	if (v == white) {
		whiteCnt++;
	}
	else if (v == blue) {
		blueCnt++;
	}

	// v�� ���ذ� �ٸ��ٸ� ���� ���� �ǽ�
	else {
		// I ����
		vector<int> one;
		for (int i = 0; i < s / 2; i++) {
			for (int j = 0; j < s / 2; j++) {
				one.push_back(v[i * s + j]);
			}
		}
		ans(one);

		// II ����
		vector<int> two;
		for (int i = 0; i < s / 2; i++) {
			for (int j = 0; j < s / 2; j++) {
				two.push_back(v[i * s + j + s / 2]);
			}
		}
		ans(two);

		// III ����
		vector<int> three;
		for (int i = 0; i < s / 2; i++) {
			for (int j = 0; j < s / 2; j++) {
				three.push_back(v[(i + s / 2) * s + j]);
			}
		}
		ans(three);

		// IV ����
		vector<int> four;
		for (int i = 0; i < s / 2; i++) {
			for (int j = 0; j < s / 2; j++) {
				four.push_back(v[(i + s / 2) * s + j + s / 2]);
			}
		}
		ans(four);
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n * n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	ans(v);
	cout << whiteCnt << " " << blueCnt;
}