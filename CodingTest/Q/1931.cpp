#include "pch.h"
#include "Header.h"
#include <list>

void Solve(ifstream* _pLoadStream)
{
	/*
	회의 시간표를 보고 가장 많이 넣을 수 있는 회의의 수를 출력
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
	넣을 수 있는 회의중에 더 일찍 끝나는 회의가 있으면 그걸 선택
	*/
	pair<int, int> iCurrMeet{ listMeeting.front() };
	int iResult{ 1 };
	listMeeting.pop_front();
	for (auto iter = listMeeting.begin(); iter != listMeeting.end(); iter++)
	{
		if (iCurrMeet.second > iter->second) // 겹침 + 더빨리끝나는회의
		{
			iCurrMeet = *iter;
		}
		else if (iCurrMeet.second <= iter->first) // 다음회의
		{
			++iResult;
			iCurrMeet = *iter;
		}
	}
	cout << iResult;
}