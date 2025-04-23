#include "pch.h"
#include "Header.h"
#include <list>
#include <string>

void Solve(ifstream* _pLoadStream)
{
	/*
	괄호 제거하는것처럼 단어에서 폭탄 단어를 지우고 그 결과에서 또 폭탄 단어를 지우고 반복하는거
	단어가 남아있지 않다면 FRULA 출력

	스택은 순회가 안되니깐 list를 썼다.
	스택 쓸거면 하나씩 꺼내고 다시 넣고 해야되니까 좀 피곤해보였다.

	문자를 하나씩 순회하면서 리스트에 넣고, 넣은 값이 폭탄의 마지막 글자면
	넣은 값을 거꾸로 순회함
	*/
	string Letter;
	string Boom;
	CIN >> Letter >> Boom;
	char Last = Boom.back();
	int Cnt(0);

	string Curr;
	for (char Temp : Letter)
	{
		Curr.push_back(Temp);
		if (Temp == Last)
		{
			auto iter = --Curr.end();
			do
			{
				if (*iter == Boom[(int)Boom.size() - Cnt - 1])
				{
					++Cnt;
					if (Cnt == (int)Boom.size())
					{
						for (int i = 0; i < Cnt; ++i)
							Curr.pop_back();
						Cnt = 0;
						break;
					}
				}
				else
				{
					Cnt = 0;
					break;
				}
			} while (iter-- != Curr.begin());
		}
		else
			Cnt = 0;
	}
	
	if (Curr.empty())
		cout << "FRULA";
	else
	{
		for (char& Temp : Curr)
			cout << Temp;
	}
}