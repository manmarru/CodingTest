#include "pch.h"
#include "Header.h"
#include <vector>

#define X 1
#define Y 0
void Solve(ifstream* _pLoadStream)
{
	/*
	주어진 크기의 평평한 땅을 만드는 데 걸리는 최소 시간, 땅 높이 출력
	땅파기 = 2초, 땅깔기 = 1초
	한번에 앞쪽을 다 건너뛰는 이진 탐색은 불가능함
	절반씩 건너뛰었는데 한참 초과로 조건을 만족하면 뒤로 못돌아간다.
	*/

	int iSize[2];
	int iBlock;
	CIN >> iSize[Y] >> iSize[X] >> iBlock;
	int iMax{ 0 };

	vector<vector<int>> vecField;
	vecField.resize(iSize[Y]);
	
	for (int y = 0; y < iSize[Y]; y++)
	{
		vecField[y].resize(iSize[X]);
		for (int x = 0; x < iSize[X]; x++)
		{
			CIN >> vecField[y][x];
			if (iMax < vecField[y][x])
				iMax = vecField[y][x];
		}
	}

	int iMinTime{ 2147483647 };//최대시간 1억2천
	int iResult{ 0 };
	int iCurTime{};
	int iCurblock{};
	for (int i = 0; i <= iMax; ++i)
	{
		iCurTime = 0;
		iCurblock = iBlock;
		for (int y = 0; y < iSize[Y]; y++)
		{
			for (int x = 0; x < iSize[X]; x++)
			{
				int Act = vecField[y][x] - i;
				if (Act < 0) // 블록 쌓음
				{
					iCurTime -= Act;
				}
				else // 땅 팜
				{
					iCurTime += Act * 2;
				}
				iCurblock += Act;
			}
		}

		if (iCurblock < 0)
			continue;

		if (iCurTime <= iMinTime) //루프돌면서 기준높이가 점점 높아지기 때문에 같은 시간이면 갱신하면 됨
		{
			iMinTime = iCurTime;
			iResult = i;
		}
	}


	//시간 >> 높이 출력 (답이 여러개면 그중에 높이가 높은 땅으로 출력)
	cout << iMinTime << ' ' << iResult;
}