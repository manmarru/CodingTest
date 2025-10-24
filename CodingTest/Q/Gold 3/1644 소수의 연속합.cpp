#include "pch.h"
#include "Header.h"
#include <vector>
#define LIMIT 4000001

/*
vector<bool> �� ���ø� Ư��ȭ�ż� bool �� �ƴ϶� bit�� ����ȴ�.
�׷��� �ּ� ��� ���� �������� �ȵǰ� ������ �� ������.
vector<char>�� ���ų�, �ݵ�� �׷��� �ؾ� �Ѵٸ� �ٸ� ����� ã�ƺ� ��. (��?)
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