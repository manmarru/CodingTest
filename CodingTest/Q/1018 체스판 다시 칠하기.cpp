#include "pch.h"
#include "Header.h"
#include <vector>

void Solve(ifstream* _pLoadStream)
{
	/*
	������ ü���ǿ��� ���� ����� 8*8 �κ��� �ڸ���
	�󸶳� �� ��ĥ�ؾ� �ϴ��� ���ϱ�
	*/

	pair<int, int> inputSize{};
	*_pLoadStream >> inputSize.second >> inputSize.first;
	int iMin{64};
	int iTarget{0};
	vector<string> ChessBoard;
	ChessBoard.resize(inputSize.second);
	for (int y = 0; y < inputSize.second; ++y)
	{
		*_pLoadStream >> ChessBoard[y];
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