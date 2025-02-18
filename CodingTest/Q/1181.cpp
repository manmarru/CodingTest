#include "pch.h"
#include "Header.h"
#include <list>
#include <string>
#include <algorithm>

void Solve(ifstream* pLoadStream)
{
	/*
	알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

	길이가 짧은 것부터
	길이가 같으면 사전 순으로
	단, 중복된 단어는 하나만 남기고 제거해야 한다.
	*/
	
	int iSize(0);
	string strInput;
	list<string> listInput;
	(*pLoadStream) >> iSize;

	for (size_t i = 0; i < iSize; i++)
	{
		(*pLoadStream) >> strInput;
		listInput.push_back(strInput);
	}
	
	//정렬
	listInput.sort([](string a, string b)
		{
			if (a.size() == b.size())// 사전순정렬
			{
				auto iterA = a.begin();
				auto iterB = b.begin();

				for (size_t i = 0; i < a.size(); i++)
				{
					if ((*iterA) == (*iterB))
					{
						iterA++;
						iterB++;
					}
					else
						return (*iterA) < (*iterB);
				}
			}
			return a.size() < b.size();
		});

	list<string>::iterator currentiter;
	//중복삭제
	for (auto iter = listInput.begin(); iter != listInput.end();)
	{
		do
		{
			currentiter = iter;
			++iter;
			if (listInput.end() == iter)
				break;
			if ((*currentiter) == (*iter))
			{
				currentiter = listInput.erase(currentiter);
			}
		} while (iter != listInput.end() && (*iter).size() == (*currentiter).size());
	}


	//반환
	for (auto Word : listInput)
		cout << Word << endl;
}