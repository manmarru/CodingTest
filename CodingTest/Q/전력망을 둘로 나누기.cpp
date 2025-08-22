#include "pch.h"
#include "Header.h"

#include <vector>
#include <queue>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/86971
잘 푼거같긴 하다.
아쉬운건 BFS 호출할때마다 History를 새로 만드는 부분.
재사용 할 수 있는 아이디어가 있음. bool이 아니라 char 이니까
History는 레퍼런스로 넘겨서 재사용하되, 매개변수로 같이 넘기는 토글 키로 바꾸는 거임
true false로 바꾸는게 아니라 토글 키를 할당하면, 이번 회차에 방문했는지 알 수 있겠다. (아이디어 좋네.)


다른 사람의 풀이 좋은거 있는데 확인해보고 지워
*/
struct NODE
{
    vector<int> Link;
};

int BFS(int Start, int Cut, vector<NODE>& Graph)
{
    vector<char> History(Graph.size(), false); //잘라서 생긴 루트노드 두개를 true로 하면 자른 선은 안 이용하겠군
    History[Cut] = true;
    History[Start] = true;
    int result = 0;

    queue<int> Destination;
    Destination.push(Start);
    while (!Destination.empty())
    {
        int Curr = Destination.front();
        Destination.pop();

        for (int i : Graph[Curr].Link)
        {
            if (History[i] == true)
                continue;
            History[i] = true;
            Destination.push(i);
            ++result;
        }
    }


    return result;
}

int solution(int n, vector<vector<int>> wires)
{
    //하나씩 잘라봐야되나???
    //하나씩 잘라보고, 자른곳 양쪽 노드를 루트로 해서 탐색해봐야할듯?

    vector<NODE> Graph(n + 1);
    for (auto Temp : wires)
    {
        Graph[Temp[0]].Link.push_back(Temp[1]);
        Graph[Temp[1]].Link.push_back(Temp[0]);
    }

    int answer = Graph.size();
    for (auto Temp : wires)
    {
        int first = BFS(Temp[0], Temp[1], Graph);
        int second = BFS(Temp[1], Temp[0], Graph);

        answer = min(answer, abs(first - second));
    }

    return answer;
}