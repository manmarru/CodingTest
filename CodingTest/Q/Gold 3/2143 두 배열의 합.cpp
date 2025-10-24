#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

/*
�հ� ũ�⸦ ���ؼ� �Ӹ��� ������ �����̴� ����� ���� ���ҿ� ���� ó���� �� �Ѵ�.
������ ������ �̺�Ž���� ����ϴ� �� �����ε� �׳� upper_bound ������� �ߴ�.
���ͷ����ͳ����� ������ �ϸ� �� ������ �ε��� ���̰� ���´�.
*/


void Solve(ifstream* _pLoadStream)
{
	vector<int> A;
	vector<int> B;

	int Sum;
	int Objective;
	int InputSize[2];
	CIN >> Objective;
	CIN >> InputSize[0];
	A.resize(InputSize[0]);
	for (int i = 0; i < InputSize[0]; ++i)
	{
		CIN >> A[i];
	}
	CIN >> InputSize[1];
	B.resize(InputSize[1]);
	for (int i = 0; i < InputSize[1]; ++i)
	{
		CIN >> B[i];
	}

	vector<int> ASum;
	for (int aStart = 0; aStart < InputSize[0]; ++aStart)
	{
		Sum = 0;
		for (int aEnd = aStart; aEnd < InputSize[0]; aEnd++)
		{
			Sum += A[aEnd];
			ASum.push_back(Sum);
		}
		Sum -= A[aStart];
	}
	
	vector<int> BSum;
	for (int bStart = 0; bStart < InputSize[1]; ++bStart)
	{
		Sum = 0;
		for (int bEnd = bStart; bEnd < InputSize[1]; ++bEnd)
		{
			Sum += B[bEnd];
			BSum.push_back(Sum);
		}
		Sum -= B[bStart];
	}

	sort(BSum.begin(), BSum.end());
	long long int Result{ 0 };

	for (int a : ASum)
	{
		int Target = Objective - a;
		auto lower = lower_bound(BSum.begin(), BSum.end(), Target);
		auto upper = upper_bound(BSum.begin(), BSum.end(), Target);
		Result += upper - lower;
	}


	cout << Result;
}

/*
	for (int i : A)
		cout << i << ' ';
	cout << endl;
	for (int i : B)
		cout << i << ' ';
	*/