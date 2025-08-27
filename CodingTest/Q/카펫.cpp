#include "pch.h"
#include "Header.h"

#include <vector>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/42842
5���� �̳�����
���� ������ ����ϰų� ������ �������� ���⵵ �ϴ���
���� ��Ƴ��� ���� Ǯ �� �ƴϸ� �״� ���ƺ����� ����.
*/

vector<int> solution(int brown, int yellow)
{
    brown -= 4;
    brown /= 2; // ������ ¦����

    vector<int> answer;
    for (int i = 1; i < brown; ++i)
    {
        if (i * (brown - i) == yellow)
        {
            answer.push_back(brown - i + 2); // ������ ū�� ���� ��
            answer.push_back(i + 2);
            break;
        }
    }

    return answer;
}