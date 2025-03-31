#include "pch.h"
#include "Header.h"
#include <vector>

struct PAPER
{
	int Lx; //�»��
	int Ly;
	int SizeX;
	int SizeY;
};

void Solve(ifstream* _pLoadStream)
{
	/*
	�����̸� ���ļ� �ξ��� �� �� �����̵��� ����Ǵ� ������ ���ϱ�
	�ִ�ũ�� 1001 * 1001
	���� ���������� - + �ϴ°ͺ��� �� �Ѵ����� ��ȸ�ϴ°� �� �����Ͱ���.
	*/

	vector<vector<int>> Ground;
	Ground.resize(1001);
	for (int i = 0; i < 1001; ++i)
		Ground[i].resize(1001, 0);

	int Case;
	PAPER Paper;
	vector<int> Result;
	CIN >> Case;
	++Case;
	Result.resize(Case, 0);
	for (int i = 1; i < Case; i++)
	{
		CIN >> Paper.Lx >> Paper.Ly >> Paper.SizeX >> Paper.SizeY;
		int MaxY = Paper.Ly + Paper.SizeY;
		int MaxX = Paper.Lx + Paper.SizeX;
		for (int y = Paper.Ly; y < MaxY; ++y)
		{
			for (int x = Paper.Lx; x < MaxX; ++x)
			{
				--Result[Ground[y][x]];
				Ground[y][x] = i;
				++Result[i];
			}
		}
	}

	for (int i = 1; i < Case; ++i)
		cout << Result[i] << '\n';
}