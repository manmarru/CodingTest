#include "pch.h"
#include "Header.h"
#include <limits>
#include <list>

void Solve(ifstream* pLoadStream)
{
	//펠린드롬수 판별하기
	//대칭인 숫자 = true
	//아니면 false

	//입력 끝나면 0

	int iInput(0);
	list<int> listSingleNum;
	while (1)
	{
		(*pLoadStream) >> iInput;
		if (0 == iInput)
			return;
		if (9 >= iInput)
		{
			cout << "yes" << endl;
			continue;
		}


		while (iInput != 0)
		{
			listSingleNum.push_back(iInput % 10);
			iInput /= 10;
		}


		while (1 < listSingleNum.size())
		{
			if (listSingleNum.front() == listSingleNum.back())
			{
				listSingleNum.pop_back();
				listSingleNum.pop_front();
			}
			else
			{
				cout << "no" << endl;
				break;
			}
		}
		if (1 >= listSingleNum.size())
			cout << "yes" << endl;
		listSingleNum.clear();
	}


}