#include <iostream>
#include <queue>

using std::cout;
using std::cin;

int main()
{
	int n, k; //�� n���� �����, k��° ��� ����, k <= n
	cin >> n >> k;

	std::queue<int> people;
	for (int i = 1; i <= n; i++) //ť people�� 1���� n���� �� �ֱ�
	{
		people.push(i);
	}

	cout << "<";
	while (people.empty() == false) //ť�� �� �� ������ while�� ����
	{
		for (int i = 0; i < k - 1; i++)
		{
			people.push(people.front());
			people.pop();
		}
		cout << people.front();
		if (people.size() != 1)
			cout << ", ";
		people.pop();
	}
	cout << ">";
}