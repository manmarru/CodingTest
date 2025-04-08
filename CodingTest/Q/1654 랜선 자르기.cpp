#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>
#include <limits>
vector<int> vecLANs;

int CableCut(int _iSize)
{
	int iResult{ 0 };
	for (int i = 0; i < (int)vecLANs.size(); ++i)
	{
		iResult += int(vecLANs[i] / _iSize);
	}

	return iResult;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	�������� �߶� N�� �̻��� ���� ������ �� �� ������ ���� �� ���� ����
	
	�Ű����� Ž�� + �̺�Ž��

	����� �������� ���� ���̰� 21����� ���ͼ� iLeft + iRight �ϸ� 42����� ���ͼ� int ���� �Ѿ ���� ����
	�׷��� int�� �ƴ϶� long long int ��ߵȴ�.
	*/

#pragma region �Է�

	int iSize{};
	int iNeed{};
	CIN >> iSize >> iNeed;
	vecLANs.resize(iSize);
	for (int i = 0; i < iSize; ++i)
		CIN >> vecLANs[i];
#pragma endregion

	int iTemp;
	int iLeft{ 1 }, iRight{*max_element(vecLANs.begin(), vecLANs.end())};
	int iMid{};
	while (1)
	{
		iMid = (iLeft + iRight) / 2;
		iTemp = CableCut(iMid);

		if (iTemp < iNeed)
		{
			iRight = iMid - 1;
		}
		else if (iTemp >= iNeed)
		{
			iLeft = iMid + 1;
		}
		if (iLeft > iRight)
			break;
	}


	cout << iRight;
}