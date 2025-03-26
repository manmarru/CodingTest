#include "pch.h"
#include "Header.h"
#include <list>

void Solve(ifstream* _pLoadStream)
{
	/*
	ȸ�� �ð�ǥ�� ���� ���� ���� ���� �� �ִ� ȸ���� ���� ���
	*/
	int iSize;
	CIN >> iSize;
	int iInput[2];
	list<pair<int, int>> listMeeting;

	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput[0] >> iInput[1];
		listMeeting.push_back({ iInput[0], iInput[1] });
	}
	listMeeting.sort();

	/*
	���� �� �ִ� ȸ���߿� �� ���� ������ ȸ�ǰ� ������ �װ� ����
	*/
	pair<int, int> iCurrMeet{ listMeeting.front() };
	int iResult{ 1 };
	listMeeting.pop_front();
	for (auto iter = listMeeting.begin(); iter != listMeeting.end(); iter++)
	{
		if (iCurrMeet.second > iter->second) // ��ħ + ������������ȸ��
		{
			iCurrMeet = *iter;
		}
		else if (iCurrMeet.second <= iter->first) // ����ȸ��
		{
			++iResult;
			iCurrMeet = *iter;
		}
	}
	cout << iResult;
}