#include "pch.h"
#include "Header.h"
#include <list>

void Solve(ifstream* pLoadStream)
{
	/*
		���� ���ķ��� ���� ������ 2���� �ǵ��� ���̳� �ڿ��� ������ ����
		������ 2���� ����鼭 ������ ���� ���� �����
	*/

	int iSize;
	CIN >> iSize;
	int iInput;
	int iResult{ 0 };
	int iFruit[10]{ 0 };
	int iType{ 0 };

	list<int> listSkewer;
	for (int i = 0; i < iSize; ++i)
	{
		CIN >> iInput;
		listSkewer.push_back(iInput);
		if (0 == iFruit[iInput])
			++iType;
		++iFruit[iInput];

		while (iType > 2)
		{
			--iFruit[listSkewer.front()];
			if (0 == iFruit[listSkewer.front()])
				--iType;
			listSkewer.pop_front();
		}
		iResult = max(iResult, (int)listSkewer.size());
	}

	cout << iResult;
}