#include "pch.h"
#include "Header.h"
#include <list>
#include <map>

void Solve(ifstream* pLoadStream)
{
	/*
		fifo
		원소들 중 우선순위가 높은 게 하나라도 있으면 pop 하지 않고 맨 뒤로 보내버림
		케이스 갯수
		원소 갯수, 타겟 원소 인덱스
		원소들 내용
	*/
	/*
		map에 원소들 갯수를 받아두고 이거 순회하면서 우선순위 체크
		타겟의 이터레이터를 받아두고 이게 제거될 차례인지 체크

		문제가 원한 정답은 map 대신 우선순위 큐 쓰는거
	*/
	int iTimes{};
	CIN >> iTimes;

	int iSize{};
	int iTarget{}; // 타겟 인덱스
	int iNum{};
	int iResult{ 0 };
	list<int> listPapers;
	map<int, int> mapNums;
	for (int i = 0; i < iTimes; i++)
	{
		iResult = 0;
		CIN >> iSize >> iTarget;

		for (int j = 0; j < iSize; j++)
		{
			CIN >> iNum;
			listPapers.push_back(iNum);
			mapNums[iNum] += 1;
		}

		if (1 != iSize)
		{
			list<int>::iterator iterTarget = listPapers.begin();
			for (int i = 0; i < iTarget; i++)
				++iterTarget;

			while (1)//itertarget이 지워질때까지
			{
				++iResult;
				for (auto& temp : mapNums)
				{
					if (temp.first > listPapers.front())
					{
						listPapers.push_back(listPapers.front());
						mapNums[listPapers.front()] += 1;
						if (listPapers.begin() == iterTarget)
							iterTarget = --listPapers.end();
						iResult--;
						break;
					}
				}
				if (iterTarget == listPapers.begin())
				{
					break;
				}
				mapNums[listPapers.front()] -= 1;
				if (0 == mapNums[listPapers.front()])
					mapNums.erase(listPapers.front());
				listPapers.pop_front();
			}
			cout << iResult << '\n';
		}
		else
			cout << 1 << '\n';
		list<int> listbuffering;
		map<int, int> mapBuffering;
		swap(listPapers, listbuffering);
		swap(mapNums, mapBuffering);


	}
}