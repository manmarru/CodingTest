#include "pch.h"
#include "Header.h"
#include <vector>
#include <stack>
#define CRITERIA 1000000007
/*
https://www.acmicpc.net/problem/13172

��Ŭ���� ȣ����: gcd(a, b) = gcd(a % b, b);

���Ҹ��� �� �𸣰ڴ�. �丣���� ������ ������ �̿��ؼ� ��ⷯ ������ ���ϰ�
�м��� �� �������� �ؽ��Ѵٴ°Ű���.
�ƴ� �ᱹ�� 1000000005���� ���ؾ� �ϳ�;

N��ü �ֻ��� M���� ������ �� ����� �ؽ̰� ����ϱ�.

=====================================================================================
�̰� �˰��ϱ� �Է°��� ���м��� �־����°Ŷ� ���� �ִ����� ���� �ʿ�� ������.
*/

struct FRACTION
{
	int Upper;
	int Downer;
	void Reduction() 
	{
		int gcd{ 0 };
		int N = Downer;
		int M = Upper; // ÷�� M�� �� ũ��.
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
		//���м��� �����
		Frac.Reduction();

		//�������� ���õ� ���� ����
		int Curr = CRITERIA - 2;

		stack<bool> Mult; // 2�� �������� true
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

		// ����
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