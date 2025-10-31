#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>
#include <queue>

/*
https://www.acmicpc.net/problem/2109
테스트케이스 그지같이 주네 요청 갯수가 0인 케이스가 왜 존재하는거냐?


https://www.acmicpc.net/source/99795485
엄청 간결한 코드
여기서는 그냥 다 넣는다. 넣으면서 날짜보다 큐 크기가 더 크면
큐에서 하나씩 뺀다. 따라서 큐의 앞에 오는건 단가가 낮은 강의임
그러면 그냥 다 넣고 하나씩 뺴면서 스케줄 짜고,
마지막에 큐 비우면서 코스트 합하면 끝난다.

시간복잡도는 나랑 비슷한데 코드가 간결해지고 과정이 단순하다.
*/


struct REQUEST
{
	int Cost;
	int DeadLine;
	bool operator < (const REQUEST& Temp) const
	{
		return Cost < Temp.Cost;
	}
};

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	if (Size == 0) // ㅅㅂ 이런케이스를 왜 주는거임
	{
		cout << 0;
		return;
	}

	vector<REQUEST> Requests(Size);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Requests[i].Cost >> Requests[i].DeadLine;
	}
	
	sort(Requests.begin(), Requests.end(), [](REQUEST Temp, REQUEST Src)
		{
			return Temp.DeadLine < Src.DeadLine;
		});
	priority_queue<REQUEST> Q;
	int Result = 0;
	int Cursor = Size - 1;

	int Day = Requests.back().DeadLine;
	while (Day > 0)
	{
		while (Cursor >= 0)
		{
			if (Requests[Cursor].DeadLine < Day)
				break;

			Q.push(Requests[Cursor]);
			--Cursor;
		}

		if (Q.empty())
		{
			--Day; // Day = Requests[Cursor].DeadLine; 으로 하면 루프 줄어들겠다.
			continue;
		}

		--Day;
		Result += Q.top().Cost;
		Q.pop();
	}

	cout << Result;
}