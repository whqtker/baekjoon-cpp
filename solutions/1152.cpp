#include <iostream>
#include <string>

using namespace std;

int main() {
	string sentence;
	getline(cin, sentence);

	int blankCnt = 0;
	for (int i = 0; i < sentence.size(); i++)
	{
		if (i == 0 || i == sentence.size() - 1) //������ �� �հ� �ڴ� �ܾ� ������ ������ ���� �����Ƿ� �Ѿ��. ���� �ش� index�� ����Ű�� ���� ���ĺ� �Ǵ� ����������
			continue;

		if (sentence[i] == ' ')
			blankCnt++;

	}
	int wordCnt = blankCnt + 1;
	if (sentence.size() == 1 && sentence == " ") //���� ó�� �κ�
		wordCnt = 0;

	cout << wordCnt;
}