#include "pch.h"
#include "Header.h"

#include <string>
#include <stack>
#include <iostream>

/*
https://school.programmers.co.kr/learn/courses/30/lessons/60058

���� ��ȣ üũ�ϴµ� �� stack�� ����� �ʿ�� ���ݾ�?
��� int �ϳ��� ++ -- �ϸ鼭 ���߿� ������ ���͹������� Ȯ���ϱ⸸ �ص� ��
*/


//�������� = ��������
//�������� + ¦�� ���� = �ùٸ�

pair<string, string> Seperate(string Original)
{
    pair<string, string> result = { "", "" };
    int IndexU(-1);
    int CntLeft(0), CntRight(0);
    int Start(0);
    for (char c : Original)
    {
        ++IndexU;
        c == '(' ? ++CntLeft : ++CntRight;

        if (CntLeft == CntRight)
        {
            result.first = Original.substr(Start, IndexU - Start + 1);
            if (IndexU == Original.size())
                return result;
            Start = IndexU + 1;
            result.second = Original.substr(Start, Original.length());
            cout << result.first << ' ' << result.second << endl;
            return result;
        }
    }
    return result;
}

bool Check(string Input)
{
    stack<char> Check;
    for (char c : Input)
    {
        if (c == '(')
        {
            Check.push('(');
        }
        else if (c == ')')
        {
            if (Check.empty())
                return false;
            else if (Check.top() == '(')
                Check.pop();
            else
                Check.push(')');
        }
    }

    return Check.empty();
}

string Act(string p)
{
    string Result = "";

    if (p == "")
        return "";

    pair<string, string> Temp = Seperate(p);

    if (true == Check(Temp.first))
    {
        Result += Temp.first;
        if (Temp.second != "")
            Result += Act(Temp.second);
    }
    else
    {
        Result += "(";
        Result += Act(Temp.second);
        Result += ")";
        Temp.first.erase(0, 1);
        Temp.first.pop_back();
        for (int i = 0; i < Temp.first.size(); ++i)
        {
            Temp.first[i] = (Temp.first[i] == '(' ? ')' : '(');
        }
        Result += Temp.first;
    }
    cout << "Result : " << Result << endl;
    return Result;
}


//u v '(' v2 '(' v3 ')' u3 ')' u2


string solution(string p)
{
    return Act(p);
}