#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// posi~~: a, b�� ��� �Ǵ� 0�� �� ��Ģ���� ����
string posiAdd(string a, string b) {
	string ans;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int maxDigit = max(a.length(), b.length());

	int carry = 0; // �޾ƿø���
	for (int i = 0; i < maxDigit; i++) {
		// a�� i�� ° �ε����� ���Ұ� �������� ���� ��
		if (i >= a.length()) {
			int n = b[i] - '0' + carry; // ��� ����� ���� �ڸ� ��
			carry = n / 10;
			n %= 10;
			ans += n + '0';
		}
		// b�� i�� ° �ε����� ���Ұ� �������� ���� ��
		else if (i >= b.length()) {
			int n = a[i] - '0' + carry; // ��� ����� ���� �ڸ� ��
			carry = n / 10;
			n %= 10;
			ans += n + '0';
		}
		else {
			int n = a[i] - '0' + b[i] - '0' + carry; // ��� ����� ���� �ڸ� ��
			carry = n / 10;
			n %= 10;
			ans += n + '0';
		}
	}
	if (carry != 0) ans += carry + '0'; // ������ �޾ƿø����� ����ؾ� �Ѵ�.
	reverse(ans.begin(), ans.end());
	return ans;
}

string posiSub(string a, string b) {
	string ans;
	string cal_a = a;
	string cal_b = b;
	// �ڸ����� �� ū ���� �� ū ���̴�.
	if (cal_a.length() > cal_b.length()) {
		reverse(cal_a.begin(), cal_a.end());
		reverse(cal_b.begin(), cal_b.end());
		for (int i = 0; i < cal_a.size(); i++) {
			// �޾Ƴ����� �ϴ� ��Ȳ
			int n; // ��� ����� ���� �ڸ���
			// b�� i�� ° �ε����� ���Ұ� �������� ���� ��
			if (i >= cal_b.length()) {
				// �ڸ����� 0���� ���� ���� ��
				if (cal_a[i] - '0' < 0) {
					cal_a[i + 1] -= 1;
					n = cal_a[i] + 10 - '0';
				}
				else
					n = cal_a[i] - '0';
			}
			else if (cal_a[i] - '0' - cal_b[i] + '0' < 0) {
				cal_a[i + 1] -= 1;
				n = cal_a[i] + 10 - '0' - cal_b[i] + '0';
			}
			else {
				n = cal_a[i] - '0' - cal_b[i] + '0';
			}
			ans += n + '0';
		}
	}
	else if (cal_a.length() < cal_b.length()) {
		reverse(cal_a.begin(), cal_a.end());
		reverse(cal_b.begin(), cal_b.end());
		for (int i = 0; i < cal_b.size(); i++) {
			int n; // ��� ����� ���� �ڸ���
			// a�� i�� ° �ε����� ���Ұ� �������� ���� ��
			if (i >= cal_a.length()) {
				// �ڸ����� 0���� ���� ���� ��
				if (cal_b[i] - '0' < 0) {
					cal_b[i + 1] -= 1;
					n = cal_b[i] + 10 - '0';
				}
				else
					n = cal_b[i] - '0';
			}
			// �޾Ƴ����� �ϴ� ��Ȳ
			else if (cal_b[i] - '0' - cal_a[i] + '0' < 0) {
				cal_b[i + 1] -= 1;
				n = cal_b[i] + 10 - '0' - cal_a[i] + '0';
			}

			else {
				n = cal_b[i] - '0' - cal_a[i] + '0';
			}
			ans += n + '0';
		}
	}
	// �ڸ����� ������ �� ���ڸ� ���� ���Ѵ�. �� ���� ���� ���� ���⼭ ó���Ѵ�.
	else if (cal_a >= cal_b) {
		reverse(cal_a.begin(), cal_a.end());
		reverse(cal_b.begin(), cal_b.end());
		for (int i = 0; i < cal_a.size(); i++) {
			// �޾Ƴ����� �ϴ� ��Ȳ
			int n; // ��� ����� ���� �ڸ���
			// b�� i�� ° �ε����� ���Ұ� �������� ���� ��
			if (i >= cal_b.length()) {
				// �ڸ����� 0���� ���� ���� ��
				if (cal_a[i] - '0' < 0) {
					cal_a[i + 1] -= 1;
					n = cal_a[i] + 10 - '0';
				}
				else n = cal_a[i] - '0';
			}
			else if (cal_a[i] - '0' - cal_b[i] + '0' < 0) {
				cal_a[i + 1] -= 1;
				n = cal_a[i] + 10 - '0' - cal_b[i] + '0';
			}
			else {
				n = cal_a[i] - '0' - cal_b[i] + '0';
			}
			ans += n + '0';
		}
	}
	else {
		reverse(cal_a.begin(), cal_a.end());
		reverse(cal_b.begin(), cal_b.end());
		for (int i = 0; i < cal_b.size(); i++) {
			// �޾Ƴ����� �ϴ� ��Ȳ
			int n; // ��� ����� ���� �ڸ���
			// a�� i�� ° �ε����� ���Ұ� �������� ���� ��
			if (i >= cal_a.length()) {
				// �ڸ����� 0���� ���� ���� ��
				if (cal_b[i] - '0' < 0) {
					cal_b[i + 1] -= 1;
					n = cal_b[i] + 10 - '0';
				}
				else n = cal_b[i] - '0';
			}
			else if (cal_b[i] - '0' - cal_a[i] + '0' < 0) {
				cal_b[i + 1] -= 1;
				n = cal_b[i] + 10 - '0' - cal_a[i] + '0';
			}
			else {
				n = cal_b[i] - '0' - cal_a[i] + '0';
			}
			ans += n + '0';
		}
	}
	// ans�� ���� 0�� ���� �� �ִ�. �� ��� �����־�� �Ѵ�. ex) 19 - 18 = 01 (x) 1 (o)
	reverse(ans.begin(), ans.end());

	int idx = 0;
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] == '0') idx = i;
		else {
			idx = i;
			break;
		}
	}
	ans = ans.substr(idx, ans.length() - idx);

	// b�� �� ū ��� �տ� -�� ���δ�.
	if (a.length() < b.length()) {
		string minus = "-";
		minus += ans;
		ans = minus;
	}
	else if (a.length() == b.length() && a < b) {
		string minus = "-";
		minus += ans;
		ans = minus;
	}

	return ans;
}

