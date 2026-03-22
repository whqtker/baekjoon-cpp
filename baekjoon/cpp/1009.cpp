#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a, b; //데이터의 수는 a^b

	for (int testCase = 0; testCase < n; testCase++)
	{
		cin >> a >> b;

		int tmp = a;
		for (int i = 0; i < b - 1; i++)
		{
			a *= tmp;
			a %= 10;
		}

		if (b == 1)
			a %= 10;

		if (a == 0)
			a = 10;

		cout << a << "\n";
	}
}