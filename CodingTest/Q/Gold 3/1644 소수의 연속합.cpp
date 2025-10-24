#include "pch.h"
#include "Header.h"
#include <vector>
#define LIMIT 4000001

/*
vector<bool> 은 템플릿 특수화돼서 bool 이 아니라 bit로 저장된다.
그래서 주소 기반 랜덤 엑세스가 안되고 접근이 더 느리다.
vector<char>을 쓰거나, 반드시 그렇게 해야 한다면 다른 방식을 찾아볼 것. (덱?)
*/
void Solve(ifstream* _pLoadStream)
{
	vector<char> Eratos(LIMIT, 0);
	vector<int> Primes;
	unsigned int Curr;
	for (unsigned int i = 2; i < LIMIT; ++i)
	{
		if (Eratos[i])
			continue;
		Primes.push_back(i);
		Curr = i * i;
		while (Curr < LIMIT)
		{
			Eratos[Curr] = true;
			Curr += i;
		}
	}

	int Input;
	CIN >> Input;

	int CurrSum = 2;
	int Result = 0;
	auto sEter = Primes.begin();
	auto eEter = Primes.begin();

	while (1)
	{
		if (CurrSum == Input)
		{
			++Result;
		}

		if (CurrSum <= Input)
		{
			++eEter;
			if (eEter == Primes.end())
				break;
			CurrSum += *eEter;
		}
		else
		{
			if (sEter == eEter)
				break;
			CurrSum -= *sEter;
			++sEter;
		}
	}

	cout << Result;
}