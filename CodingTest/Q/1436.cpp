#include "pch.h"
#include "1436.h"

void Solve(ifstream* pLoadStream)
{
	/*
	666이 들어간 n번째로 작은 숫자 출력
	브루트 포스
	*/
	int iInput(0);
	(*pLoadStream) >> iInput;

	string DevilNum;
	vector<int> vecNumbers;
	for (int i = 0; i < iInput; i++)
	{
		vecNumbers.push_back(i);
	}
	// 0자리부터 시작해서 6보다 큰 숫자면 666의 오른쪽에 두기

	/*
	1666
	6666
	6667
	6669
	7666
	1666
	2666
	3666
	4666
	5666
	6666
	6667
	6668
	6669
	10666
	11666
	12666
	13666
	14666
	15666
	16666
	16667
	16668
	16669
	20666
	66699

	n까지의 숫자를 나열하고 알맞게 666 붙이기
	*/




}