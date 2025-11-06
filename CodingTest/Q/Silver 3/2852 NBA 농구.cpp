#include "pch.h"
#include "Header.h"
#include <string>
#include <format>

/*
https://www.acmicpc.net/problem/2852
그냥 무난하게 푼 것 같음, 가독성은 별로지만
*/

int TeamScore[2] = {0, 0};
int Goal(int Team)
{
    ++TeamScore[Team];

    if (TeamScore[0] > TeamScore[1])
        return 0;
    else if (TeamScore[1] > TeamScore[0])
        return 1;
    return 2;
}

//이기기 시작한 팀, 시간
void Solve(ifstream* _pLoadStream)
{
    int InputSize;
    CIN >> InputSize;

    int TeamTime[2][2] = { {0, 0} , {0, 0} };
    string Input[2];

    int Team;
    int WinningTeam;
    CIN >> Team >> Input[0];
    WinningTeam = Goal(--Team);

    for (int i = 1; i < InputSize; ++i)
    {
        CIN >> Team >> Input[1];
        if (WinningTeam != 2)
        {
			TeamTime[WinningTeam][0] += stoi(Input[1].substr(0, 2)) - stoi(Input[0].substr(0, 2));
			TeamTime[WinningTeam][1] += stoi(Input[1].substr(3, 2)) - stoi(Input[0].substr(3, 2));
        }

        WinningTeam = Goal(--Team);
        Input[0] = Input[1];
    }
    Input[1] = {"48:00"};
    if (WinningTeam != 2)
    {
		TeamTime[WinningTeam][0] += stoi(Input[1].substr(0, 2)) - stoi(Input[0].substr(0, 2));
		TeamTime[WinningTeam][1] += stoi(Input[1].substr(3, 2)) - stoi(Input[0].substr(3, 2));
	}
    
    for (int i = 0; i < 2; ++i)
    {
        while (TeamTime[i][1] < 0)
        {
            TeamTime[i][1] += 60;
            --TeamTime[i][0];
        }
        while (TeamTime[i][1] >= 60)
        {
            TeamTime[i][1] -= 60;
            ++TeamTime[i][0];
        }
    }

    printf("%02d:%02d\n", TeamTime[0][0], TeamTime[0][1]);
    printf("%02d:%02d\n", TeamTime[1][0], TeamTime[1][1]);
    return;
}