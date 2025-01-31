#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		double d;
		string s;
		vector<string> op;

		cin >> d;

		// cin.get()�� ����, ���๮�ڵ� �Է¹޴´�. cin�� ����, ���๮�ڸ� �����Ѵ�.
		while (1) {
			s = cin.get();
			if (s == "\n") break;
			else if (s != " ")
				op.push_back(s);
		}

		for (int j = 0; j < op.size(); j++) {
			if (op[j] == "@") d *= 3;
			else if (op[j] == "%") d += 5;
			else if (op[j] == "#") d -= 7;
		}

		// �Ҽ��� �ڸ����� �����ϴ� �κ�, �Ҽ��� �Ʒ� 0 ���
		cout << fixed;
		cout << showpoint << setprecision(2);

		cout << d << "\n";
	}
}