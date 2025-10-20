#include "pch.h"
#include "Header.h"
#include <vector>

#define X 1
#define Y 0
void Solve(ifstream* _pLoadStream)
{
	/*
	�־��� ũ���� ������ ���� ����� �� �ɸ��� �ּ� �ð�, �� ���� ���
	���ı� = 2��, ����� = 1��
	�ѹ��� ������ �� �ǳʶٴ� ���� Ž���� �Ұ�����
	���ݾ� �ǳʶپ��µ� ���� �ʰ��� ������ �����ϸ� �ڷ� �����ư���.
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

	int iMinTime{ 2147483647 };//�ִ�ð� 1��2õ
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
				if (Act < 0) // ��� ����
				{
					iCurTime -= Act;
				}
				else // �� ��
				{
					iCurTime += Act * 2;
				}
				iCurblock += Act;
			}
		}

		if (iCurblock < 0)
			continue;

		if (iCurTime <= iMinTime) //�������鼭 ���س��̰� ���� �������� ������ ���� �ð��̸� �����ϸ� ��
		{
			iMinTime = iCurTime;
			iResult = i;
		}
	}


	//�ð� >> ���� ��� (���� �������� ���߿� ���̰� ���� ������ ���)
	cout << iMinTime << ' ' << iResult;
}