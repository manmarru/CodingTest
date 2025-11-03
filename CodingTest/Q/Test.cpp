#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;

	vector<vector<int>> result(Size);
	bool Direction;
	int Num{ 0 };
	int y{ 0 };
	int Line{ 1 };
	int LineCnt{ 0 };
	int LineDir{ 1 };
	int Dir{ -1 };

	for (int i = 0; i < Size * Size; ++i)
	{
		result[y].push_back(Num);
		y += Dir;
		++LineCnt;

		if (LineCnt == Line)
		{
			Line += LineDir;
			if (Line == Size)
				LineDir *= -1;
			LineCnt = 0;
			Dir *= -1;
			++Num;
			if (y == -1)
				y = 0;
		}
		else
		{
			Num += 2;
		}



	}





	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
			cout << result[y][x] << '\t';
		cout << endl;
	}
}