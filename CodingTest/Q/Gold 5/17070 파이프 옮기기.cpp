#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

enum STATE { LAY, STAND, LEAN, STATE_END };
struct POINT
{
	int x;
	int y;
	STATE State;
};
void Solve(ifstream* _pLoadStream)
{
	/*
	2칸 차지하는 파이프를
	우, 하, 45도 회전 이동이 가능하다. 대각선으로 두면 4칸 차지한다.
	우하단 끝으로 갈 수 있는 경우의 수 구하기
	
	DP를 사용할거라면 고등학교때 목적지로 가는 경우의 수 구하던 것처럼 하면 된다.
	*/
	int Size;
	CIN >> Size;
	vector<vector<int>> House(Size);
	int Input;
	for (int y = 0; y < Size; ++y)
	{
		House[y].reserve(Size);
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Input;
			House[y].push_back(Input);
		}
	}

	if (1 == House[Size - 1][Size - 1]) // 목적지가 막혀있으면
	{
		cout << 0;
		return;
	}



	// DFS 사용해서 목적지 도착할때마다 카운팅 +1
	queue<POINT> Destination;
	POINT Curr;
	Destination.push({ 1, 0, LAY });
	int Result(0);
	bool check[STATE_END]; // 비어있는 방향 = true;
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();
		if (Curr.x == Size - 1 && Curr.y == Size - 1)
		{
			++Result;
			continue;
		}
		
		check[LAY] = ((Curr.x != Size - 1) && (House[Curr.y][Curr.x + 1] != 1));
		check[STAND] = ((Curr.y != Size - 1) && (House[Curr.y + 1][Curr.x] != 1));
		check[LEAN] = ((check[LAY] && check[STAND]) && (House[Curr.y + 1][Curr.x + 1] != 1));


		switch (Curr.State)
		{
		case LAY:
		{
			if (check[LAY])
				Destination.push({ Curr.x + 1, Curr.y, LAY });
			break;
		}
		case STAND:
		{
			if (check[STAND])
				Destination.push({ Curr.x, Curr.y + 1, STAND });
			break;
		}
		case LEAN:
		{
			if (check[LAY])
				Destination.push({ Curr.x + 1, Curr.y, LAY });
			if (check[STAND])
				Destination.push({ Curr.x, Curr.y + 1, STAND });
			break;
		}
		}
		if (check[LEAN])
			Destination.push({ Curr.x + 1, Curr.y + 1, LEAN });
	}

	cout << Result;
}