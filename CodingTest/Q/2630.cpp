#include "pch.h"
#include "Header.h"
#include <vector>


vector<vector<int>> vecPaper;//[y][x]
int iResult[2]{ 0 };//ÇÏ¾ç , ÆÄ¶û

bool Check(int _iX, int _iY, int _iSize)
{
	int iColor = vecPaper[_iY][_iX];

	for (int y = _iY; y < _iY + _iSize; ++y)
	{
		for (int x = _iX; x < _iX + _iSize; ++x)
		{
			if (vecPaper[y][x] != iColor)
				return false;
		}
	}

	++iResult[iColor];
	return true;
}

void quad(int _iX, int _iY, int _iSize)
{
	if (!Check(_iX, _iY, _iSize))
	{
		quad(_iX, _iY, _iSize / 2);
	}
	if (!Check(_iX + _iSize, _iY, _iSize))
	{
		quad(_iX + _iSize, _iY, _iSize / 2);
	}
	if (!Check(_iX, _iY + _iSize, _iSize))
	{
		quad(_iX, _iY + _iSize, _iSize / 2);
	}
	if (!Check(_iX + _iSize, _iY + _iSize, _iSize))
	{
		quad(_iX + _iSize, _iY + _iSize, _iSize / 2);
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	1ÀÌ ÆÄ¶û 0 ÀÌ ÇÏ¾ç
	cout << ÆÄ¶õÁ¾ÀÌ °¹¼ö <ÇÏ¾áÁ¾ÀÌ °¹¼ö
	*/
	int iSize;
	CIN >> iSize;
	vecPaper.resize(iSize);
	for (int y = 0; y < iSize; y++)
	{
		vecPaper[y].resize(iSize);
		for (int x = 0; x < iSize; x++)
		{
			CIN >> vecPaper[y][x];
		}
	}

	if (!Check(0, 0, iSize))
	{
		quad(0, 0, iSize / 2);
	}




	cout << iResult[0] << '\n' << iResult[1];
}