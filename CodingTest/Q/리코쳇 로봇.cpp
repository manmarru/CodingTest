#include "pch.h"
#include "Header.h"

#include <string>
#include <vector>
#include <queue>

using namespace std;


/*
코드가 좀 긴 거 빼고는 ㄱㅊ
코드 줄이려면 4방향 COOR 배열을 만들고 4번 루프하는거 알지?
그거만 줄여도 20줄은 줄어든다.
*/

struct COOR
{
    int x;
    int y;
};

int SizeX;
int SizeY;
void Move(COOR& Result, COOR Way, vector<string>& board)
{
    int x = Result.x;
    int y = Result.y;
    while ('.' == board[y][x])
    {
        x += Way.x; y += Way.y;

        if (y < 0 || x < 0 || y >= SizeY || x >= SizeX || board[y][x] == 'D')
        {
            Result.x = x - Way.x;
            Result.y = y - Way.y;
            return;
        }
    }
}

int solution(vector<string> board)
{
    SizeX = board[0].size();
    SizeY = board.size();

    COOR Start;
    COOR Goal;
    for (int y = 0; y < SizeY; ++y)
    {
        for (int x = 0; x < SizeX; ++x)
        {
            if ('R' == board[y][x])
            {
                Start.y = y;
                Start.x = x;
                board[y][x] = '.';
            }
            else if ('G' == board[y][x])
            {
                Goal.y = y;
                Goal.x = x;
                board[y][x] = '.';
            }
        }
    }

    queue<COOR> Destination;
    queue<COOR> Next;
    vector<vector<bool>> History(SizeY, vector<bool>(SizeX, false));
    int answer = 0;

    Next.push(Start);
    History[Start.y][Start.x] = true;
    COOR Curr;
    COOR Up, Down, Left, Right;
    COOR Way;
    do
    {
        swap(Destination, Next);
        while (!Destination.empty())
        {
            Curr = Destination.front();
            Destination.pop();

            //4방향으로 뻗기
            Up = Down = Left = Right = Curr;

            Way.y = -1; Way.x = 0;
            Move(Up, Way, board);
            Way.y = 1;
            Move(Down, Way, board);
            Way.y = 0; Way.x = -1;
            Move(Left, Way, board);
            Way.x = 1;
            Move(Right, Way, board);

            if (History[Up.y][Up.x] == false)
            {
                Next.push(Up);
                History[Up.y][Up.x] = true;
            }
            if (History[Down.y][Down.x] == false)
            {
                Next.push(Down);
                History[Down.y][Down.x] = true;
            }
            if (History[Left.y][Left.x] == false)
            {
                Next.push(Left);
                History[Left.y][Left.x] = true;
            }
            if (History[Right.y][Right.x] == false)
            {
                Next.push(Right);
                History[Right.y][Right.x] = true;
            }
        }
        ++answer;
        if (true == History[Goal.y][Goal.x])
            return answer;
    } while (!Next.empty());

    return -1;
}