#include "pch.h"
#include "Header.h"

#include <vector>
#include <algorithm>

using namespace std;

/*
문제 https://school.programmers.co.kr/learn/courses/30/lessons/42892
*/

struct NODE
{
    NODE* Left = nullptr;
    NODE* Right = nullptr;
    int y; // y
    int x; // x
    int NodeNum;

    NODE(int _y, int _x, int _NodeNum) : y(_y), x(_x), NodeNum(_NodeNum)
    {
    }

    bool Push(int _y, int _x, int _NodeNum)
    {
        if (_x < x)
        {
            if (Left == nullptr)
            {
                Left = new NODE(_y, _x, _NodeNum);
                return true;
            }
            if (true == Left->Push(_y, _x, _NodeNum))
                return true;
        }
        else
        {
            if (Right == nullptr)
            {
                Right = new NODE(_y, _x, _NodeNum);
                return true;
            }
            if (false == Right->Push(_y, _x, _NodeNum))
                return true;
        }

        return false;
    }

    void PreOrder(vector<int>& _Out)
    {
        _Out.push_back(NodeNum);
        if (nullptr != Left)
            Left->PreOrder(_Out);
        if (nullptr != Right)
            Right->PreOrder(_Out);
    }
    void PostOrder(vector<int>& _Out)
    {
        if (nullptr != Left)
            Left->PostOrder(_Out);
        if (nullptr != Right)
            Right->PostOrder(_Out);
        _Out.push_back(NodeNum);
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    //완전 이진 트리가 아니라서 인덱싱으로 푸는건 불가능하다. (각 층의 첫 인덱스가 2^n이 아니다.)
    int MaxSize = nodeinfo.size();
    for (int i = 0; i < MaxSize; ++i)
    {
        nodeinfo[i].push_back(i + 1);
    }


    sort(nodeinfo.begin(), nodeinfo.end(), [](vector<int>& Temp, vector<int>& Src)
        {
            if (Temp[1] == Src[1])
            {
                return Temp[0] > Src[0];
            }
            return Temp[1] > Src[1];
        });

    NODE* Root = new NODE(nodeinfo[0][1], nodeinfo[0][0], nodeinfo[0][2]);


    for (int i = 1; i < MaxSize; ++i)
    {
        Root->Push(nodeinfo[i][1], nodeinfo[i][0], nodeinfo[i][2]);
    }

    vector<vector<int>> answer(2, vector<int>());
    Root->PreOrder(answer[0]);
    Root->PostOrder(answer[1]);

    return answer;
}