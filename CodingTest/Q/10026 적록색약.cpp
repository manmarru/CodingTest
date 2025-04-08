#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#define 넘겨 continue
#define 삽입 push
#define 참 true
#define 거짓 false

pair<int, int> operator+(pair<int, int> &Temp, pair<int, int> &Src)
{
	return { Temp.first + Src.first, Temp.second + Src.second };
}

void Solve(ifstream* _pLoadStream)
{
	/*
	RGB로 이루어진 그림판에서 같은 색 집합의 갯수 찾기
	단, 색맹용 그림판은 R == G
	레전드 한글코딩
	*/
	int 입력크기;
	int 결과[2]{ 0, 0 };
	CIN >> 입력크기;

	vector<vector<char>> 그림판(입력크기);
	vector<vector<char>> 색맹그림판(입력크기);
	vector<vector<bool>> 방문기록[2];
	queue<pair<int, int>> 방문예정;
	방문기록[0].resize(입력크기);
	방문기록[1].resize(입력크기);
	for (int ㄱ = 0; ㄱ < 입력크기; ㄱ++)
	{
		그림판[ㄱ].resize(입력크기);
		색맹그림판[ㄱ].resize(입력크기);
		방문기록[0][ㄱ].resize(입력크기);
		방문기록[1][ㄱ].resize(입력크기);
		fill(방문기록[0][ㄱ].begin(), 방문기록[0][ㄱ].end(), false);
		fill(방문기록[1][ㄱ].begin(), 방문기록[1][ㄱ].end(), false);
		for (int ㄴ = 0; ㄴ < 입력크기; ㄴ++)
		{
			CIN >> 그림판[ㄱ][ㄴ];
			색맹그림판[ㄱ][ㄴ] = 그림판[ㄱ][ㄴ] == 'R' ? 'G' : 그림판[ㄱ][ㄴ];
		}
	}

	pair<int, int> 현재위치, 다음위치;
	pair<int, int> 방향[4]{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	for (int y = 0; y < 입력크기; ++y)
	{
		for (int x = 0; x < 입력크기; x++)
		{
			if (방문기록[0][y][x])
				넘겨;
			방문예정.삽입({ y,x });
			방문기록[0][y][x] = 참;
			++결과[0];
			while (!방문예정.empty())
			{
				현재위치 = 방문예정.front();
				방문예정.pop();
				for (int ㄱ = 0; ㄱ < 4; ㄱ++)
				{
					다음위치 = 현재위치 + 방향[ㄱ];
					if (다음위치.first < 0 || 다음위치.first >= 입력크기
						|| 다음위치.second < 0 || 다음위치.second >= 입력크기)
						넘겨;
					if (방문기록[0][다음위치.first][다음위치.second])
						넘겨;
					if (그림판[다음위치.first][다음위치.second] != 그림판[현재위치.first][현재위치.second])
						넘겨;
					방문기록[0][다음위치.first][다음위치.second] = 참;
					방문예정.삽입({다음위치.first, 다음위치.second});
				}
			}
		}
	}

	for (int y = 0; y < 입력크기; ++y)
	{
		for (int x = 0; x < 입력크기; x++)
		{
			if (방문기록[1][y][x])
				넘겨;
			방문예정.삽입({ y,x });
			방문기록[1][y][x] = 참;
			++결과[1];
			while (!방문예정.empty())
			{
				현재위치 = 방문예정.front();
				방문예정.pop();
				for (int ㄱ = 0; ㄱ < 4; ㄱ++)
				{
					다음위치 = 현재위치 + 방향[ㄱ];
					if (다음위치.first < 0 || 다음위치.first >= 입력크기
						|| 다음위치.second < 0 || 다음위치.second >= 입력크기)
						넘겨;
					if (방문기록[1][다음위치.first][다음위치.second])
						넘겨;

					if (색맹그림판[다음위치.first][다음위치.second] != 색맹그림판[현재위치.first][현재위치.second])
						넘겨;

					방문기록[1][다음위치.first][다음위치.second] = 참;
					방문예정.삽입({ 다음위치.first, 다음위치.second });
				}
			}
		}
	}

	cout << 결과[0] << ' ' << 결과[1];
}