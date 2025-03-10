#include "pch.h"
#include "Header.h"
#include <vector>

int SizeY, SizeX;
vector<vector<int>> Board;
int Max{ 0 };
void MaxCheck(int _Temp)
{
	Max = max(Max, _Temp);
}
void I() //2����
{
	int Temp;
	for (int y = 0; y < SizeY; ++y)
	{
		Temp = Board[y][0] + Board[y][1] + Board[y][2] + Board[y][3];
		MaxCheck(Temp);
		for (int x = 4; x < SizeX; x++)
		{
			Temp += Board[y][x] - Board[y][x - 4];
			MaxCheck(Temp);
		}
	}

	for (int x = 0; x < SizeX; ++x)
	{
		Temp = Board[0][x] + Board[1][x] + Board[2][x] + Board[3][x];
		MaxCheck(Temp);
		for (int y = 4; y < SizeY; y++)
		{
			Temp += Board[y][x] - Board[y - 4][x];
			MaxCheck(Temp);
		}
	}
}
void L() // 8����
{
	int Temp{ 0 };
	//����
	for (int y = 0; y < SizeY - 2; y++)
	{
		for (int x = 0; x < SizeX - 1; x++)
		{
			Temp = Board[y][x] + Board[y][x + 1] + Board[y + 1][x] + Board[y + 1][x + 1] + Board[y + 2][x] +  Board[y + 2][x + 1];
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					MaxCheck(Temp - Board[y + i][x + j] - Board[y + i + 1][x + j]);
				}
			}
		}
	}
	//����
	for (int y = 0; y < SizeY - 1; y++)
	{
		for (int x = 0; x < SizeX - 2; x++)
		{
			Temp = Board[y][x] + Board[y][x + 1] + Board[y][x + 2] + Board[y + 1][x] + Board[y + 1][x + 1] + Board[y + 1][x + 2];
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					MaxCheck(Temp - Board[y + i][x + j] - Board[y + i][x + j + 1]);
				}
			}
		}
	}
}
void Z() // 4����
{
	int Temp;
	//����
	for (int y = 0; y < SizeY - 2; y++)
	{
		for (int x = 0; x < SizeX - 1; x++)
		{
			Temp = Board[y + 1][x + 1] + Board[y + 1][x];
			MaxCheck(Temp + Board[y][x] + Board[y + 2][x + 1]);
			MaxCheck(Temp + Board[y][x + 1] + Board[y + 2][x]);
		}
	}
	//����
	for (int y = 0; y < SizeY - 1; y++)
	{
		for (int x = 0; x < SizeX - 2; x++)
		{
			Temp = Board[y][x + 1] + Board[y + 1][x + 1];
			MaxCheck(Temp + Board[y][x] + Board[y + 1][x + 2]);
			MaxCheck(Temp + Board[y + 1][x] + Board[y][x + 2]);
		}
	}
}
void T() // 4����
{
	int Temp;
	//����
	for (int y = 0; y < SizeY - 2; y++)
	{
		for (int x = 0; x < SizeX - 1; x++)
		{
			Temp = Board[y + 1][x] + Board[y + 1][x + 1];
			MaxCheck(Temp + Board[y][x] + Board[y + 2][x]);
			MaxCheck(Temp + Board[y][x + 1] + Board[y + 2][x + 1]);
		}
	}
	//����
	for (int y = 0; y < SizeY - 1; y++)
	{
		for (int x = 0; x < SizeX - 2; x++)
		{
			Temp = Board[y][x + 1] + Board[y + 1][x + 1];
			MaxCheck(Temp + Board[y][x] + Board[y][x + 2]);
			MaxCheck(Temp + Board[y + 1][x] + Board[y + 1][x + 2]);
		}
	}
}
void O() //�׸�� 1����
{
	for (int y = 0; y < SizeY - 1; y++)
	{
		for (int x = 0; x < SizeX - 1; x++)
		{
			MaxCheck(Board[y][x] + Board[y][x + 1] + Board[y + 1][x] + Board[y + 1][x + 1]);
		}
	}
}

void Solve(ifstream* pLoadStream)
{
	/*
	�����ǿ� �׸���̳� �ϳ��� ���Ƽ�
	�÷��� ĭ�� ���ڵ��� ���� ���� ū ��츦 ���ϱ�
	ȸ��, ��Ī ����
	*/

	CIN >> SizeY >> SizeX;
	Board.resize(SizeY);
	for (int y = 0; y < SizeY; y++)
	{
		Board[y].resize(SizeX);
		for (int x = 0; x < SizeX; x++)
		{
			CIN >> Board[y][x];
		}
	}

	I();
	L();
	Z();
	T();
	O();
	cout << Max;
}