#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
		k층의 n호에는
		k-1층의 1호부터 n호까지의 주민들의 수의 합만큼의 사람이 살아야 한다.
		0층의 n호에는 n명이 산다.
		첫 입력에 케이스 수, 그다음부터 k, n 순서로 입력

		나중에 점화식으로 푸는 방법을 생각해 볼 것
	*/
	int iInput(0);
	int iFloor(0), iDoor(0);
	*_pLoadStream >> iInput;
	for (int i = 0; i < iInput; ++i)
	{
		*_pLoadStream >> iFloor >> iDoor;

		if (iDoor == 1)
		{
			cout << 1 << endl;
			continue;
		}
		else if (iFloor == 0)
		{
			cout << iDoor << endl;
			continue;
		}
		else // 1층 이상부터임
		{
			vector<vector<int>> vecBoard;
			vecBoard.resize(iFloor + 1);
			for (int i = 0; i < iDoor; ++i)
			{
				vecBoard[0].push_back(i + 1);
			}

			int curPeople(0);
			for (int i = 1; i <= iFloor; ++i)
			{
				curPeople = 0;
				for (int j = 0; j < iDoor; ++j)
				{
					for (int k = 0; k <= j; ++k)
					{
						curPeople += vecBoard[i - 1][k];
					}
					vecBoard[i].push_back(curPeople);
					curPeople = 0;
				}
			}
			cout << vecBoard[iFloor][iDoor - 1] << endl;
			vecBoard.clear();
		}
	}
}


/*
g(x) = n(n+1)/2
1			2			3			4			5			6
1			3			6			10			15			21
1			4			10			20			25			31
1			5			15			35			45			76

*/