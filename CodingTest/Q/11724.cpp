#include "pch.h"
#include "Header.h"
#include <queue>
#include <map>

void Solve(ifstream* pLoadStream)
{
	/*
	������ִ� ������ ���� ���ϱ�
	����� ������ ���� ��嵵 ���� �� ����
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

	iResult = iSize[0] - mapLink.size(); // ������ ���� ��ŭ�� �ʱⰪ���� ����

	/*
	BFS
	map�� ��ȸ�ϸ鼭 ���ҵ��� stlDestination�� �ְ� ���Ҹ� ����
	�̹� ���� ���̸�(���Ұ� ������) continue
	stlDestination�� ���ҵ��� �ϳ��� ������ map���� �ش� ��尡 ����ִ��� Ȯ��(�̹� ���� ������ Ȯ��)
	���Ұ� ������ ���� stlDestinatio�� �ְ� map�� ���� ����
	stlDestination�� ��� �Ǹ� ������ִ� �� ������ ���� ��ȸ�Ѱ��̴ϱ� iReuslt += 1
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