#include "pch.h"
#include "Header.h"
#include <list>
#include <map>

void Solve(ifstream* pLoadStream)
{
	/*
		fifo
		���ҵ� �� �켱������ ���� �� �ϳ��� ������ pop ���� �ʰ� �� �ڷ� ��������
		���̽� ����
		���� ����, Ÿ�� ���� �ε���
		���ҵ� ����
	*/
	/*
		map�� ���ҵ� ������ �޾Ƶΰ� �̰� ��ȸ�ϸ鼭 �켱���� üũ
		Ÿ���� ���ͷ����͸� �޾Ƶΰ� �̰� ���ŵ� �������� üũ

		������ ���� ������ map ��� �켱���� ť ���°�
	*/
	int iTimes{};
	CIN >> iTimes;

	int iSize{};
	int iTarget{}; // Ÿ�� �ε���
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

			while (1)//itertarget�� ������������
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