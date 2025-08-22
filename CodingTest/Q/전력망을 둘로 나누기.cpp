#include "pch.h"
#include "Header.h"

#include <vector>
#include <queue>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/86971
�� Ǭ�Ű��� �ϴ�.
�ƽ���� BFS ȣ���Ҷ����� History�� ���� ����� �κ�.
���� �� �� �ִ� ���̵� ����. bool�� �ƴ϶� char �̴ϱ�
History�� ���۷����� �Ѱܼ� �����ϵ�, �Ű������� ���� �ѱ�� ��� Ű�� �ٲٴ� ����
true false�� �ٲٴ°� �ƴ϶� ��� Ű�� �Ҵ��ϸ�, �̹� ȸ���� �湮�ߴ��� �� �� �ְڴ�. (���̵�� ����.)


�ٸ� ����� Ǯ�� ������ �ִµ� Ȯ���غ��� ����
*/
struct NODE
{
    vector<int> Link;
};

int BFS(int Start, int Cut, vector<NODE>& Graph)
{
    vector<char> History(Graph.size(), false); //�߶� ���� ��Ʈ��� �ΰ��� true�� �ϸ� �ڸ� ���� �� �̿��ϰڱ�
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
    //�ϳ��� �߶���ߵǳ�???
    //�ϳ��� �߶󺸰�, �ڸ��� ���� ��带 ��Ʈ�� �ؼ� Ž���غ����ҵ�?

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