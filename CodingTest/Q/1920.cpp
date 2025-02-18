#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <unordered_set>
void Solve(ifstream* pLoadStream)
{
	/*
		���� �ȿ� ���ڰ� ����ִ��� ����ϱ�
	*/

	/*
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
	�����Ҷ��� �̰� �־�� �ȴ�.
	*/
	���������ȭ

	int iSize{};
	int iNum;
	vector<int> vecNums;
	*pLoadStream >> iSize;
	vecNums.resize(iSize);
	for (int i = 0; i < iSize; ++i)
	{
		*pLoadStream >> vecNums[i];
	}
	sort(vecNums.begin(), vecNums.end());

	int iLeft{ 0 };
	int iRight{ 0 };
	int iMid;
	*pLoadStream >> iSize;
	for (int i = 0; i < iSize; ++i)
	{
		*pLoadStream >> iNum;
		iLeft = 0;
		iRight = (int)vecNums.size() - 1;

		while (1)
		{
			iMid = (int)((iLeft + iRight) / 2);
			if (vecNums[iMid] == iNum)
			{
				cout << 1 << '\n';
				break;
			}
			else if (iNum > vecNums[iMid])
			{
				iLeft = iMid + 1;
			}
			else
			{
				iRight = iMid - 1;
			}
			if (iLeft > iRight)
			{
				cout << 0 << '\n';
				break;
			}
		}
	}
}