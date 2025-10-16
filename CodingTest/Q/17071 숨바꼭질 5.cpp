#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#include <array>


/*
https://www.acmicpc.net/problem/17071
������ ������ ���� �̸� �����ϴ� �����̰�
���� ������ �ִ°� �ȵǴϱ� �͸����� ģ�ٰ� �ϸ�
¦�� �Ͽ� ������ ���� ¦�� �Ͽ��� ���� Ȱ��ȭ �ȴٰ� �����ϸ� ��.
�׷��� History�� array<bool, 2> �ΰ���

https://www.acmicpc.net/source/99310568
�� �ڵ� ������ ����ϴ�.
initializer_list�� ���°� ���ɿ� ū ������ �ִ°͵� �ƴ϶� �����ϴٰ� ������
�׳� for ���� ���� ���������� ���� �迭 �ϳ� ����� ������
*/

#define MAPSIZE 500000
#define HALFSIZE 250000
enum NUM { EVEN = 0, ODD = 1, NONE };

vector<array<bool, 2>> History(MAPSIZE + 1, { false, false });

void Solve(ifstream* _pLoadStream)
{
    int Subin, Sist;

    CIN >> Subin >> Sist;
    if (Subin == Sist)
    {
        cout << 0;
        return;
    }
    queue<int> Destination;
    Destination.push(Subin);
    History[Subin][EVEN] = true;

    int Curr;
    int Turn = 0;
    while (!Destination.empty())
    {
        ++Turn;
        int Size = Destination.size();
        NUM Temp = (NUM)(Turn % 2);
        for (int i = 0; i < Size; ++i)
        {
            Curr = Destination.front();
            Destination.pop();

            if (Curr > 1 && History[Curr - 1][Temp] == false)
            {
                Destination.push(Curr - 1);
                History[Curr - 1][Temp] = true;
            }

            if (Curr < MAPSIZE && History[Curr + 1][Temp] == false)
            {
                Destination.push(Curr + 1);
                History[Curr + 1][Temp] = true;
            }
            
            if (Curr <= HALFSIZE && History[Curr * 2][Temp] == false)
            {
                Destination.push(Curr * 2);
                History[Curr * 2][Temp] = true;
            }
        }
        Sist += Turn;
        if (Sist > MAPSIZE)
        {
            cout << -1;
            return;
        }
        if (History[Sist][Temp] == true)
        {
            cout << Turn;
            return;
        }
    }
}