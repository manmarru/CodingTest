#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>

/*
https://www.acmicpc.net/problem/3190
ㅇㅋ이정도면 잘함
근데 마구 구현하다가 가독성이 떨어지는 부분은 약간 보이긴 하네
*/

#define Y 0
#define X 1

enum ATT { EMPTY, SNAKE, APPLE};
int Size;
vector<vector<ATT>> History;
const int dY[4]{ -1, 0, 1, 0 }; // 상 우 하 좌
const int dX[4]{ 0, 1, 0, -1 };
queue<pair<int, int>> Snake;

int Turn(int CurDir, char Input)
{
	CurDir += Input == 'D' ? 1 : 3;
	return CurDir % 4;
}

void Debug(vector<vector<ATT>>& Temp)
{
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			cout << History[y][x] << '\t';
		}
		cout << '\n';
	}
	라인프린트;
}

bool SMove(int HeadDir) // false == 종료
{
	pair<int, int> Next = { Snake.back().first + dY[HeadDir], Snake.back().second + dX[HeadDir] };

	if (Next.first < 0 || Next.first >= Size || Next.second < 0 || Next.second >= Size)
	{
		return false;
	}

	ATT Att = History[Next.first][Next.second];
	if (Att == EMPTY)
	{
		History[Snake.front().first][Snake.front().second] = EMPTY;
		Snake.pop();
	}
	else if (Att == SNAKE)
	{
		return false;
	}
	Snake.push(Next);
	History[Next.first][Next.second] = SNAKE;

	return true;
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Size;
	History.resize(Size, vector<ATT>(Size, EMPTY));
	History[0][0] = SNAKE;

	int AppleSize;
	CIN >> AppleSize;
	int Input[2];
	for (int i = 0; i < AppleSize; ++i)
	{
		CIN >> Input[Y] >> Input[X];
		History[Input[Y] - 1][Input[X] - 1] = APPLE;
	}
	int DirSize;
	CIN >> DirSize;
	Snake.push({ 0, 0 });

	int TimeInput;
	int CurTime = 0;
	int HeadDir = 1;
	pair<int, int> Next;
	cout << CurTime << endl;
	Debug(History);
	for (int i = 0; i < DirSize; ++i)
	{
		ATT Att;
		CIN >> TimeInput;
		while(CurTime < TimeInput)
		{
			++CurTime;
			if (false == SMove(HeadDir))
			{
				cout << CurTime;
				return;
			}
			cout << CurTime << endl;
			Debug(History);
		}
		char DirInput;
		CIN >> DirInput;
		HeadDir = Turn(HeadDir, DirInput);
	}

	do 
	{
		++CurTime;
	} while (SMove(HeadDir));

	cout << CurTime;

	return;
}