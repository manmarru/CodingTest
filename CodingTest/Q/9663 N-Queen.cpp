#include "pch.h"
#include "Header.h"
#include <vector>


vector<vector<int>> Board;
int Size;
int Result(0);
void Install(int _x, int _y)
{
	int minX = _x - min(_x, _y);
	int minY = _y - min(_x, _y);
	do
	{
		++Board[minY][minX];
		++minY;
		++minX;
	} while (minX < Size && minY < Size);

	minX = _x + min(Size - _x - 1, _y);
	minY = _y - min(Size - _x - 1, _y);
	do
	{
		++Board[minY][minX];
		++minY;
		--minX;
	} while (minX >= 0 && minY < Size);

	for (int i = 0; i < Size; ++i)
	{
		++Board[i][_x];
	}
	Board[_y][_x] -= 2;
}

void Cleaning(int _x, int _y)
{
	int minX = _x - min(_x, _y);
	int minY = _y - min(_x, _y);
	do
	{
		--Board[minY][minX];
		++minY;
		++minX;
	} while (minX < Size && minY < Size);
	
	minX = _x + min(Size - _x - 1, _y);
	minY = _y - min(Size - _x - 1, _y);
	do
	{
		--Board[minY][minX];
		++minY;
		--minX;
	} while (minX >= 0 && minY < Size);

	for (int i = 0; i < Size; ++i)
	{
		--Board[i][_x];
	}
	Board[_y][_x] += 2;
}

void DFS(int _y, int _Count)
{
	if (_Count == Size)
	{
		++Result;
		return;
	}

	for (int x = 0; x < Size; ++x)
	{
		if (Board[_y][x] == 0)
		{
			Install(x, _y);
			DFS(_y + 1, _Count + 1);
			Cleaning(x, _y);
		}
	}
}

void Solve(ifstream* _pLoadStream)
{
	/*
	N-Queen : ũ�Ⱑ N*N�� ü���� ����  �� N ���� ���� ������ �� ���� ���� ����
	���� ���� ����� ���� ���

	�� �� �غ��� �Ǵ°� �ƴ�? N < [1, 15] �ε� �� �� �ϸ� �ǰڴ�.

	�̷��Ա��� �� �� �ʿ�� ������ �� �밢��, �� �밢���� ���� �����ߴ����� ���� ����ؼ�
	���� ���� ���� ���� �ڸ��� �ε��� + 1 or -1 �ϸ� ���� �࿡�� ���� ������ ĭ���� ������ �ǰ���?
	
	��Ʈ����ŷ ���� 10�� ���� ������.
	*/
	CIN >> Size;
	Board.resize(Size);
	for (int i = 0; i < Size; ++i)
		Board[i].resize(Size, 0);

	DFS(0, 0);

	cout << Result;
}