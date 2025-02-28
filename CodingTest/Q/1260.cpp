#include "pch.h"
#include "Header.h"
#include <map>
#include <queue>
#include <stack>
#include <list>

void Solve(ifstream* pLoadStream)
{
	/*
	DFS 탐색 결과와 BFS 탐색 결과를 출력하기
	방문 가능한 곳이 여러개면 번호가 작은 곳부터
	*/
	int iSize[2]; //정점개수, 간선개수
	int iStart; // 시작번호
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
				//거꾸로 정렬해야되는데? 걍 리스트에 복사해서 써야겠다...

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