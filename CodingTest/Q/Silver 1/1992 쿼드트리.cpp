#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/1992

+�������� string�� ��ġ�� ""���ٰ� �� string�� ��ġ�°Ŷ� �ð����⵵ ����ؾ� �Ѵ�.
+= ������ ���ʲ��� append�ϴ°Ŷ� �� �� ������.
stringstream�� >> ������ �ϸ� �޸� ������ �ɲ� �� ȿ�����̰� ���ֱ� �Ѵ�.
ostringstream�� ����ϴ� �͵� ����ؾ� �Ѵ�.
*/


vector<vector<char>> Tiles;
string Quad(int StartY, int StartX, int Size)
{
	if (Size == 1)
	{
		return { Tiles[StartY][StartX] };
	}

	string Targets[4] = {
		Quad(StartY, StartX, Size / 2)
		, Quad(StartY, StartX + Size / 2, Size / 2)
		, Quad(StartY + Size / 2, StartX, Size / 2)
		, Quad(StartY + Size / 2, StartX + Size / 2, Size / 2) };
	
	if (Targets[0].length() == 1
		&& Targets[0] == Targets[1] && Targets[0] == Targets[2] && Targets[0] == Targets[3])
	{
		return Targets[0];
	}

	string Temp = "";
	for (int i = 0; i < 4; ++i)
	{
		if (Targets[i].length() != 1)
		{
			Temp += '(';
			Temp += Targets[i];
			Temp += ')';
		}
		else
			Temp += Targets[i];
	}
	return Temp;
}

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	Tiles.resize(Size, vector<char>(Size));

	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Tiles[y][x];
		}
	}
	
	string Answer = Quad(0, 0, Size);
	if (Answer.length() == 1)
		cout << Answer;
	else
		cout << '(' <<  Answer << ')';
}