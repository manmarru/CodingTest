#include "pch.h"
#include "Header.h"
#include <vector>
#include <stack>
/*
���� 3�� ������ ����� ū ���� ������ ���� �ִ�ġ ���ϱ�
��Ʈ��ŷ���� �� ��ƺ��� �׶� �������밡  ��� �������� ���غ��°ɷ� Ǯ����.
������ �ִ� 8*8 ������ �ӵ��� �� ������ ���´�.
*/
int SizeX, SizeY;
stack<pair<int, int>> Picked;//y, x
vector<vector<int>> Field;

int Track()
{
	vector<vector<int>> Copy = Field;
	stack<pair<int, int>> Destination;
	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			if (Copy[y][x] == 2)
			{
				Destination.push({ y, x });
			}
		}
	}

	pair<int, int> Curr;
	while (!Destination.empty())
	{
		Curr = Destination.top();
		Destination.pop();

		if (Curr.first > 0 && Copy[Curr.first - 1][Curr.second] == 0)
		{
			Destination.push({ Curr.first - 1, Curr.second });
			Copy[Curr.first - 1][Curr.second] = 2;
		}
		if (Curr.first < SizeY - 1 && Copy[Curr.first + 1][Curr.second] == 0)
		{
			Destination.push({ Curr.first + 1, Curr.second });
			Copy[Curr.first + 1][Curr.second] = 2;
		}
		if (Curr.second > 0 && Copy[Curr.first][Curr.second - 1] == 0)
		{
			Destination.push({ Curr.first, Curr.second - 1 });
			Copy[Curr.first][Curr.second - 1] = 2;
		}
		if (Curr.second < SizeX - 1 && Copy[Curr.first][Curr.second + 1] == 0)
		{
			Destination.push({ Curr.first, Curr.second + 1 });
			Copy[Curr.first][Curr.second + 1] = 2;
		}
	}
	
	int Cnt{ 0 };
	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			if (Copy[y][x] == 0)
			{
				++Cnt;
			}
		}
	}

	return Cnt;
}

int PICK(int Pick)
{
	if (Pick == 3)
	{
		return Track();
	}

	int Result{ 0 };

	pair<int, int>Curr{ Picked.top() };
	for (int y = Curr.first; y < SizeY; ++y)
	{
		for (int x = Curr.second; x < SizeX; ++x)
		{
			if (Field[y][x] == 0)
			{
				Picked.push({ y, x });
				Field[y][x] = 1;
				Result = max(Result, PICK(Pick + 1));
				Field[y][x] = 0;
				Picked.pop();
			}
		}
		Curr.second = 0;
	}

	return Result;
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> SizeY >> SizeX;
	Field.resize(SizeY, vector<int>(SizeX));
	for (int y = 0; y < SizeY; ++y)
	{
		for (int x = 0; x < SizeX; ++x)
		{
			CIN >> Field[y][x];
		}
	}
	//=======�Է³�=========
	Picked.push({ 0, 0 });
	cout << PICK(0);


}