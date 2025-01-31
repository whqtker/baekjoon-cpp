#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int howManyAlpha[26] = {}; //index�� 0�̸� a(97) �Ǵ� A(65), index�� 25�� z(122) �Ǵ� Z(90), 0�̸� ���� ����, ������ ������, 0���� �ʱ�ȭ
	string word;
	cin >> word;

	for (int i = 0; i < word.size(); i++)
	{
		if (int(word.at(i)) >= 97)
			howManyAlpha[int(word.at(i)) - 97]++; //�ҹ���
		else if (int(word.at(i)) <= 90)
			howManyAlpha[int(word.at(i)) - 65]++; //�빮��
	}

	int maxValue = -1;
	int maxIndex;
	for (int i = 0; i < 26; i++) //�ִ� ���ϱ�
	{
		if (howManyAlpha[i] > maxValue)
		{
			maxValue = howManyAlpha[i];
			maxIndex = i;
		}
	}

	int howManyMax = 0;
	for (int i = 0; i < 26; i++) //�ִ��� ��� �� �ִ��� Ȯ���ϱ�
	{
		if (howManyAlpha[i] == maxValue)
			howManyMax++;
	}

	if (howManyMax == 1)
		cout << char(maxIndex + 65);
	else if (howManyMax > 1)
		cout << '?';
}