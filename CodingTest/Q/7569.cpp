#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <array>

struct Coor
{
	int iX;
	int iY;
	int iZ;

	friend Coor operator+(Coor& Temp, Coor& Src)
	{
		return Coor{ Temp.iX + Src.iX, Temp.iY + Src.iY, Temp.iZ + Src.iZ };
	}
	/*
	friend를 넣어야 하는 이유
	+ 연산에는 매개변수가 두개 들간다.
	근데 맴버함수는 자동으로 this가 숨겨진 첫 번째 매개변수로 들가서
	매개변수를 하나 더 받는 셈이 됨
	friend 뺴면 위에 연산자 오버라이딩은 매개변수가 세개 들어가는거임
	그래서 얘는 맴버함수가 아니라는 의미로 friend를 넣는고야
	*/
};

void Solve(ifstream* pLoadStream)
{
	int iSizeX, iSizeY, iSizeZ;
	vector<vector<vector<int>>> vecBox;
	queue<Coor> stlCoor;
	CIN >> iSizeX >> iSizeY >> iSizeZ;
	vecBox.resize(iSizeZ);
	for (int z = 0; z < iSizeZ; z++)
	{
		vecBox[z].resize(iSizeY);
		for (int y = 0; y < iSizeY; y++)
		{
			vecBox[z][y].resize(iSizeX);
			for (int x = 0; x < iSizeX; x++)
			{
				CIN >> vecBox[z][y][x];
				if (vecBox[z][y][x] == 1)
					stlCoor.push({ x, y, z });
			}
		}
	}

	Coor tCurr{}, tDelta{}, tNext{};
	int dX[6]{ 1, -1, 0, 0 , 0, 0};
	int dY[6]{ 0, 0, 1, -1 , 0, 0};
	int dZ[6]{ 0, 0, 0, 0, 1, -1 };
	while (!stlCoor.empty())
	{
		tCurr = stlCoor.front();
		stlCoor.pop();
		for (int i = 0; i < 6; i++)
		{
			tDelta = { dX[i], dY[i], dZ[i] };
			tNext = tCurr + tDelta;
			if (0 > tNext.iX || tNext.iX >= iSizeX || 0 > tNext.iY || tNext.iY >= iSizeY
				|| 0 > tNext.iZ || tNext.iZ >= iSizeZ)
				continue;
			if (0 != vecBox[tNext.iZ][tNext.iY][tNext.iX])
				continue;
			vecBox[tNext.iZ][tNext.iY][tNext.iX] += vecBox[tCurr.iZ][tCurr.iY][tCurr.iX] + 1;
			stlCoor.push(tNext);
		}
	}

	int iMax{ 0 };
	for (int i = 0; i < iSizeZ; i++)
	{
		for (int k = 0; k < iSizeY; k++)
		{
			for (int a = 0; a < iSizeX; a++)
			{
				if (0 == vecBox[i][k][a])
				{
					cout << -1;
					return;
				}
				if (iMax < vecBox[i][k][a])
					iMax = vecBox[i][k][a];
				cout << vecBox[i][k][a] << ' ';
			}
			cout << endl;
		}
		cout << '\n' << '\n';
	}

	cout << iMax -  1 << endl;
}