#include "pch.h"
#include "1436.h"

void Solve(ifstream* pLoadStream)
{
	/*
	666�� �� n��°�� ���� ���� ���
	���Ʈ ����
	*/
	int iInput(0);
	(*pLoadStream) >> iInput;

	string DevilNum;
	vector<int> vecNumbers;
	for (int i = 0; i < iInput; i++)
	{
		vecNumbers.push_back(i);
	}
	// 0�ڸ����� �����ؼ� 6���� ū ���ڸ� 666�� �����ʿ� �α�

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

	n������ ���ڸ� �����ϰ� �˸°� 666 ���̱�
	*/




}