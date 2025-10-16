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
	2ĭ �����ϴ� ��������
	��, ��, 45�� ȸ�� �̵��� �����ϴ�. �밢������ �θ� 4ĭ �����Ѵ�.
	���ϴ� ������ �� �� �ִ� ����� �� ���ϱ�
	
	DP�� ����ҰŶ�� ����б��� �������� ���� ����� �� ���ϴ� ��ó�� �ϸ� �ȴ�.
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

	if (1 == House[Size - 1][Size - 1]) // �������� ����������
	{
		cout << 0;
		return;
	}



	// DFS ����ؼ� ������ �����Ҷ����� ī���� +1
	queue<POINT> Destination;
	POINT Curr;
	Destination.push({ 1, 0, LAY });
	int Result(0);
	bool check[STATE_END]; // ����ִ� ���� = true;
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