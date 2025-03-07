#include "pch.h"
#include "Header.h"
#include <string>
#include <list>

void Solve(ifstream* pLoadStream)
{
	int iSize;
	CIN >> iSize;
	string szCommand;
	int iDir{ 1 };
	int iInput;
	string szNums;
	list<int> listNums;
	string szResult;
	bool bError;
	for (int i = 0; i < iSize; i++)
	{
		bError = false;
		CIN >> szCommand >> iInput >> szNums;
		iDir = 1;

		//두자리 이상 숫자를 받을려니까 길어지는거같다.
		if (0 != iInput)
		{
			string szTemp;
			for (char c : szNums)
			{
				if ('[' == c)
					continue;
				if (']' == c)
				{
					listNums.push_back(stoi(szTemp));
					break;
				}
				if (c == ',')
				{
					listNums.push_back(stoi(szTemp));
					szTemp = "";
					continue;
				}
				szTemp += c;
			}
		}

		//명령 처리
		for (char Temp : szCommand)
		{
			if ('D' == Temp)
			{
				if (listNums.empty())
				{
					bError = true;
					break;
				}

				iDir == 1 ? listNums.pop_front() : listNums.pop_back();
			}
			else
				iDir *= -1;
		}
		if (bError)
		{
			cout << "error\n";
			listNums = list<int>();
			continue;
		}


		if (-1 == iDir)
			listNums.reverse();
		cout << '[';
		if (0 != listNums.size())
		{
			for (auto i = listNums.begin(); i != --listNums.end(); ++i)
			{
				cout << *i << ',';
			}
			cout << listNums.back() << ']' << '\n';
		}
		else
			cout << ']' << '\n';

		listNums = list<int>();
	}

}