string posiMul(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<string> part; // a�� b�� �ڸ����� ���� ���� �����. part�� ���ҵ��� ���� ���� ���� ���.
	for (int i = 0; i < b.size(); i++) {
		int carry = 0; // �޾ƿø���
		string ans;
		for (int j = 0; j < a.size(); j++) {
			int n = (a[j] - '0') * (b[i] - '0') + carry; // ��� ����� ���� �ڸ� ��
			carry = n / 10;
			n %= 10;
			ans += n + '0';
		}
		if (carry != 0) ans += carry + '0';

		// ���� ������������ ���� �ڸ��� ���� ���� �ڿ� �� ĭ ��� ����Ѵ�. �� ������ �����ؾ� �Ѵ�.
		reverse(ans.begin(), ans.end());
		for (int j = 0; j < i; j++) {
			ans += '0';
		}
		part.push_back(ans);
	}

	string sum = part[0];
	for (int i = 0; i < part.size() - 1; i++) {
		posiAdd(sum, part[i + 1]);
		sum = posiAdd(sum, part[i + 1]);
	}

	// ��� ��ó��
	int idx = 0;
	for (int i = 0; i < sum.length(); i++) {
		if (sum[i] == '0') idx = i;
		else {
			idx = i;
			break;
		}
	}
	sum = sum.substr(idx, sum.length() - idx);
	return sum;
}

string add(string a, string b) {
	// �� �� ������ �� ���񰪳��� �տ� - �� ���δ�.
	if (a[0] == '-' && b[0] == '-') {
		string ret = "-";
		a = a.substr(1, a.size() - 1);
		b = b.substr(1, b.size() - 1);
		ret += posiAdd(a, b);
		return ret;
	}
	// a�� ������ ��
	else if (a[0] == '-') {
		a = a.substr(1, a.size() - 1);
		return posiSub(b, a);
	}
	// b�� ������ ��
	else if (b[0] == '-') {
		b = b.substr(1, b.size() - 1);
		return posiSub(a, b);
	}
	// �� �� ����� ��
	else return posiAdd(a, b);
}

string sub(string a, string b) {
	// �� �� ������ �� - a - (- b) = b - a
	if (a[0] == '-' && b[0] == '-') {
		a = a.substr(1, a.size() - 1);
		b = b.substr(1, b.size() - 1);
		return posiSub(b, a);
	}
	// a�� ������ �� - a - b = - (a + b)
	else if (a[0] == '-') {
		a = a.substr(1, a.size() - 1);
		string ret = "-";
		ret += posiAdd(a, b);
		return ret;
	}
	// b�� ������ ��
	else if (b[0] == '-') {
		b = b.substr(1, b.size() - 1);
		return posiAdd(a, b);
	}
	// �� �� ����� ��
	else return posiSub(a, b);
}

string mul(string a, string b) {
	// �� �� ������ ��
	if (a[0] == '-' && b[0] == '-') {
		a = a.substr(1, a.size() - 1);
		b = b.substr(1, b.size() - 1);
		return posiMul(a, b);
	}
	// a�� ������ ��
	else if (a[0] == '-') {
		a = a.substr(1, a.size() - 1);
		string ret = "-";
		ret += posiMul(a, b);
		return ret;
	}
	// b�� ������ ��
	else if (b[0] == '-') {
		b = b.substr(1, b.size() - 1);
		string ret = "-";
		ret += posiMul(a, b);
		return ret;
	}
	// �� �� ����� ��
	else return posiMul(a, b);
}

int main() {
	string a, b;
	cin >> a >> b;

	// ��ó�� ���� (�Էµ� ���� 0���� �����ϴ� ���)
	int idx = 0;
	bool nega = false; // �Էµ� ���� �������� �Ǻ�
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != '-' && a[i] != '0') {
			idx = i;
			break;
		}
		else if (a[i] == '-') nega = true;
	}
	a = a.substr(idx);
	if (nega == true && a[0] != 0) {
		string minus = "-";
		minus += a;
		a = minus;
	}

	idx = 0;
	nega = false;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] != '-' && b[i] != '0') {
			idx = i;
			break;
		}
		else if (b[i] == '-') nega = true;
	}
	b = b.substr(idx);
	if (nega == true && b[0] != 0) {
		string minus = "-";
		minus += b;
		b = minus;
	}

	// ����
	cout << add(a, b) << "\n";

	// ����
	cout << sub(a, b) << "\n";

	// ����
	cout << mul(a, b) << "\n";
}