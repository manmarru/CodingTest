#include "pch.h"
#include "Header.h"
#include <vector>


void Solve(ifstream* _pLoadStream)
{
	//�κм��� �� ���� �� ������� ������ ���̸� ���ϱ�
	int Size;
	CIN >> Size;
	vector<int> Input(Size);
	vector<int> DP(Size, 0);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input[i];
	}
	
	//dp ����ҰŰ�, n �� �������� �� �� ���ں��� ���� �ֵ� �� ���� ũ�� ��ϵ� dp���� 1 ���Ѱ� �������ָ� �ǰڴ�.
	for (int MainIndex = 0; MainIndex < Size; ++MainIndex)
	{
		DP[MainIndex] = 1;
		int Criteria = Input[MainIndex];
		
		for (int CurrIndex = MainIndex; CurrIndex >= 0; --CurrIndex) // ����
		{
			int Curr = Input[CurrIndex];
			if (Curr > Criteria)
			{
				DP[MainIndex] = 0;
				continue;
			}
			// ����ȸ�ϸ鼭 Curr ���� ũ��, ���� ���� DP�� ������ �� ã��

			int MaxCnt(0);
			for (int j = CurrIndex; j < Criteria; ++j)
			{
				
				MaxCnt = max(DP[j], MaxCnt);
			}
			DP[CurrIndex] = ++MaxCnt;
		}


		for (int i = MainIndex; i < Size; ++i)//������
		{

		}

	}

}