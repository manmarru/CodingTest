#include "pch.h"
#include "Header.h"
#include <vector>

struct BAG
{
	int Weight;
	int Value;
};

void Solve(ifstream* _pLoadStream)
{
	/*
	��ɿ� ���� �� �ִ� ���ǵ��� ��ġ�� �ִ��� ���

	set���� �ߺ��Ǵ� ����,��ġ�� �����ϸ鼭 Ǯ�� �ߴµ�
	�����Ҷ����� �����ϴ°� ���� ���ߴ�. ��������
	*/

	int Size;
	int MaxWeight;
	CIN >> Size >> MaxWeight;

	vector<int> DP(MaxWeight + 1, -1); // ���Դ� �ִ� ��ġ
	DP[0] = 0;
	vector<BAG> Entry;
	Entry.reserve(Size);
	BAG Input; // ����, ��ġ

	for (int i = 0; i < Size; ++i)
	{
		CIN >> Input.Weight >> Input.Value;
		Entry.push_back(Input);
	}
	/*
	���� ������ �ֱ� �������� ���Ժ� DP�� Ȯ���Ұ���
	*/

	vector<int> NewDP(MaxWeight + 1, 0);
	for (int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < MaxWeight; ++j)
		{
			if (DP[j] == -1)
				continue;

			if (j + Entry[i].Weight > MaxWeight)
				break;
			//�������� maxweight���� ������ newDP �ʿ����.
			NewDP[j + Entry[i].Weight] = max(DP[j + Entry[i].Weight], DP[j] + Entry[i].Value);
		}
		for (int j = 0; j <= MaxWeight; ++j)
		{
			DP[j] = NewDP[j] == 0 ? DP[j] : NewDP[j];
			NewDP[j] = 0;
		}
	}

	int Result(0);
	for (int i = 1; i <= MaxWeight; ++i)
	{
		Result = max(DP[i], Result);
	}
	
	cout << Result;
}