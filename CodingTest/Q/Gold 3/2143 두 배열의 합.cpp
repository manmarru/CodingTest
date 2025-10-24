#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>

/*
합과 크기를 비교해서 머리와 꼬리를 움직이는 방식은 음수 원소에 대한 처리를 못 한다.
정렬한 다음에 이분탐색을 사용하는 게 정석인데 그냥 upper_bound 써버리긴 했다.
이터레이터끼리의 뺄셈을 하면 그 간격의 인덱스 길이가 나온다.
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