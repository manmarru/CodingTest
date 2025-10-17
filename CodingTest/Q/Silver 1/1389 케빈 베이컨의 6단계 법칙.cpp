#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	�ɺ� ������ ���� ���� ���� ����� ã��
	�ɺ� ������ �� = ��� ����� �ɺ� �������� ���� �� ������ �ܰ��� ��
	*/


	int iSize, iLink;
	CIN >> iSize >> iLink;
	vector<vector<int>> vecDIstance;
	vecDIstance.resize(iSize + 1);
	int iInput[2];
	for (int i = 1; i <= iSize; i++)
	{
		vecDIstance[i].resize(iSize + 1);
		fill(vecDIstance[i].begin(), vecDIstance[i].end(), iSize);
		vecDIstance[i][i] = 0;
		vecDIstance[i][0] = 0;
	}
	for (int i = 0; i < iLink; ++i)
	{
		CIN >> iInput[0] >> iInput[1];
		vecDIstance[iInput[0]][iInput[1]] = 1;
		vecDIstance[iInput[1]][iInput[0]] = 1;
	}
	//�ʱ⼼�ó�


	for (int iMid = 1; iMid <= iSize; ++iMid)
	{
		for (int iStart = 1; iStart <= iSize; ++iStart)
		{
			for (int iEnd = 1; iEnd <= iSize; ++iEnd)
			{
				if (vecDIstance[iStart][iEnd] > vecDIstance[iStart][iMid] + vecDIstance[iMid][iEnd])
				{
					vecDIstance[iStart][iEnd] = vecDIstance[iStart][iMid] + vecDIstance[iMid][iEnd];
					vecDIstance[iEnd][iStart] = vecDIstance[iStart][iEnd];
				}
			}
		}
	}

	vector<int> vecKevin(iSize + 1, 0);
	int iMin{iSize * iSize};
	int iResult{ 0 };
	for (int i = 1; i <= iSize; ++i)
	{
		for (int j : vecDIstance[i])
		{
			vecKevin[i] += j;
		}
		if (vecKevin[i] < iMin)
		{
			iResult = i;
			iMin = vecKevin[i];
		}
	}
	cout << iResult;

}