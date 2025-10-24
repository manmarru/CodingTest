#include "pch.h"
#include "Header.h"

#include <unordered_map>

#define MAXCOST 100000000
/*
중앙에서 나가는 코스트 2(사실상 처음만)
인접이동 코스트 3
반대편 이동 코스트 4
동일발판 밟는 코스트 1
그리드라기엔 발 위치가 다음 행동에 영향을 주는게 dp같은데?

다른 사람들 풀이 보면 Before After로 안하고 과정을 싹 다 기록한다.
이게 더 빠르긴 한데 메모리 차이가 그만큼 많이 난다. (5배 정도)
*/
enum WAY { MID = 0b00001, UP = 0b00010, LEFT = 0b00100, DOWN = 0b01000, RIGHT = 0b10000, WAY_END = 5 };// 순서는 입력값이랑 동일하다.
const int Way[WAY_END] { MID, UP, LEFT, DOWN, RIGHT };
//						  1   2    4      8      16
void Solve(ifstream* _pLoadStream)
{
	int Input;
	unordered_map<int, int> Before;
	unordered_map<int, int> After;
	unordered_map<int, int> ForCopy;

	ForCopy[MID | UP] = MAXCOST; //3
	ForCopy[MID | LEFT] = MAXCOST; //5
	ForCopy[MID | DOWN] = MAXCOST; //9
	ForCopy[MID | RIGHT] = MAXCOST; //17
	ForCopy[UP | LEFT] = MAXCOST; //6
	ForCopy[UP | DOWN] = MAXCOST; //10
	ForCopy[UP | RIGHT] = MAXCOST; //18
	ForCopy[LEFT | DOWN] = MAXCOST; //12
	ForCopy[LEFT | RIGHT] = MAXCOST; //20
	ForCopy[DOWN | RIGHT] = MAXCOST; //24
	Before = After = ForCopy;

	CIN >> Input;
	After[Way[Input] | MID] = 2;

	for (auto Temp : After)
		cout << Temp.first << " : " << Temp.second << '\n';
	cout << 라인 << endl;


	int Record;
	while (1)
	{
		CIN >> Input;
		if (Input == 0)
			break;

		swap(Before, After);
		After = ForCopy;
		for (auto& Curr : Before)
		{
			if (Curr.second == MAXCOST) // 이전 DP기록이 없으면
				continue;

			if ((Curr.first & Way[Input]) != 0) // 이미 밟고있으면
			{
				After[Curr.first] = min(After[Curr.first], Curr.second + 1);
				continue;
			}

			//for (const int i : Way)
			for(int i = 0; i < 5; ++i)
			{
				if ((Curr.first & (int)pow(2,i)) == 0)
					continue;
				
				Record = (Curr.first ^ (int)pow(2, i)) | Way[Input]; // 발 떼고 다음버튼 밟기

				if ((int)pow(2,i) == MID)
					After[Record] = min(After[Record], Curr.second + 2);
				else if (((Input + i) % 2) == 0) // 반대쪽 발판 밟았으면
					After[Record] = min(After[Record], Curr.second + 4);
				else
					After[Record] = min(After[Record], Curr.second + 3);
			}
		}
		for (auto Temp : After)
			cout << Temp.first << " : " << Temp.second << '\n';
		cout << 라인 << endl;
	}

	int Result{ MAXCOST };
	for (auto Temp : After)
		Result = min(Result, Temp.second);
	cout << Result;
}