#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
		k���� nȣ����
		k-1���� 1ȣ���� nȣ������ �ֹε��� ���� �ո�ŭ�� ����� ��ƾ� �Ѵ�.
		0���� nȣ���� n���� ���.
		ù �Է¿� ���̽� ��, �״������� k, n ������ �Է�

		���߿� ��ȭ������ Ǫ�� ����� ������ �� ��
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
		else // 1�� �̻������
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