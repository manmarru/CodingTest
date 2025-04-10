#include "pch.h"
#include "Header.h"
#include <vector>

enum WAY { UP, DOWN, NOT, WAY_END };
void Solve(ifstream* _pLoadStream)
{
	/*
	하나 선택하면 한칸 상하좌우에 있는건 선택 못한다. 가장 높은 코스트를 만들어서 출력하기
	원소가 많아서 BFS/DFS같은 탐색 알고리즘은 불가능함
	세로줄 두개 중에 하나 선택 or 선택 안함으로 생각하면 되겠다.

	프로그래밍 대회나 코딩 테스트에서
	"최댓값/최솟값
	"부분 문제로 쪼갤 수 있음"
	"선택이 다음에 영향 줌"
	이런 게 보이면 무조건 DP 의심해 보는 게 좋아.
	*/
	int CaseInput;
	int Size;
	int Input;
	CIN >> CaseInput;
	vector<int> Stickers[3];
	for (int Case = 0; Case < CaseInput; ++Case)
	{
		CIN >> Size;
		Stickers[UP].clear();
		Stickers[DOWN].clear();
		Stickers[NOT].clear();

		Stickers[UP].reserve(Size);
		Stickers[DOWN].reserve(Size);
		Stickers[NOT].resize(Size, 0);

		for (int i = 0; i < Size; ++i)
		{
			CIN >> Input;
			Stickers[UP].push_back(Input);
		}
		for (int i = 0; i < Size; ++i)
		{
			CIN >> Input;
			Stickers[DOWN].push_back(Input);
		}
		for (int i = 1; i < Size; ++i)
		{
			Stickers[UP][i] += max(Stickers[DOWN][i - 1], Stickers[2][i - 1]);
			Stickers[DOWN][i] += max(Stickers[UP][i - 1], Stickers[2][i - 1]);
			Stickers[NOT][i] += max(Stickers[UP][i - 1], Stickers[DOWN][i - 1]);
		}

		
		cout << max(Stickers[UP][Size - 1], Stickers[DOWN][Size - 1]) << '\n';
	}
}