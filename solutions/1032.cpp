#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int fileCount; //������ ����, 50�� ����
	cin >> fileCount;

	vector<string>fileName(fileCount);

	for (auto& ele : fileName) //fileName �Է¹ޱ�
	{
		cin >> ele;
	}

	//fileName�鿡���� �ִ� ���� ���ϱ�
	int FileNameLength = fileName[0].size(); //���� ���� �̸����� ���̴� ��� ����

	vector<char> outputMessage; //��µ� �޼���
	for (int i = 0; i < FileNameLength; i++)
	{
		bool flag = true;
		for (int j = 0; j < fileName.size() - 1; j++)
		{
			if (fileName[j][i] != fileName[j + 1][i])
			{
				outputMessage.push_back('?');
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			outputMessage.push_back(fileName[0][i]);
		}
	}

	for (auto& ele : outputMessage) //��µ� �޼��� ���
	{
		cout << ele;
	}
}