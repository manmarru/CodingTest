#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	N*N ���ں���
	(A,B)����(C,D) ������ ���� ���ϱ�
	���ѤѤѤѤѤѤѤѤѤѤѤѷ��⹮���ĤĤĤĤĤĤ�
	*/
	int Size;
	int Case;
	int Input;
	vector<vector<int>> Board;
	CIN >> Size >> Case;
	Size += 1;
	Board.resize(Size);
	Board[0].resize(Size, 0);

	for (int y = 1; y < Size; ++y)
	{
		Board[y].reserve(Size);
		Board[y].push_back(0);
		for (int x = 1; x < Size; ++x)
		{
			CIN >> Input;
			Board[y].push_back(Input);
		}
	}

	for (int y = 1; y < Size; ++y)
	{
		for (int x = 1; x < Size; ++x)
		{
			Board[y][x] += Board[y - 1][x] + Board[y][x - 1] - Board[y - 1][x - 1];
		}
	}

	int First[2], Second[2];
	for (int i = 0; i < Case; ++i)
	{
		CIN >> First[0] >> First[1] >> Second[0] >> Second[1];
		cout << Board[Second[0]][Second[1]]
			- Board[First[0] - 1][Second[1]] - Board[Second[0]][First[1] - 1]
			+ Board[First[0] - 1][First[1] - 1] << '\n';
	}

}