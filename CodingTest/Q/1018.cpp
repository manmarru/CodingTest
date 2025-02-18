#include "pch.h"
#include "Header.h"

void Solve(ifstream* pLoadStream)
{
	/*
	망가진 체스판에서 가장 비슷한 8*8 부분을 자르고
	얼마나 더 색칠해야 하는지 구하기
	*/

	pair<int, int> inputSize{};
	*pLoadStream >> inputSize.second >> inputSize.first;
	int iMin{64};
	int iTarget{0};
	vector<string> ChessBoard;
	ChessBoard.resize(inputSize.second);
	for (int y = 0; y < inputSize.second; ++y)
	{
		*pLoadStream >> ChessBoard[y];
		cout << ChessBoard[y] << endl;
	}


	for (int y = 0; y < inputSize.second - 7; ++y)
	{
		for (int x = 0; x < inputSize.first - 7; ++x)
		{
			iTarget = 0;
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					if ((i + j) % 2 == 0)
						iTarget += (int)ChessBoard[y + i][x + j] == 'B';
					else
						iTarget += (int)ChessBoard[y + i][x + j] == 'W';
				}
			}
			if (iTarget > 32)
 				iTarget = 64 - iTarget;
			iMin = min(iMin, iTarget);
		}
	}

	cout << iMin;
}