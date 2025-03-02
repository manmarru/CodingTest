#include "pch.h"
#include "Header.h"
#include <queue>
#include <map>

void Solve(ifstream* pLoadStream)
{
	/*
	연결돼있는 묶음의 갯수 구하기
	참고로 연결이 없는 노드도 있을 수 있음
	*/
	int iSize[2];
	CIN >> iSize[0] >> iSize[1];
	int iInput[2];
	int iResult{ 0 };
	map<int, queue<int>> mapLink;
	queue<int> stlDestination;
	for (int i = 0; i < iSize[1]; ++i)
	{
		CIN >> iInput[0] >> iInput[1];
		mapLink[iInput[0]].push(iInput[1]);
		mapLink[iInput[1]].push(iInput[0]);
	}

	iResult = iSize[0] - mapLink.size(); // 연결이 없는 만큼을 초기값으로 지정

	/*
	BFS
	map을 순회하면서 원소들을 stlDestination에 넣고 원소를 지움
	이미 갔던 곳이면(원소가 없으면) continue
	stlDestination의 원소들을 하나씩 꺼내서 map에서 해당 노드가 비어있는지 확인(이미 갔던 곳인지 확인)
	원소가 있으면 전부 stlDestinatio에 넣고 map의 원소 삭제
	stlDestination이 비게 되면 연결돼있는 한 묶음을 전부 순회한것이니까 iReuslt += 1
	*/
	while (!mapLink.empty())
	{
		auto iter = mapLink.begin();
		if ((*mapLink.begin()).second.empty())
		{
			mapLink.erase(mapLink.begin());
			continue;
		}

		stlDestination.push(iter->first);
		
		while (!stlDestination.empty())
		{
			int iCurr = stlDestination.front();
			stlDestination.pop();

			if (mapLink.end() != mapLink.find(iCurr))
			{
				auto* currNode = &mapLink[iCurr];
				while (!currNode->empty())
				{
					stlDestination.push(currNode->front());
					currNode->pop();
				}
				mapLink.erase(iCurr);
			}
		}
		++iResult;
		queue<int>().swap(stlDestination);
	}

	cout << iResult;
}