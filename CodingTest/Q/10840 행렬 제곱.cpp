#include "pch.h"
#include "Header.h"
#include <vector>


int Size;
vector<vector<int>> mult(vector<vector<int>>& _Amatrix, vector<vector<int>>& _Bmatrix)
{
	vector<vector<int>> Result;
	for (int i = 0; i = Size; ++i)
	{
		Result.resize(Size);
		for (int j = 0; j < Size; ++j)
		{
			Result[i].resize(Size, 0);
		}
	}

	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			for (int i = 0; i < Size; ++i)
			{
				Result[y][x] += _Amatrix[y][i] * _Bmatrix[i][x];
				Result[y][x] %= 1000;
			}
		}
	}

	return Result;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	��� A�� B ���� ���ϱ�
	1 <= A <= 5
	1 <= B <= õ��
	*/
	long long int Input;
	CIN >> Size >> Input;
	
	vector<vector<int>> Matrix(Size);
	for (int i = 0; i < Size; ++i)
	{
		Matrix.resize(Size);
		for (int j = 0; j < Size; ++j)
		{
			CIN >> Matrix[i][j];
		}
	}
	
	long long int Curr;
	/*
	��...�ϴ� �ɰ��ߵɰŰ�����
	B = B1 + B2
	B1 = B3 + B4 �̷�������
	
	*/
	

}