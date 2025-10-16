#include "pch.h"
#include "Header.h"
#include <vector>


void Solve(ifstream* _pLoadStream)
{
	//�κм��� �� ���� �� ������� ������ ���̸� ���ϱ�
	/*
	https://www.acmicpc.net/source/94493660
	�� ����ȭ Ǯ��, ������ ���̸� �˸� �Ǵ°Ŵϱ�.
	*/
	int Size;
	CIN >> Size;
	vector<int> Input(Size);
	vector<int> DP(Size, 0);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input[i];
	}
	int Result[3] = { 0, 0, 0};
	
	//dp ����ҰŰ�, n �� �������� �� �� ���ں��� ���� �ֵ� �� ���� ũ�� ��ϵ� dp���� 1 ���Ѱ� �������ָ� �ǰڴ�.
	for (int MainIndex = 0; MainIndex < Size; ++MainIndex)
	{
		fill(DP.begin(), DP.end(), 0);
		DP[MainIndex] = 1;
		Result[0] = 0;
		for (int CurrIndex = MainIndex - 1; CurrIndex >= 0; --CurrIndex) // ����
		{
			int Curr = Input[CurrIndex];
			if (Curr >= Input[MainIndex])
			{
				DP[CurrIndex] = 0;
				continue;
			}
			// ����ȸ�ϸ鼭 Curr ���� ũ��, ���� ���� DP�� ������ �� ã��
			int MaxCnt{ 0 };
			for (int j = CurrIndex + 1; j <= MainIndex; ++j)
			{
				if(Input[CurrIndex] < Input[j])
					MaxCnt = max(DP[j], MaxCnt);
			}
			DP[CurrIndex] = ++MaxCnt;
		}
		for (int i = 0; i <= MainIndex; ++i)
			Result[0] = max(Result[0], DP[i]);

		
		Result[1] = 0;
		//������
		for (int CurrIndex = MainIndex + 1; CurrIndex < Size; ++CurrIndex)
		{
			int Curr = Input[CurrIndex];
			if (Curr >= Input[MainIndex])
			{
				DP[CurrIndex] = 0;
				continue;
			}

			int MaxCnt{ 0 };
			for (int j = CurrIndex - 1; j >= MainIndex; --j)
			{
				if (Input[CurrIndex] < Input[j])
					MaxCnt = max(DP[j], MaxCnt);
			}
			DP[CurrIndex] = ++MaxCnt;
		}
		for (int i = Size - 1; i >= MainIndex; --i)
			Result[1] = max(Result[1], DP[i]);


		Result[2] = max(Result[2], Result[0] + Result[1]);
	}

	cout << Result[2] - 1;
}