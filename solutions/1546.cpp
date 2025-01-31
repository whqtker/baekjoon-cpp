#include <iostream>

using std::cout;
using std::cin;

int main() {
	const int max_sub_cnt = 1000;
	double score[max_sub_cnt] = {};
	int sub_cnt;

	cin >> sub_cnt;

	for (int i = 0; i < sub_cnt; i++)
	{
		cin >> score[i];
	}

	double MaxScore = 0;
	for (int i = 0; i < sub_cnt; i++)
	{
		if (score[i] >= MaxScore)
		{
			MaxScore = score[i];
		}
	}

	double tot = 0;
	double avg;
	for (int i = 0; i < sub_cnt; i++)
	{
		score[i] = (score[i] / MaxScore) * 100.0; //�ְ� ������ �ƴ� �ٸ� ������ ���� �缳��
		tot += score[i];
	}

	avg = tot / sub_cnt;
	cout << std::fixed; //�Ҽ��� �� �ڸ��� ����.
	cout.precision(3); //�Ҽ��� �� 3�ڸ��� ����, �� �ڵ�� ��ȣ�ۿ�
	cout << avg;

	return 0;
}