#include "pch.h"
#include "Header.h"
#include <map>
#include <queue>
#include <stack>
#include <list>

void Solve(ifstream* pLoadStream)
{
	/*
	DFS Ž�� ����� BFS Ž�� ����� ����ϱ�
	�湮 ������ ���� �������� ��ȣ�� ���� ������
	*/
	int iSize[2]; //��������, ��������
	int iStart; // ���۹�ȣ
	int iInput[2];
	map<int, priority_queue<int>>mapLink;
	stack<int> DFSDestination;
	CIN >> iSize[0] >> iSize[1] >> iStart;
	vector<bool> vecHistory(iSize[0], false);
	for (int i = 0; i < iSize[1]; ++i)
	{
		CIN >> iInput[0] >> iInput[1];
		mapLink[iInput[0]].push(iInput[1]);
		mapLink[iInput[1]].push(iInput[0]);
	}
	DFSDestination.push(iStart);

	//DFS
	int iCurr;
	int iNext;
	while (!DFSDestination.empty())
	{
		iCurr = DFSDestination.top();
		DFSDestination.pop();
		if (!vecHistory[iCurr - 1])
		{

			cout << iCurr << ' ';
			vecHistory[iCurr - 1] = true;
			priority_queue<int> Temp = mapLink[iCurr];
			while (!Temp.empty())
			{
				iNext = Temp.top();
				if (!vecHistory[iNext - 1])
				{
					DFSDestination.push(Temp.top());
				}
				Temp.pop();
			}
		}
	}
	cout << '\n';
	//BFS
	fill(vecHistory.begin(), vecHistory.end(), false);
	queue<int> BFSDestination;
	BFSDestination.push(iStart);
	while (!BFSDestination.empty())
	{
		iCurr = BFSDestination.front();
		BFSDestination.pop();
		if (!vecHistory[iCurr - 1])
		{
			cout << iCurr << ' ';
			vecHistory[iCurr - 1] = true;
			list<int> Temp;
			while (!mapLink[iCurr].empty())
			{
				//�Ųٷ� �����ؾߵǴµ�? �� ����Ʈ�� �����ؼ� ��߰ڴ�...

				iNext = mapLink[iCurr].top();
				mapLink[iCurr].pop();
				if (!vecHistory[iNext - 1])
				{
					Temp.push_front(iNext);
				}
			}
			for (int& i : Temp)
			{
				BFSDestination.push(i);
			}
		}
	}
}