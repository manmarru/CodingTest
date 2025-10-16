#include "pch.h"
#include "Header.h"
#include <vector>
#include <limits>
#define MAXSIZE 300001

void Solve(ifstream* _pLoadStream)
{
	int Size, Case;
	CIN >> Size;
	++Size;
	vector<vector<int>> Floyd(Size);
	for (int i = 0; i < Size; ++i)
		Floyd[i].resize(Size, MAXSIZE);
	CIN >> Case;
	int Input[3];
	for (int i = 0; i < Case; ++i) // 동일한 경로 노선이  한개가 아닐 수 있다.
	{
		CIN >> Input[0] >> Input[1];
		CIN >> Input[2];
		Floyd[Input[0]][Input[1]] = min(Floyd[Input[0]][Input[1]], Input[2]);
	}

	for (int y = 1; y < Size; ++y)
	{
		Floyd[y][y] = 0;
	}

	for (int Mid = 1; Mid < Size; ++Mid)
	{
		for (int Start = 1; Start < Size; ++Start)
		{
			for (int End = 1; End < Size; ++End)
			{
				Floyd[Start][End] = min(Floyd[Start][End], Floyd[Start][Mid] + Floyd[Mid][End]);
			}
		}
	}


	for (int y = 1; y < Size; ++y)
	{
		for (int x = 1; x < Size; ++x)
		{
			cout << (Floyd[y][x] == MAXSIZE ? 0 : Floyd[y][x]) << ' ';
		}
		cout << '\n';
	}
}