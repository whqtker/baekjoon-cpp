#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define pp pair<pair<int, int>, pair<int, int>>

using namespace std;

// ���� �Ǵ� ���� ���� �� ������ ���� ���
int calc(int sm, int sd, int em, int ed) {
	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (sm > em || (sm == em && sd > ed))
		return 0;
	int ret = 0;
	if (sm == em)
		ret = ed - sd;
	else
		ret = day[sm] - sd + ed;
	for (int i = sm + 1;i <= em - 1;i++)
		ret += day[i];

	return ret;
}

// ���� ���� �Ǵ� ��¥ ������ ����, �Ǵ� ��¥�� ������ �ʰ� ���� ��(������ �� ��)���� ����
bool cmp(pp f1, pp f2) {
	int f1_sm = f1.first.first;
	int f1_sd = f1.first.second;
	int f1_em = f1.second.first;
	int f1_ed = f1.second.second;
	int f2_sm = f2.first.first;
	int f2_sd = f2.first.second;
	int f2_em = f2.second.first;
	int f2_ed = f2.second.second;

	if (f1_sm == f2_sm) {
		if (f1_sd == f2_sd)
			return calc(f1_sm, f1_sd, f1_em, f1_ed) > calc(f2_sm, f2_sd, f2_em, f2_ed);
		return f1_sd < f2_sd;
	}
	return f1_sm < f2_sm;
}

int main() {
	int n;
	cin >> n;

	vector<pp> date;
	for (int i = 0;i < n;i++) {
		int q, w, e, r;
		cin >> q >> w >> e >> r;

		date.push_back({ { q,w }, { e,r } });
	}

	sort(date.begin(), date.end(), cmp);

	// ��� ���� 11/30 ������ ���� ��� ����ó��
	bool flag = true;
	for (int i = 0;i < n;i++) {
		if (date[i].second.first == 12) {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << 0;
		return 0;
	}

	//  ��� ���� 3/1 ���Ŀ� �Ǵ� ��� ����ó��
	if (date[0].first.first >= 3) {
		if (date[0].first.first != 3 || date[0].first.second != 1) {
			cout << 0;
			return 0;
		}
	}

	// 3/1 �Ǵ� �� ������ �Ǵ� �� �� ���� �ʰ� ���� �� ã��
	int idx = 0;
	int max_gap = 0;
	for (int i = 0;i < n;i++) {
		if ((date[i].first.first == 3 && date[i].first.second == 1) || date[i].first.first < 3) {
			int tmp = calc(3, 1, date[i].second.first, date[i].second.second);
			if (tmp >= max_gap) {
				max_gap = tmp;
				idx = i;
			}
		}
	}

	int cnt = 1;
	int cur = idx + 1;
	int tmp = cur;

	while (1) {
		// ���� ���� ���� ���� 11/30 ���Ķ�� �ߴ�
		if (date[idx].second.first == 12)
			break;

		// ������ �ɵ� �� ���� �ʰ� ���� �� ã��
		for (int i = cur;i < n;i++) {
			bool cond = date[i].first.first < date[idx].second.first || (date[i].first.first == date[idx].second.first && date[i].first.second <= date[idx].second.second);
			if (cond) {
				if (date[tmp].second.first < date[i].second.first || (date[i].second.first == date[tmp].second.first && date[tmp].second.second <= date[i].second.second))
					tmp = i;
			}
			else {
				// i == cur�ε� ���� if���� ������� �ʾҴٴ� ���� ���� ���� ���� ������ �� �� �ִ� ���� ���ٴ� �ǹ��̴�.
				if (i == cur && !cond) {
					cout << 0;
					return 0;
				}
				break;
			}
		}

		cnt++;
		idx = tmp;
		cur = idx + 1;
	}

	cout << cnt;
}