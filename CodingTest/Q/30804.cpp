#include "pch.h"
#include "Header.h"
#include <list>

void Solve(ifstream* pLoadStream)
{
	/*
		과일 탕후루의 과일 종류가 2개가 되도록 앞이나 뒤에서 과일을 빼기
		종류를 2개로 만들면서 과일을 가장 많이 남기기
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