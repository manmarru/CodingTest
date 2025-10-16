#include "pch.h"
#include "Header.h"
#include <vector>

struct OBJ
{
	int y, x;
};

vector<OBJ> Houses;
vector<OBJ> Stores;

vector<bool> Picked;
int Result(99999);
int StoreSize;

void DFS(int Before, int More) // 이전 루프에서 Before인덱스를 골랐고 More 만큼 더 선택 가능
{
	if (0 == More)
	{
		// 계산 후 result 갱신
		int Sum(0);
		int Less;
		for (OBJ House : Houses)
		{
			Less = 99999;
			for (int i = 0; i < StoreSize; ++i)
			{
				if (Picked[i])
				{
					Less = min(Less, abs(House.x - Stores[i].x) + abs(House.y - Stores[i].y));
				}
			}
			Sum += Less;
		}

		Result = min(Result, Sum);
		cout << Sum << endl;
		return;
	}
	
	for (int i = Before + 1; i < StoreSize; ++i)
	{
		if (!Picked[i])
		{
			Picked[i] = true;
			DFS(i, More - 1);
			Picked[i] = false;
		}
	}

	return;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	y,x 로 치킨가게와 집의 좌표가 주어짐 (1 <= y, x)

	치킨집과 집의 거리는 Dy + Dx 이다.

	치킨집들 중 최대 M개를 선택해서 치킨집과의 거리의 합이 최소가 되게 해야 함.

	거리 기반으로 하나씩 빼보는건 의미가 없을거같은데? 걍 모든 조합 다 해봐야 알듯?

	m개를 선택했을 때 치킨포인트 총합을 전부 계산해보는게 맞을듯
	*/

	int Size, Pick;

	CIN >> Size >> Pick;
	int Input;
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Input;

			if (Input == 1)
			{
				Houses.push_back({ y, x });
			}
			else if (Input == 2)
			{
				Stores.push_back({ y, x });
			}
		}
	}
	Picked.resize(Stores.size(), false);
	StoreSize = Stores.size();
	// 입력은 끝난 상태, Houses와 Stores 도 다 채워줬다.

	DFS(-1, Pick); // -1을 선택했고(암것도 아직 안골랐으니까) Pick개 더 선택 가능
	cout << Result << endl;
}