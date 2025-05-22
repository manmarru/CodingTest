#include "pch.h"
#include "Header.h"
#include <vector>
#include <stack>
#define CRITERIA 1000000007
/*
https://www.acmicpc.net/problem/13172

유클리드 호제법: gcd(a, b) = gcd(a % b, b);

뭔소린지 잘 모르겠다. 페르마의 마지막 정리를 이용해서 모듈러 역원을 구하고
분수를 그 역원으로 해싱한다는거같다.
아니 결국에 1000000005승을 구해야 하네;

N면체 주사위 M개를 던졌을 때 기댓값의 해싱값 출력하기.

=====================================================================================
이거 알고보니까 입력값이 기약분수로 주어지는거라서 내가 최대공약수 구할 필요는 없었다.
*/

struct FRACTION
{
	int Upper;
	int Downer;
	void Reduction() 
	{
		int gcd{ 0 };
		int N = Downer;
		int M = Upper; // 첨엔 M이 더 크다.
		while (true)
		{
			M %= N;
			if (M % N == 0)
			{
				gcd = N;
				break;
			}

			N %= M;
			if (N % M == 0)
			{
				gcd = M;
				break;
			}
		}
		Upper /= gcd;
		Downer /= gcd;
	}
};

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	unsigned long long int Temp{ 0 };
	unsigned long long int Result{ 0 };

	FRACTION Frac;
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Frac.Downer >> Frac.Upper;
		//기약분수로 만들기
		Frac.Reduction();

		//문제에서 제시된 연산 진행
		int Curr = CRITERIA - 2;

		stack<bool> Mult; // 2로 나눠지면 true
		while (Curr != 1)
		{
			if (Curr % 2 == 0)
			{
				Mult.push(true);
				Curr /= 2;
			}
			else
			{
				Mult.push(false);
				Curr -= 1;
			}
		}

		// 제곱
		Temp = Frac.Downer;
		while (!Mult.empty())
		{
			if (Mult.top() == false)
				Temp *= Frac.Downer;
			else
				Temp *= Temp;
			Mult.pop();
			Temp %= CRITERIA;
		}
		Temp *= Frac.Upper;
		Temp %= CRITERIA;
		
		Result += Temp;
		Result %= CRITERIA;
	}

	cout << Result;
}