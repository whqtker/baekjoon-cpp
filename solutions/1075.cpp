#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int f; //n: ���� �� �ڸ��� ������ �ٲ� ��, f: �ٲ� n�� ������ �������� �ϴ� ��
	cin >> n >> f;

	//int x = 0;
	//int tmp = n;
	//while (tmp > 0) //�ڸ� �� ���ϴ� �Լ�
	//{
	//	tmp /= 10;
	//	x++;
	//}

	n -= ((n % (int)pow(10, 2)));

	int cnt = 0;
	while (n % f != 0)
	{
		n++;
		cnt++;
	}

	if (cnt < 10)
		cout << 0 << cnt;
	else
		cout << cnt;
}